#pragma once

#include <chk/core/export.h>

#include <chk/core/core.h>

#define Pi32  3.14159265358979323846f
#define Pi64  3.14159265358979323846
#define Tau32 6.28318530717958647692f
#define Tau64 6.28318530717958647692

CHK_CORE_API float  chk_deg_to_rad_f32(float deg);
CHK_CORE_API double chk_deg_to_rad_f64(double deg);

#define chk_deg_to_rad(x) _Generic((x), float: chk_deg_to_rad_f32, double: chk_deg_to_rad_f64)(x)

CHK_CORE_API float  chk_rad_to_deg_f32(float rad);
CHK_CORE_API double chk_rad_to_deg_f64(double rad);

#define chk_rad_to_deg(x) _Generic((x), float: chk_rad_to_deg_f32, double: chk_rad_to_deg_f64)(x)

CHK_CORE_API float  chk_sin_f32(float x);
CHK_CORE_API double chk_sin_f64(double x);

#define chk_sin(x) _Generic((x), float: chk_sin_f32, double: chk_sin_f64)(x)

CHK_CORE_API float  chk_cos_f32(float x);
CHK_CORE_API double chk_cos_f64(double x);

#define chk_cos(x) _Generic((x), float: chk_cos_f32, double: chk_cos_f64)(x)

CHK_CORE_API float  chk_tan_f32(float x);
CHK_CORE_API double chk_tan_f64(double x);

#define chk_tan(x) _Generic((x), float: chk_tan_f32, double: chk_tan_f64)(x)

CHK_CORE_API float  chk_asin_f32(float x);
CHK_CORE_API double chk_asin_f64(double x);

#define chk_asin(x) _Generic((x), float: chk_asin_f32, double: chk_asin_f64)(x)

CHK_CORE_API float  chk_acos_f32(float x);
CHK_CORE_API double chk_acos_f64(double x);

#define chk_acos(x) _Generic((x), float: chk_acos_f32, double: chk_acos_f64)(x)

CHK_CORE_API float  chk_atan_f32(float x);
CHK_CORE_API double chk_atan_f64(double x);

#define chk_atan(x) _Generic((x), float: chk_atan_f32, double: chk_atan_f64)(x)

CHK_CORE_API float  chk_atan2_f32(float y, float x);
CHK_CORE_API double chk_atan2_f64(double y, double x);

#define chk_atan2(y, x) _Generic((y), float: chk_atan2_f32, double: chk_atan2_f64)(y, x)

CHK_CORE_API double chk_lerp(double a, double b, double t);
CHK_CORE_API double chk_smoothstep(double edge0, double edge1, double x);
CHK_CORE_API double chk_map(double x, double a1, double a2, double b1, double b2);

CHK_CORE_API uint8_t  chk_abs_u8(uint8_t x);
CHK_CORE_API uint16_t chk_abs_u16(uint16_t x);
CHK_CORE_API uint32_t chk_abs_u32(uint32_t x);
CHK_CORE_API uint64_t chk_abs_u64(uint64_t x);
CHK_CORE_API int8_t   chk_abs_s8(int8_t x);
CHK_CORE_API int16_t  chk_abs_s16(int16_t x);
CHK_CORE_API int32_t  chk_abs_s32(int32_t x);
CHK_CORE_API int64_t  chk_abs_s64(int64_t x);
CHK_CORE_API float    chk_abs_f32(float x);
CHK_CORE_API double   chk_abs_f64(double x);

#define chk_abs(x)                                                                                                     \
  _Generic((x),                                                                                                        \
      uint8_t: chk_abs_u8,                                                                                             \
      uint16_t: chk_abs_u16,                                                                                           \
      uint32_t: chk_abs_u32,                                                                                           \
      uint64_t: chk_abs_u64,                                                                                           \
      int8_t: chk_abs_s8,                                                                                              \
      int16_t: chk_abs_s16,                                                                                            \
      int32_t: chk_abs_s32,                                                                                            \
      int64_t: chk_abs_s64,                                                                                            \
      float: chk_abs_f32,                                                                                              \
      double: chk_abs_f64)(x)

CHK_CORE_API uint8_t  chk_sign_u8(uint8_t x);
CHK_CORE_API uint16_t chk_sign_u16(uint16_t x);
CHK_CORE_API uint32_t chk_sign_u32(uint32_t x);
CHK_CORE_API uint64_t chk_sign_u64(uint64_t x);
CHK_CORE_API int8_t   chk_sign_s8(int8_t x);
CHK_CORE_API int16_t  chk_sign_s16(int16_t x);
CHK_CORE_API int32_t  chk_sign_s32(int32_t x);
CHK_CORE_API int64_t  chk_sign_s64(int64_t x);
CHK_CORE_API float    chk_sign_f32(float x);
CHK_CORE_API double   chk_sign_f64(double x);

#define chk_sign(x)                                                                                                    \
  _Generic((x),                                                                                                        \
      uint8_t: chk_sign_u8,                                                                                            \
      uint16_t: chk_sign_u16,                                                                                          \
      uint32_t: chk_sign_u32,                                                                                          \
      uint64_t: chk_sign_u64,                                                                                          \
      int8_t: chk_sign_s8,                                                                                             \
      int16_t: chk_sign_s16,                                                                                           \
      int32_t: chk_sign_s32,                                                                                           \
      int64_t: chk_sign_s64,                                                                                           \
      float: chk_sign_f32,                                                                                             \
      double: chk_sign_f64)(x)

CHK_CORE_API uint8_t  chk_clamp_u8(uint8_t x, uint8_t min, uint8_t max);
CHK_CORE_API uint16_t chk_clamp_u16(uint16_t x, uint16_t min, uint16_t max);
CHK_CORE_API uint32_t chk_clamp_u32(uint32_t x, uint32_t min, uint32_t max);
CHK_CORE_API uint64_t chk_clamp_u64(uint64_t x, uint64_t min, uint64_t max);
CHK_CORE_API int8_t   chk_clamp_s8(int8_t x, int8_t min, int8_t max);
CHK_CORE_API int16_t  chk_clamp_s16(int16_t x, int16_t min, int16_t max);
CHK_CORE_API int32_t  chk_clamp_s32(int32_t x, int32_t min, int32_t max);
CHK_CORE_API int64_t  chk_clamp_s64(int64_t x, int64_t min, int64_t max);
CHK_CORE_API float    chk_clamp_f32(float x, float min, float max);
CHK_CORE_API double   chk_clamp_f64(double x, double min, double max);

#define chk_clamp(x, min, max)                                                                                         \
  _Generic((x),                                                                                                        \
      uint8_t: chk_clamp_u8,                                                                                           \
      uint16_t: chk_clamp_u16,                                                                                         \
      uint32_t: chk_clamp_u32,                                                                                         \
      uint64_t: chk_clamp_u64,                                                                                         \
      int8_t: chk_clamp_s8,                                                                                            \
      int16_t: chk_clamp_s16,                                                                                          \
      int32_t: chk_clamp_s32,                                                                                          \
      int64_t: chk_clamp_s64,                                                                                          \
      float: chk_clamp_f32,                                                                                            \
      double: chk_clamp_f64)(x, min, max)

CHK_CORE_API uint8_t  chk_floor_u8(uint8_t x);
CHK_CORE_API uint16_t chk_floor_u16(uint16_t x);
CHK_CORE_API uint32_t chk_floor_u32(uint32_t x);
CHK_CORE_API uint64_t chk_floor_u64(uint64_t x);
CHK_CORE_API int8_t   chk_floor_s8(int8_t x);
CHK_CORE_API int16_t  chk_floor_s16(int16_t x);
CHK_CORE_API int32_t  chk_floor_s32(int32_t x);
CHK_CORE_API int64_t  chk_floor_s64(int64_t x);
CHK_CORE_API float    chk_floor_f32(float x);
CHK_CORE_API double   chk_floor_f64(double x);

#define chk_floor(x)                                                                                                   \
  _Generic((x),                                                                                                        \
      uint8_t: chk_floor_u8,                                                                                           \
      uint16_t: chk_floor_u16,                                                                                         \
      uint32_t: chk_floor_u32,                                                                                         \
      uint64_t: chk_floor_u64,                                                                                         \
      int8_t: chk_floor_s8,                                                                                            \
      int16_t: chk_floor_s16,                                                                                          \
      int32_t: chk_floor_s32,                                                                                          \
      int64_t: chk_floor_s64,                                                                                          \
      float: chk_floor_f32,                                                                                            \
      double: chk_floor_f64)(x)

CHK_CORE_API uint8_t  chk_ceil_u8(uint8_t x);
CHK_CORE_API uint16_t chk_ceil_u16(uint16_t x);
CHK_CORE_API uint32_t chk_ceil_u32(uint32_t x);
CHK_CORE_API uint64_t chk_ceil_u64(uint64_t x);
CHK_CORE_API int8_t   chk_ceil_s8(int8_t x);
CHK_CORE_API int16_t  chk_ceil_s16(int16_t x);
CHK_CORE_API int32_t  chk_ceil_s32(int32_t x);
CHK_CORE_API int64_t  chk_ceil_s64(int64_t x);
CHK_CORE_API float    chk_ceil_f32(float x);
CHK_CORE_API double   chk_ceil_f64(double x);

#define chk_ceil(x)                                                                                                    \
  _Generic((x),                                                                                                        \
      uint8_t: chk_ceil_u8,                                                                                            \
      uint16_t: chk_ceil_u16,                                                                                          \
      uint32_t: chk_ceil_u32,                                                                                          \
      uint64_t: chk_ceil_u64,                                                                                          \
      int8_t: chk_ceil_s8,                                                                                             \
      int16_t: chk_ceil_s16,                                                                                           \
      int32_t: chk_ceil_s32,                                                                                           \
      int64_t: chk_ceil_s64,                                                                                           \
      float: chk_ceil_f32,                                                                                             \
      double: chk_ceil_f64)(x)

CHK_CORE_API uint8_t  chk_round_u8(uint8_t x);
CHK_CORE_API uint16_t chk_round_u16(uint16_t x);
CHK_CORE_API uint32_t chk_round_u32(uint32_t x);
CHK_CORE_API uint64_t chk_round_u64(uint64_t x);
CHK_CORE_API int8_t   chk_round_s8(int8_t x);
CHK_CORE_API int16_t  chk_round_s16(int16_t x);
CHK_CORE_API int32_t  chk_round_s32(int32_t x);
CHK_CORE_API int64_t  chk_round_s64(int64_t x);
CHK_CORE_API float    chk_round_f32(float x);
CHK_CORE_API double   chk_round_f64(double x);

#define chk_round(x)                                                                                                   \
  _Generic((x),                                                                                                        \
      uint8_t: chk_round_u8,                                                                                           \
      uint16_t: chk_round_u16,                                                                                         \
      uint32_t: chk_round_u32,                                                                                         \
      uint64_t: chk_round_u64,                                                                                         \
      int8_t: chk_round_s8,                                                                                            \
      int16_t: chk_round_s16,                                                                                          \
      int32_t: chk_round_s32,                                                                                          \
      int64_t: chk_round_s64,                                                                                          \
      float: chk_round_f32,                                                                                            \
      double: chk_round_f64)(x)

CHK_CORE_API uint8_t  chk_min_u8(uint8_t a, uint8_t b);
CHK_CORE_API uint16_t chk_min_u16(uint16_t a, uint16_t b);
CHK_CORE_API uint32_t chk_min_u32(uint32_t a, uint32_t b);
CHK_CORE_API uint64_t chk_min_u64(uint64_t a, uint64_t b);
CHK_CORE_API int8_t   chk_min_s8(int8_t a, int8_t b);
CHK_CORE_API int16_t  chk_min_s16(int16_t a, int16_t b);
CHK_CORE_API int32_t  chk_min_s32(int32_t a, int32_t b);
CHK_CORE_API int64_t  chk_min_s64(int64_t a, int64_t b);
CHK_CORE_API float    chk_min_f32(float a, float b);
CHK_CORE_API double   chk_min_f64(double a, double b);

#define chk_min(a, b)                                                                                                  \
  _Generic((a),                                                                                                        \
      uint8_t: chk_min_u8,                                                                                             \
      uint16_t: chk_min_u16,                                                                                           \
      uint32_t: chk_min_u32,                                                                                           \
      uint64_t: chk_min_u64,                                                                                           \
      int8_t: chk_min_s8,                                                                                              \
      int16_t: chk_min_s16,                                                                                            \
      int32_t: chk_min_s32,                                                                                            \
      int64_t: chk_min_s64,                                                                                            \
      float: chk_min_f32,                                                                                              \
      double: chk_min_f64)(a, b)

CHK_CORE_API uint8_t  chk_max_u8(uint8_t a, uint8_t b);
CHK_CORE_API uint16_t chk_max_u16(uint16_t a, uint16_t b);
CHK_CORE_API uint32_t chk_max_u32(uint32_t a, uint32_t b);
CHK_CORE_API uint64_t chk_max_u64(uint64_t a, uint64_t b);
CHK_CORE_API int8_t   chk_max_s8(int8_t a, int8_t b);
CHK_CORE_API int16_t  chk_max_s16(int16_t a, int16_t b);
CHK_CORE_API int32_t  chk_max_s32(int32_t a, int32_t b);
CHK_CORE_API int64_t  chk_max_s64(int64_t a, int64_t b);
CHK_CORE_API float    chk_max_f32(float a, float b);
CHK_CORE_API double   chk_max_f64(double a, double b);

#define chk_max(a, b)                                                                                                  \
  _Generic((a),                                                                                                        \
      uint8_t: chk_max_u8,                                                                                             \
      uint16_t: chk_max_u16,                                                                                           \
      uint32_t: chk_max_u32,                                                                                           \
      uint64_t: chk_max_u64,                                                                                           \
      int8_t: chk_max_s8,                                                                                              \
      int16_t: chk_max_s16,                                                                                            \
      int32_t: chk_max_s32,                                                                                            \
      int64_t: chk_max_s64,                                                                                            \
      float: chk_max_f32,                                                                                              \
      double: chk_max_f64)(a, b)

CHK_CORE_API float  chk_sqrt_f32(float x);
CHK_CORE_API double chk_sqrt_f64(double x);

#define chk_sqrt(x) _Generic((x), float: chk_sqrt_f32, double: chk_sqrt_f64)(x)

CHK_CORE_API float  chk_pow_f32(float x, float y);
CHK_CORE_API double chk_pow_f64(double x, double y);

#define chk_pow(x, y) _Generic((x), float: chk_pow_f32, double: chk_pow_f64)(x, y)

CHK_CORE_API float  chk_exp_f32(float x);
CHK_CORE_API double chk_exp_f64(double x);

#define chk_exp(x) _Generic((x), float: chk_exp_f32, double: chk_exp_f64)(x)

CHK_CORE_API float  chk_logE_f32(float x);
CHK_CORE_API double chk_logE_f64(double x);

#define chk_logE(x) _Generic((x), float: chk_logE_f32, double: chk_logE_f64)(x)

CHK_CORE_API float  chk_log10_f32(float x);
CHK_CORE_API double chk_log10_f64(double x);

#define chk_log10(x) _Generic((x), float: chk_log10_f32, double: chk_log10_f64)(x)

CHK_CORE_API float  chk_log2_f32(float x);
CHK_CORE_API double chk_log2_f64(double x);

#define chk_log2(x) _Generic((x), float: chk_log2_f32, double: chk_log2_f64)(x)
