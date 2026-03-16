#pragma once

#include <chk/sanran/export.h>

#include <chk/core/core.h>

#include <chk/sanran/render_cmd.h>

#define CHK_SANRAN_RENDER_LIST_PUSH_LIMIT 16

typedef struct chk_render_list_impl chk_render_list_impl_t;
typedef struct chk_render_list      chk_render_list_t;

typedef struct chk_render_list {
  chk_render_list_impl_t* impl;

  void*  cmd_buffer;
  size_t cmd_buffer_size;
  size_t cmd_buffer_used;
  size_t cmd_buffer_count;
} chk_render_list_t;

typedef struct chk_render_list_config {
  size_t cmd_buffer_size;
} chk_render_list_config_t;

CHK_SANRAN_API chk_render_list_config_t chk_render_list_config_default(void);

CHK_SANRAN_API chk_render_list_t* chk_render_list_create(chk_render_list_config_t* config);
CHK_SANRAN_API void               chk_render_list_destroy(chk_render_list_t* render_list);

CHK_SANRAN_API bool chk_render_list_begin(chk_render_list_t* render_list);
CHK_SANRAN_API void chk_render_list_end(chk_render_list_t* render_list);

CHK_SANRAN_API bool chk_render_list_push_cmd(chk_render_list_t* render_list, chk_render_cmd_t* cmd);

CHK_SANRAN_API bool chk_render_clear(chk_render_list_t* render_list, float r, float g, float b, float a);
CHK_SANRAN_API bool chk_render_point(chk_render_list_t* render_list, double x, double y, float r, float g, float b,
                                     float a);
