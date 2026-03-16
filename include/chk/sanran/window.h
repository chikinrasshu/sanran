#pragma once

#include <chk/sanran/export.h>

#include <chk/core/core.h>
#include <chk/core/vec.h>

typedef struct chk_window_impl chk_window_impl_t;
typedef struct chk_window      chk_window_t;

typedef void (*chk_window_on_close_t)(chk_window_t* window, void* user_data);
typedef void (*chk_window_on_frame_t)(chk_window_t* window, void* user_data);
typedef void (*chk_window_on_move_t)(chk_window_t* window, chk_v2_t pos, void* user_data);
typedef void (*chk_window_on_size_t)(chk_window_t* window, chk_v2_t size, void* user_data);
typedef void (*chk_window_on_fb_size_t)(chk_window_t* window, chk_v2_t fb_size, void* user_data);
typedef void (*chk_window_on_scale_t)(chk_window_t* window, double scale, void* user_data);
typedef void (*chk_window_on_focus_t)(chk_window_t* window, bool is_focused, void* user_data);
typedef void (*chk_window_on_hover_t)(chk_window_t* window, bool is_hovered, void* user_data);
typedef void (*chk_window_on_minmax_t)(chk_window_t* window, bool is_min, bool is_max, void* user_data);
typedef void (*chk_window_on_fullscreen_t)(chk_window_t* window, bool is_fullscreen, void* user_data);

typedef struct chk_window_state {
  bool open;
  bool focused;
  bool hovered;
  bool minimized;
  bool maximized;
  bool fullscreen;
} chk_window_state_t;

typedef struct chk_window_changed {
  bool open;
  bool focus;
  bool hover;
  bool minmax;
  bool fullscreen;

  bool pos;
  bool size;
  bool fb_size;
  bool scale;
} chk_window_changed_t;

typedef struct chk_window_data {
  chk_v2_t pos;
  chk_v2_t size;
  chk_v2_t fb_size;

  double scale;
} chk_window_data_t;

typedef struct chk_window_callbacks {
  chk_window_on_close_t      close;
  chk_window_on_frame_t      frame;
  chk_window_on_move_t       move;
  chk_window_on_size_t       size;
  chk_window_on_fb_size_t    fb_size;
  chk_window_on_scale_t      scale;
  chk_window_on_focus_t      focus;
  chk_window_on_hover_t      hover;
  chk_window_on_minmax_t     minmax;
  chk_window_on_fullscreen_t fullscreen;
} chk_window_callbacks_t;

typedef struct chk_window_timer {
  double cur_time;
  double last_time;
  double delta_time;

  double fps;
  double fps_avg;

  double fps_history[32];
  size_t fps_history_count;
  size_t fps_history_index;
} chk_window_timer_t;

typedef struct chk_window {
  chk_window_impl_t* impl;

  chk_window_state_t     is, was;
  chk_window_data_t      data, old_data;
  chk_window_changed_t   changed;
  chk_window_callbacks_t on;
  chk_window_timer_t     timer;

  void* user_data;
} chk_window_t;

typedef struct chk_window_config {
  const char* title;

  chk_v2_t size;
  void*    user_data;

  chk_window_callbacks_t on;
} chk_window_config_t;

CHK_SANRAN_API chk_window_config_t chk_window_config_default(void);

CHK_SANRAN_API chk_window_t* chk_window_create(chk_window_config_t* config);
CHK_SANRAN_API void          chk_window_destroy(chk_window_t* window);

CHK_SANRAN_API void chk_window_run(chk_window_t* window);
