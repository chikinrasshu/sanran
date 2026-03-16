#pragma once

#include <chk/core/export.h>

#include <chk/core/core.h>

#include <stdarg.h>

typedef enum chk_log_sev {
  CHK_LOG_SEV_NONE = 0,

  CHK_LOG_SEV_TRACE,
  CHK_LOG_SEV_DEBUG,
  CHK_LOG_SEV_INFO,
  CHK_LOG_SEV_WARN,
  CHK_LOG_SEV_ERROR,

  CHK_LOG_SEV_COUNT,
} chk_log_sev_t;

CHK_CORE_API const char* chk_log_sev_to_str(chk_log_sev_t sev);

typedef void (*chk_log_fn_t)(chk_log_sev_t sev, const char* sender, const char* msg, const char* f, int ln,
                             const char* fn);

CHK_CORE_API chk_log_fn_t chk_log_get_fn(void);
CHK_CORE_API void*        chk_log_get_user_data(void);
CHK_CORE_API void         chk_log_set_fn(chk_log_fn_t fn, void* user_data);

CHK_CORE_API chk_log_sev_t chk_log_get_sev(void);
CHK_CORE_API void          chk_log_set_sev(chk_log_sev_t sev);

CHK_CORE_API void _chk_log(chk_log_sev_t sev, const char* sender, const char* msg, const char* f, int ln,
                           const char* fn);
CHK_CORE_API void _chk_log_f(chk_log_sev_t sev, const char* sender, const char* msg, const char* f, int ln,
                             const char* fn, ...);
CHK_CORE_API void _chk_log_v(chk_log_sev_t sev, const char* sender, const char* msg, const char* f, int ln,
                             const char* fn, va_list args);

#define chk_log_trace(msg, ...)                                                                                        \
  _chk_log##__VA_OPT__(_f)(CHK_LOG_SEV_TRACE, NULL, (msg), __FILE__, __LINE__, __func__ __VA_OPT__(, __VA_ARGS__))
#define chk_log_debug(msg, ...)                                                                                        \
  _chk_log##__VA_OPT__(_f)(CHK_LOG_SEV_DEBUG, NULL, (msg), __FILE__, __LINE__, __func__ __VA_OPT__(, __VA_ARGS__))
#define chk_log_info(msg, ...)                                                                                         \
  _chk_log##__VA_OPT__(_f)(CHK_LOG_SEV_INFO, NULL, (msg), __FILE__, __LINE__, __func__ __VA_OPT__(, __VA_ARGS__))
#define chk_log_warn(msg, ...)                                                                                         \
  _chk_log##__VA_OPT__(_f)(CHK_LOG_SEV_WARN, NULL, (msg), __FILE__, __LINE__, __func__ __VA_OPT__(, __VA_ARGS__))
#define chk_log_error(msg, ...)                                                                                        \
  _chk_log##__VA_OPT__(_f)(CHK_LOG_SEV_ERROR, NULL, (msg), __FILE__, __LINE__, __func__ __VA_OPT__(, __VA_ARGS__))

#define chk_log_trace_v(msg, args) _chk_log_v(CHK_LOG_SEV_TRACE, NULL, (msg), __FILE__, __LINE__, __func__, (args))
#define chk_log_debug_v(msg, args) _chk_log_v(CHK_LOG_SEV_DEBUG, NULL, (msg), __FILE__, __LINE__, __func__, (args))
#define chk_log_info_v(msg, args)  _chk_log_v(CHK_LOG_SEV_INFO, NULL, (msg), __FILE__, __LINE__, __func__, (args))
#define chk_log_warn_v(msg, args)  _chk_log_v(CHK_LOG_SEV_WARN, NULL, (msg), __FILE__, __LINE__, __func__, (args))
#define chk_log_error_v(msg, args) _chk_log_v(CHK_LOG_SEV_ERROR, NULL, (msg), __FILE__, __LINE__, __func__, (args))

#define chk_log_trace_by(sender, msg, ...)                                                                             \
  _chk_log##__VA_OPT__(_f)(CHK_LOG_SEV_TRACE, (sender), (msg), __FILE__, __LINE__, __func__ __VA_OPT__(, __VA_ARGS__))
#define chk_log_debug_by(sender, msg, ...)                                                                             \
  _chk_log##__VA_OPT__(_f)(CHK_LOG_SEV_DEBUG, (sender), (msg), __FILE__, __LINE__, __func__ __VA_OPT__(, __VA_ARGS__))
#define chk_log_info_by(sender, msg, ...)                                                                              \
  _chk_log##__VA_OPT__(_f)(CHK_LOG_SEV_INFO, (sender), (msg), __FILE__, __LINE__, __func__ __VA_OPT__(, __VA_ARGS__))
#define chk_log_warn_by(sender, msg, ...)                                                                              \
  _chk_log##__VA_OPT__(_f)(CHK_LOG_SEV_WARN, (sender), (msg), __FILE__, __LINE__, __func__ __VA_OPT__(, __VA_ARGS__))
#define chk_log_error_by(sender, msg, ...)                                                                             \
  _chk_log##__VA_OPT__(_f)(CHK_LOG_SEV_ERROR, (sender), (msg), __FILE__, __LINE__, __func__ __VA_OPT__(, __VA_ARGS__))

#define chk_log_trace_by_v(sender, msg, args)                                                                          \
  _chk_log_v(CHK_LOG_SEV_TRACE, (sender), (msg), __FILE__, __LINE__, __func__, (args))
#define chk_log_debug_by_v(sender, msg, args)                                                                          \
  _chk_log_v(CHK_LOG_SEV_DEBUG, (sender), (msg), __FILE__, __LINE__, __func__, (args))
#define chk_log_info_by_v(sender, msg, args)                                                                           \
  _chk_log_v(CHK_LOG_SEV_INFO, (sender), (msg), __FILE__, __LINE__, __func__, (args))
#define chk_log_warn_by_v(sender, msg, args)                                                                           \
  _chk_log_v(CHK_LOG_SEV_WARN, (sender), (msg), __FILE__, __LINE__, __func__, (args))
#define chk_log_error_by_v(sender, msg, args)                                                                          \
  _chk_log_v(CHK_LOG_SEV_ERROR, (sender), (msg), __FILE__, __LINE__, __func__, (args))
