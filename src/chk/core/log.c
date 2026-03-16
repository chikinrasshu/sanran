#include <chk/core/log.h>

#include <stdio.h>

CHK_CORE_LOCAL static chk_log_fn_t  g_log_fn        = NULL;
CHK_CORE_LOCAL static chk_log_sev_t g_log_sev       = CHK_LOG_SEV_INFO;
CHK_CORE_LOCAL static void*         g_log_user_data = NULL;

CHK_CORE_LOCAL void _chk_log_stub(chk_log_sev_t sev, const char* sender, const char* msg, const char* f, int ln,
                                  const char* fn);

CHK_CORE_API const char* chk_log_sev_to_str(chk_log_sev_t sev) {
  const char* name = "UNK";
  switch (sev) {
    case CHK_LOG_SEV_NONE:
    case CHK_LOG_SEV_COUNT: break;

    case CHK_LOG_SEV_TRACE: name = "TRC"; break;
    case CHK_LOG_SEV_DEBUG: name = "DBG"; break;
    case CHK_LOG_SEV_INFO:  name = "INF"; break;
    case CHK_LOG_SEV_WARN:  name = "WRN"; break;
    case CHK_LOG_SEV_ERROR: name = "ERR"; break;
  }

  return name;
}

CHK_CORE_API chk_log_fn_t chk_log_get_fn(void) {
  chk_log_fn_t fn = g_log_fn ? g_log_fn : _chk_log_stub;
  return fn;
}

CHK_CORE_API void* chk_log_get_user_data(void) {
  void* user_data = g_log_user_data;
  return user_data;
}

CHK_CORE_API void chk_log_set_fn(chk_log_fn_t fn, void* user_data) {
  g_log_fn        = fn;
  g_log_user_data = user_data;
}

CHK_CORE_API chk_log_sev_t chk_log_get_sev(void) {
  chk_log_sev_t sev = g_log_sev;
  return sev;
}

CHK_CORE_API void chk_log_set_sev(chk_log_sev_t sev) {
  if (sev < CHK_LOG_SEV_TRACE || sev > CHK_LOG_SEV_ERROR) { return; }
  g_log_sev = sev;
}

CHK_CORE_API void _chk_log(chk_log_sev_t sev, const char* sender, const char* msg, const char* f, int ln,
                           const char* fn) {
  chk_log_fn_t log_fn = chk_log_get_fn();
  log_fn(sev, sender, msg, f, ln, fn);
}

CHK_CORE_API void _chk_log_f(chk_log_sev_t sev, const char* sender, const char* msg, const char* f, int ln,
                             const char* fn, ...) {
  va_list args;
  va_start(args, fn);
  _chk_log_v(sev, sender, msg, f, ln, fn, args);
  va_end(args);
}

CHK_CORE_API void _chk_log_v(chk_log_sev_t sev, const char* sender, const char* msg, const char* f, int ln,
                             const char* fn, va_list args) {
  char buf[1024];

  va_list args_copy;
  va_copy(args_copy, args);
  int written = vsnprintf(buf, sizeof(buf), msg, args);
  va_end(args_copy);

  if (written > 0) { _chk_log(sev, sender, buf, f, ln, fn); }
}

CHK_CORE_LOCAL void _chk_log_stub(chk_log_sev_t sev, const char* sender, const char* msg, const char* f, int ln,
                                  const char* fn) {
  if (sev < chk_log_get_sev()) { return; }

  (void)sev;
  (void)f;
  (void)ln;
  (void)fn;

  const char* sev_name = chk_log_sev_to_str(sev);

  if (sender) {
    fprintf(stderr, "[%s] [%s:%d:%s] [%s] %s\n", sev_name, f, ln, fn, sender, msg);
  } else {
    fprintf(stderr, "[%s] [%s:%d:%s] %s\n", sev_name, f, ln, fn, msg);
  }
}
