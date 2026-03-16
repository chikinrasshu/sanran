#include <chk/sanran/sanran.h>

#include <chk/core/log.h>

int main(int argc, char** argv) {
  (void)argc;
  (void)argv;

  chk_sanran_config_t config = chk_sanran_config_default();
  config.window.title        = "chkLauncher";

  chk_sanran_t* sanran = chk_sanran_create(&config);
  if (sanran) {
    chk_sanran_run(sanran);

    chk_sanran_destroy(sanran);
    sanran = NULL;
  }

  return 0;
}