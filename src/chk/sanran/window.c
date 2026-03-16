#include <chk/sanran/window.h>

#include <chk/core/log.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include <stdlib.h>

CHK_SANRAN_LOCAL static bool    g_window_initialized = false;
CHK_SANRAN_LOCAL static int64_t g_window_count       = 0;

CHK_SANRAN_LOCAL bool _chk_window_push(void);
CHK_SANRAN_LOCAL void _chk_window_pop(void);

CHK_SANRAN_LOCAL void _chk_window_on_error(int code, const char* msg);
CHK_SANRAN_LOCAL void _chk_window_on_close(GLFWwindow* handle);
CHK_SANRAN_LOCAL void _chk_window_on_frame(GLFWwindow* handle);
CHK_SANRAN_LOCAL void _chk_window_on_move(GLFWwindow* handle, int x, int y);
CHK_SANRAN_LOCAL void _chk_window_on_size(GLFWwindow* handle, int w, int h);
CHK_SANRAN_LOCAL void _chk_window_on_fb_size(GLFWwindow* handle, int w, int h);
CHK_SANRAN_LOCAL void _chk_window_on_scale(GLFWwindow* handle, float sx, float sy);
CHK_SANRAN_LOCAL void _chk_window_on_focus(GLFWwindow* handle, int focused);
CHK_SANRAN_LOCAL void _chk_window_on_hover(GLFWwindow* handle, int hovered);
CHK_SANRAN_LOCAL void _chk_window_on_min(GLFWwindow* handle, int minimized);
CHK_SANRAN_LOCAL void _chk_window_on_max(GLFWwindow* handle, int maximized);

typedef struct chk_window_impl {
  GLFWwindow* handle;
} chk_window_impl_t;

CHK_SANRAN_API chk_window_config_t chk_window_config_default(void) {
  chk_window_config_t config = {0};

  config.title = "chkSanran";
  config.size  = chk_v2_make(800, 600);

  return config;
}

CHK_SANRAN_API chk_window_t* chk_window_create(chk_window_config_t* config) {
  chk_window_t* result = NULL;

  if (_chk_window_push()) {
    chk_window_t* window = calloc(1, sizeof(*window));
    if (window) {
      chk_window_impl_t* impl = calloc(1, sizeof(*impl));
      if (impl) {
        window->impl = impl;

        glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

        glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
        glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_FALSE);

        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

        int win_w = (int)config->size.x;
        int win_h = (int)config->size.y;

        GLFWwindow* handle = glfwCreateWindow(win_w, win_h, config->title, NULL, NULL);
        if (handle) {
          impl->handle = handle;

          glfwMakeContextCurrent(handle);

          // Initialize OpenGL
          int gl_version = gladLoadGL((GLADloadfunc)glfwGetProcAddress);
          if (gl_version) {
            glfwSetWindowUserPointer(handle, window);

            window->on        = config->on;
            window->user_data = config->user_data;

            // Get default values
            int win_x, win_y, win_w, win_h, fb_w, fb_h;
            glfwGetWindowPos(handle, &win_x, &win_y);
            glfwGetWindowSize(handle, &win_w, &win_h);
            glfwGetFramebufferSize(handle, &fb_w, &fb_h);

            float win_sx, win_sy;
            glfwGetWindowContentScale(handle, &win_sx, &win_sy);

            window->data.pos     = chk_v2_make((double)win_x, (double)win_y);
            window->data.size    = chk_v2_make((double)win_w, (double)win_h);
            window->data.fb_size = chk_v2_make((double)fb_w, (double)fb_h);
            window->data.scale   = (double)win_sx;

            glViewport(0, 0, fb_w, fb_h);

            if (window->on.move) { window->on.move(window, window->data.pos, window->user_data); }
            if (window->on.size) { window->on.size(window, window->data.size, window->user_data); }
            if (window->on.fb_size) { window->on.fb_size(window, window->data.fb_size, window->user_data); }

            // Set window callbacks
            glfwSetWindowCloseCallback(handle, _chk_window_on_close);
            glfwSetWindowRefreshCallback(handle, _chk_window_on_frame);
            glfwSetWindowPosCallback(handle, _chk_window_on_move);
            glfwSetWindowSizeCallback(handle, _chk_window_on_size);
            glfwSetFramebufferSizeCallback(handle, _chk_window_on_fb_size);
            glfwSetWindowContentScaleCallback(handle, _chk_window_on_scale);
            glfwSetWindowFocusCallback(handle, _chk_window_on_focus);
            glfwSetCursorEnterCallback(handle, _chk_window_on_hover);
            glfwSetWindowIconifyCallback(handle, _chk_window_on_min);
            glfwSetWindowMaximizeCallback(handle, _chk_window_on_max);

            window->is.open = true;

            chk_log_info("created window");

            result = window;
          } else {
            chk_log_error("failed to initialize OpenGL");
          }
        } else {
          chk_log_error("failed to create window");
        }
      } else {
        chk_log_error("failed to allocate window->impl");
      }
    } else {
      chk_log_error("failed to allocate window");
    }

    if (!result) { chk_window_destroy(window); }
  }

  return result;
}

CHK_SANRAN_API void chk_window_destroy(chk_window_t* window) {
  if (window) {
    chk_window_impl_t* impl = window->impl;

    if (impl) {
      if (impl->handle) { glfwDestroyWindow(impl->handle); }

      free(impl);
    }

    free(window);

    chk_log_info("destroyed window");
  } else {
    chk_log_error("window is NULL");
  }

  _chk_window_pop();
}

CHK_SANRAN_API void chk_window_step(chk_window_t* window, bool poll_events) {
  if (poll_events) { glfwPollEvents(); }

  // Create changed flags
  window->changed.pos = window->data.pos.x != window->old_data.pos.x || window->data.pos.y != window->old_data.pos.y;
  window->changed.size =
      window->data.size.x != window->old_data.size.x || window->data.size.y != window->old_data.size.y;
  window->changed.fb_size =
      window->data.fb_size.x != window->old_data.fb_size.x || window->data.fb_size.y != window->old_data.fb_size.y;
  window->changed.open  = window->is.open != window->was.open;
  window->changed.focus = window->is.focused != window->was.focused;
  window->changed.hover = window->is.hovered != window->was.hovered;
  window->changed.minmax =
      window->is.minimized != window->was.minimized || window->is.maximized != window->was.maximized;
  window->changed.fullscreen = window->is.fullscreen != window->was.fullscreen;

  // Update timer
  window->timer.last_time  = window->timer.cur_time;
  window->timer.cur_time   = glfwGetTime();
  window->timer.delta_time = window->timer.cur_time - window->timer.last_time;

  // Update FPS
  double fps        = 1.0 / window->timer.delta_time;
  window->timer.fps = fps;

  // Run the frame
  glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (window->on.frame) { window->on.frame(window, window->user_data); }

  glfwSwapBuffers(window->impl->handle);

  // Update FPS history and average
  window->timer.fps_history[window->timer.fps_history_index] = fps;
  window->timer.fps_history_index                            = (window->timer.fps_history_index + 1) %
                                    (sizeof(window->timer.fps_history) / sizeof(window->timer.fps_history[0]));
  if (window->timer.fps_history_count < sizeof(window->timer.fps_history) / sizeof(window->timer.fps_history[0])) {
    ++window->timer.fps_history_count;
  }
  double fps_sum = 0.0;
  for (size_t i = 0; i < window->timer.fps_history_count; ++i) { fps_sum += window->timer.fps_history[i]; }
  window->timer.fps_avg = fps_sum / window->timer.fps_history_count;

  // Update old data
  window->old_data = window->data;
  window->was      = window->is;
}

CHK_SANRAN_API void chk_window_run(chk_window_t* window) {
  chk_window_impl_t* impl = window->impl;

  if (window->is.open) {
    glfwShowWindow(impl->handle);
    while (window->is.open) { chk_window_step(window, true); }
  }
}

CHK_SANRAN_LOCAL void _chk_window_on_error(int code, const char* msg) {
  static const char* sender = "GLFW";
  chk_log_error_by(sender, "%d: %s", code, msg);
}

CHK_SANRAN_LOCAL void _chk_window_on_close(GLFWwindow* handle) {
  chk_window_t* window = glfwGetWindowUserPointer(handle);
  if (window) {
    chk_window_impl_t* impl = window->impl;
    if (impl) {
      window->is.open = false;
      if (window->on.close) { window->on.close(window, window->user_data); }
    } else {
      chk_log_error("window->impl is NULL");
    }
  } else {
    chk_log_error("window is NULL");
  }
}

CHK_SANRAN_LOCAL void _chk_window_on_frame(GLFWwindow* handle) {
  chk_window_t* window = glfwGetWindowUserPointer(handle);
  if (window) {
    chk_window_impl_t* impl = window->impl;
    if (impl) {
      chk_window_step(window, false);
    } else {
      chk_log_error("window->impl is NULL");
    }
  } else {
    chk_log_error("window is NULL");
  }
}

CHK_SANRAN_LOCAL void _chk_window_on_move(GLFWwindow* handle, int x, int y) {
  chk_window_t* window = glfwGetWindowUserPointer(handle);
  if (window) {
    chk_window_impl_t* impl = window->impl;
    if (impl) {
      window->data.pos.x = (double)x;
      window->data.pos.y = (double)y;

      if (window->on.move) { window->on.move(window, window->data.pos, window->user_data); }
    } else {
      chk_log_error("window->impl is NULL");
    }
  } else {
    chk_log_error("window is NULL");
  }
}

CHK_SANRAN_LOCAL void _chk_window_on_size(GLFWwindow* handle, int w, int h) {
  chk_window_t* window = glfwGetWindowUserPointer(handle);
  if (window) {
    chk_window_impl_t* impl = window->impl;
    if (impl) {
      window->data.size.x = (double)w;
      window->data.size.y = (double)h;

      if (window->on.size) { window->on.size(window, window->data.size, window->user_data); }
    } else {
      chk_log_error("window->impl is NULL");
    }
  } else {
    chk_log_error("window is NULL");
  }
}

CHK_SANRAN_LOCAL void _chk_window_on_fb_size(GLFWwindow* handle, int w, int h) {
  chk_window_t* window = glfwGetWindowUserPointer(handle);
  if (window) {
    chk_window_impl_t* impl = window->impl;
    if (impl) {
      window->data.fb_size.x = (double)w;
      window->data.fb_size.y = (double)h;

      glViewport(0, 0, w, h);

      if (window->on.fb_size) { window->on.fb_size(window, window->data.fb_size, window->user_data); }
    } else {
      chk_log_error("window->impl is NULL");
    }
  } else {
    chk_log_error("window is NULL");
  }
}

CHK_SANRAN_LOCAL void _chk_window_on_scale(GLFWwindow* handle, float sx, float sy) {
  chk_window_t* window = glfwGetWindowUserPointer(handle);
  if (window) {
    chk_window_impl_t* impl = window->impl;
    if (impl) {
      window->data.scale = (double)sx;
      chk_log_info("window scale: %.2f", window->data.scale);

      if (window->on.scale) { window->on.scale(window, window->data.scale, window->user_data); }
    } else {
      chk_log_error("window->impl is NULL");
    }
  } else {
    chk_log_error("window is NULL");
  }
}

CHK_SANRAN_LOCAL void _chk_window_on_focus(GLFWwindow* handle, int focused) {
  chk_window_t* window = glfwGetWindowUserPointer(handle);
  if (window) {
    chk_window_impl_t* impl = window->impl;
    if (impl) {
      window->is.focused = (bool)focused;
      if (window->on.focus) { window->on.focus(window, window->is.focused, window->user_data); }
    } else {
      chk_log_error("window->impl is NULL");
    }
  } else {
    chk_log_error("window is NULL");
  }
}

CHK_SANRAN_LOCAL void _chk_window_on_hover(GLFWwindow* handle, int hovered) {
  chk_window_t* window = glfwGetWindowUserPointer(handle);
  if (window) {
    chk_window_impl_t* impl = window->impl;
    if (impl) {
      window->is.hovered = (bool)hovered;
      if (window->on.hover) { window->on.hover(window, window->is.hovered, window->user_data); }
    } else {
      chk_log_error("window->impl is NULL");
    }
  } else {
    chk_log_error("window is NULL");
  }
}

CHK_SANRAN_LOCAL void _chk_window_on_min(GLFWwindow* handle, int minimized) {
  chk_window_t* window = glfwGetWindowUserPointer(handle);
  if (window) {
    chk_window_impl_t* impl = window->impl;
    if (impl) {
      window->is.minimized = (bool)minimized;
      if (window->on.minmax) {
        window->on.minmax(window, window->is.minimized, window->is.maximized, window->user_data);
      }
    } else {
      chk_log_error("window->impl is NULL");
    }
  } else {
    chk_log_error("window is NULL");
  }
}

CHK_SANRAN_LOCAL void _chk_window_on_max(GLFWwindow* handle, int maximized) {
  chk_window_t* window = glfwGetWindowUserPointer(handle);
  if (window) {
    chk_window_impl_t* impl = window->impl;
    if (impl) {
      window->is.maximized = (bool)maximized;
      if (window->on.minmax) {
        window->on.minmax(window, window->is.minimized, window->is.maximized, window->user_data);
      }
    } else {
      chk_log_error("window->impl is NULL");
    }
  } else {
    chk_log_error("window is NULL");
  }
}

// Window Push/Pop

CHK_SANRAN_LOCAL bool _chk_window_push(void) {
  if (g_window_count == 0) {
    glfwSetErrorCallback(_chk_window_on_error);
    g_window_initialized = glfwInit();
    if (!g_window_initialized) { chk_log_error("failed to initialize window backend"); }
  }
  if (g_window_initialized) { g_window_count++; }
  return g_window_initialized;
}

CHK_SANRAN_LOCAL void _chk_window_pop(void) {
  if (g_window_count == 1) {
    glfwTerminate();

    g_window_count = 0;

    g_window_initialized = false;
  }
  --g_window_count;
}
