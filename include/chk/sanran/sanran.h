#pragma once

#include <chk/sanran/export.h>

#include <chk/sanran/render_list.h>
#include <chk/sanran/window.h>

#include <chk/core/core.h>

typedef struct chk_sanran {
  chk_window_t*      window;
  chk_render_list_t* render_list;
} chk_sanran_t;

typedef struct chk_sanran_config {
  chk_window_config_t      window;
  chk_render_list_config_t render_list;
} chk_sanran_config_t;

CHK_SANRAN_API chk_sanran_config_t chk_sanran_config_default(void);

CHK_SANRAN_API chk_sanran_t* chk_sanran_create(chk_sanran_config_t* config);
CHK_SANRAN_API void          chk_sanran_destroy(chk_sanran_t* sanran);

CHK_SANRAN_API void chk_sanran_run(chk_sanran_t* sanran);
