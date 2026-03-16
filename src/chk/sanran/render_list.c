#include <chk/sanran/render_list.h>

#include <chk/core/log.h>

#include <stdlib.h>

CHK_SANRAN_LOCAL static bool                g_render_list_initialized   = false;
CHK_SANRAN_LOCAL static chk_render_list_t** g_render_list_push_queue    = NULL;
CHK_SANRAN_LOCAL static size_t              g_render_list_push_count    = 0;
CHK_SANRAN_LOCAL static size_t              g_render_list_push_capacity = 0;
CHK_SANRAN_LOCAL static size_t              g_render_list_count         = 0;

CHK_SANRAN_LOCAL bool _chk_render_list_push(void);
CHK_SANRAN_LOCAL void _chk_render_list_pop(void);

CHK_SANRAN_LOCAL bool _chk_render_list_begin(chk_render_list_t* render_list);
CHK_SANRAN_LOCAL void _chk_render_list_end(chk_render_list_t* render_list);

typedef struct chk_render_list_impl {
  void* _stub;
} chk_render_list_impl_t;

CHK_SANRAN_API chk_render_list_config_t chk_render_list_config_default(void) {
  chk_render_list_config_t config = {0};

  config.cmd_buffer_size = sizeof(chk_render_cmd_t) * 1024 * 4;

  return config;
}

CHK_SANRAN_API chk_render_list_t* chk_render_list_create(chk_render_list_config_t* config) {
  chk_render_list_t* result = NULL;

  if (_chk_render_list_push()) {
    if (config) {
      chk_render_list_t* render_list = calloc(1, sizeof(chk_render_list_t));
      if (render_list) {
        void* cmd_buffer = malloc(config->cmd_buffer_size);
        if (cmd_buffer) {
          render_list->cmd_buffer      = cmd_buffer;
          render_list->cmd_buffer_size = config->cmd_buffer_size;

          result = render_list;

          chk_log_info("created render list");
        } else {
          chk_log_error("Failed to allocate render command buffer");
        }
      } else {
        chk_log_error("Failed to allocate render list");
      }

      if (!result) { chk_render_list_destroy(render_list); }
    } else {
      chk_log_error("config is NULL");
    }
  }

  return result;
}

CHK_SANRAN_API void chk_render_list_destroy(chk_render_list_t* render_list) {
  if (render_list) {
    chk_render_list_impl_t* impl = render_list->impl;
    if (impl) {
      //

      free(impl);
    }

    if (render_list->cmd_buffer) { free(render_list->cmd_buffer); }

    free(render_list);

    chk_log_info("destroyed render list");
  } else {
    chk_log_error("render_list is NULL");
  }

  _chk_render_list_pop();
}

CHK_SANRAN_API bool chk_render_list_begin(chk_render_list_t* render_list) {
  bool result = false;

  if (render_list) {
    // TODO(chk): Implement render list begin logic

    result = true;
  } else {
    chk_log_error("render_list is NULL");
  }

  return result;
}

CHK_SANRAN_API void chk_render_list_end(chk_render_list_t* render_list) {
  if (render_list) {
    // TODO(chk): Implement render list end logic

  } else {
    chk_log_error("render_list is NULL");
  }
}

// Render List Push/Pop

CHK_SANRAN_LOCAL bool _chk_render_list_push(void) {
  if (g_render_list_count == 0) {
    g_render_list_push_capacity = CHK_SANRAN_RENDER_LIST_PUSH_LIMIT;
    g_render_list_push_queue    = calloc(g_render_list_push_capacity, sizeof(*g_render_list_push_queue));
    if (g_render_list_push_queue) {
      g_render_list_initialized = true;
    } else {
      chk_log_error("failed to initialize render list push queue");
    }
  }
  if (g_render_list_initialized) { ++g_render_list_count; }
  return g_render_list_initialized;
}

CHK_SANRAN_LOCAL void _chk_render_list_pop(void) {
  if (g_render_list_count == 1) {
    if (g_render_list_push_queue) { free(g_render_list_push_queue); }

    g_render_list_push_queue    = NULL;
    g_render_list_push_capacity = 0;
    g_render_list_push_count    = 0;

    g_render_list_initialized = false;
  }
  --g_render_list_count;
}

CHK_SANRAN_LOCAL bool _chk_render_list_begin(chk_render_list_t* render_list) {
  bool result = false;

  if (g_render_list_initialized) {

    if (render_list) {
      // TODO(chk): Implement render list begin logic

      result = true;
    } else {
      chk_log_error("render_list is NULL");
    }
  } else {
    chk_log_error("render list push queue is not initialized");
  }

  return false;
}

CHK_SANRAN_LOCAL void _chk_render_list_end(chk_render_list_t* render_list) {
  if (g_render_list_initialized) {
    if (render_list) {
      // TODO(chk): Implement render list end logic

    } else {
      chk_log_error("render_list is NULL");
    }
  } else {
    chk_log_error("render list push queue is not initialized");
  }
}
