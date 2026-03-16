#include <chk/sanran/sanran.h>

#include <chk/core/log.h>

#include <stdlib.h>

CHK_SANRAN_API chk_sanran_config_t chk_sanran_config_default(void) {
  chk_sanran_config_t config = {0};

  config.window      = chk_window_config_default();
  config.render_list = chk_render_list_config_default();

  return config;
}

CHK_SANRAN_API chk_sanran_t* chk_sanran_create(chk_sanran_config_t* config) {
  chk_sanran_t* result = NULL;

  if (config) {
    chk_sanran_t* sanran = calloc(1, sizeof(*sanran));
    if (sanran) {
      sanran->window = chk_window_create(&config->window);
      if (sanran->window) {
        sanran->render_list = chk_render_list_create(&config->render_list);
        if (sanran->render_list) {
          result = sanran;

          chk_log_info("created sanran");
        }
      }
    } else {
      chk_log_error("failed to allocate sanran");
    }

    if (!result) { chk_sanran_destroy(sanran); }
  } else {
    chk_log_error("config is NULL");
  }

  return result;
}

CHK_SANRAN_API void chk_sanran_destroy(chk_sanran_t* sanran) {
  if (sanran) {
    if (sanran->render_list) { chk_render_list_destroy(sanran->render_list); }
    if (sanran->window) { chk_window_destroy(sanran->window); }

    free(sanran);

    chk_log_info("destroyed sanran");
  } else {
    chk_log_error("sanran is NULL");
  }
}

CHK_SANRAN_API void chk_sanran_run(chk_sanran_t* sanran) {
  if (sanran) {
    chk_window_run(sanran->window);
  } else {
    chk_log_error("sanran is NULL");
  }
}
