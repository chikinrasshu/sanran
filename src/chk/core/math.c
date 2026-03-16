#include <chk/core/math.h>

#include <math.h>

CHK_CORE_API float chk_deg_to_rad_f32(float deg) { //
  return deg * (Pi32 / 180.0f);
}

CHK_CORE_API double chk_deg_to_rad_f64(double deg) { //
  return deg * (Pi64 / 180.0);
}

CHK_CORE_API float chk_rad_to_deg_f32(float rad) { //
  return rad * (180.0f / Pi32);
}

CHK_CORE_API double chk_rad_to_deg_f64(double rad) { //
  return rad * (180.0 / Pi64);
}

CHK_CORE_API float chk_sin_f32(float x) { //
  return sinf(x);
}

CHK_CORE_API double chk_sin_f64(double x) { //
  return sin(x);
}

CHK_CORE_API float chk_cos_f32(float x) { //
  return cosf(x);
}

CHK_CORE_API double chk_cos_f64(double x) { //
  return cos(x);
}

CHK_CORE_API float chk_tan_f32(float x) { //
  return tanf(x);
}

CHK_CORE_API double chk_tan_f64(double x) { //
  return tan(x);
}

CHK_CORE_API float chk_asin_f32(float x) { //
  return asinf(x);
}

CHK_CORE_API double chk_asin_f64(double x) { //
  return asin(x);
}

CHK_CORE_API float chk_acos_f32(float x) { //
  return acosf(x);
}

CHK_CORE_API double chk_acos_f64(double x) { //
  return acos(x);
}

CHK_CORE_API float chk_atan_f32(float x) { //
  return atanf(x);
}

CHK_CORE_API double chk_atan_f64(double x) { //
  return atan(x);
}

CHK_CORE_API float chk_atan2_f32(float y, float x) { //
  return atan2f(y, x);
}

CHK_CORE_API double chk_atan2_f64(double y, double x) { //
  return atan2(y, x);
}

CHK_CORE_API double chk_lerp(double a, double b, double t) { //
  return a + t * (b - a);
}

CHK_CORE_API double chk_smoothstep(double edge0, double edge1, double x) { //
  double t = chk_clamp(chk_map(x, edge0, edge1, 0.0, 1.0), 0.0, 1.0);
  return t * t * (3.0 - 2.0 * t);
}

CHK_CORE_API double chk_map(double x, double a1, double a2, double b1, double b2) { //
  return b1 + ((x - a1) / (a2 - a1)) * (b2 - b1);
}

CHK_CORE_API uint8_t chk_abs_u8(uint8_t x) { //
  return x;
}

CHK_CORE_API uint16_t chk_abs_u16(uint16_t x) { //
  return x;
}

CHK_CORE_API uint32_t chk_abs_u32(uint32_t x) { //
  return x;
}

CHK_CORE_API uint64_t chk_abs_u64(uint64_t x) { //
  return x;
}

CHK_CORE_API int8_t chk_abs_s8(int8_t x) { //
  return x < 0 ? -x : x;
}

CHK_CORE_API int16_t chk_abs_s16(int16_t x) { //
  return x < 0 ? -x : x;
}

CHK_CORE_API int32_t chk_abs_s32(int32_t x) { //
  return x < 0 ? -x : x;
}

CHK_CORE_API int64_t chk_abs_s64(int64_t x) { //
  return x < 0 ? -x : x;
}

CHK_CORE_API float chk_abs_f32(float x) { //
  return fabsf(x);
}

CHK_CORE_API double chk_abs_f64(double x) { //
  return fabs(x);
}

CHK_CORE_API uint8_t chk_sign_u8(uint8_t x) { //
  return 1;
}

CHK_CORE_API uint16_t chk_sign_u16(uint16_t x) { //
  return 1;
}

CHK_CORE_API uint32_t chk_sign_u32(uint32_t x) { //
  return 1;
}

CHK_CORE_API uint64_t chk_sign_u64(uint64_t x) { //
  return 1;
}

CHK_CORE_API int8_t chk_sign_s8(int8_t x) { //
  return x < 0 ? -1 : 1;
}

CHK_CORE_API int16_t chk_sign_s16(int16_t x) { //
  return x < 0 ? -1 : 1;
}

CHK_CORE_API int32_t chk_sign_s32(int32_t x) { //
  return x < 0 ? -1 : 1;
}

CHK_CORE_API int64_t chk_sign_s64(int64_t x) { //
  return x < 0 ? -1 : 1;
}

CHK_CORE_API float chk_sign_f32(float x) { //
  return x < 0 ? -1.0f : 1.0f;
}

CHK_CORE_API double chk_sign_f64(double x) { //
  return x < 0 ? -1.0 : 1.0;
}

CHK_CORE_API uint8_t chk_clamp_u8(uint8_t x, uint8_t min, uint8_t max) { //
  return x < min ? min : (x > max ? max : x);
}

CHK_CORE_API uint16_t chk_clamp_u16(uint16_t x, uint16_t min, uint16_t max) { //
  return x < min ? min : (x > max ? max : x);
}

CHK_CORE_API uint32_t chk_clamp_u32(uint32_t x, uint32_t min, uint32_t max) { //
  return x < min ? min : (x > max ? max : x);
}

CHK_CORE_API uint64_t chk_clamp_u64(uint64_t x, uint64_t min, uint64_t max) { //
  return x < min ? min : (x > max ? max : x);
}

CHK_CORE_API int8_t chk_clamp_s8(int8_t x, int8_t min, int8_t max) { //
  return x < min ? min : (x > max ? max : x);
}

CHK_CORE_API int16_t chk_clamp_s16(int16_t x, int16_t min, int16_t max) { //
  return x < min ? min : (x > max ? max : x);
}

CHK_CORE_API int32_t chk_clamp_s32(int32_t x, int32_t min, int32_t max) { //
  return x < min ? min : (x > max ? max : x);
}

CHK_CORE_API int64_t chk_clamp_s64(int64_t x, int64_t min, int64_t max) { //
  return x < min ? min : (x > max ? max : x);
}

CHK_CORE_API float chk_clamp_f32(float x, float min, float max) { //
  return x < min ? min : (x > max ? max : x);
}

CHK_CORE_API double chk_clamp_f64(double x, double min, double max) { //
  return x < min ? min : (x > max ? max : x);
}

CHK_CORE_API uint8_t chk_floor_u8(uint8_t x) { //
  return x;
}

CHK_CORE_API uint16_t chk_floor_u16(uint16_t x) { //
  return x;
}

CHK_CORE_API uint32_t chk_floor_u32(uint32_t x) { //
  return x;
}

CHK_CORE_API uint64_t chk_floor_u64(uint64_t x) { //
  return x;
}

CHK_CORE_API int8_t chk_floor_s8(int8_t x) { //
  return x;
}

CHK_CORE_API int16_t chk_floor_s16(int16_t x) { //
  return x;
}

CHK_CORE_API int32_t chk_floor_s32(int32_t x) { //
  return x;
}

CHK_CORE_API int64_t chk_floor_s64(int64_t x) { //
  return x;
}

CHK_CORE_API float chk_floor_f32(float x) { //
  return floorf(x);
}

CHK_CORE_API double chk_floor_f64(double x) { //
  return floor(x);
}

CHK_CORE_API uint8_t chk_ceil_u8(uint8_t x) { //
  return x;
}

CHK_CORE_API uint16_t chk_ceil_u16(uint16_t x) { //
  return x;
}

CHK_CORE_API uint32_t chk_ceil_u32(uint32_t x) { //
  return x;
}

CHK_CORE_API uint64_t chk_ceil_u64(uint64_t x) { //
  return x;
}

CHK_CORE_API int8_t chk_ceil_s8(int8_t x) { //
  return x;
}

CHK_CORE_API int16_t chk_ceil_s16(int16_t x) { //
  return x;
}

CHK_CORE_API int32_t chk_ceil_s32(int32_t x) { //
  return x;
}

CHK_CORE_API int64_t chk_ceil_s64(int64_t x) { //
  return x;
}

CHK_CORE_API float chk_ceil_f32(float x) { //
  return ceilf(x);
}

CHK_CORE_API double chk_ceil_f64(double x) { //
  return ceil(x);
}

CHK_CORE_API uint8_t chk_round_u8(uint8_t x) { //
  return x;
}

CHK_CORE_API uint16_t chk_round_u16(uint16_t x) { //
  return x;
}

CHK_CORE_API uint32_t chk_round_u32(uint32_t x) { //
  return x;
}

CHK_CORE_API uint64_t chk_round_u64(uint64_t x) { //
  return x;
}

CHK_CORE_API int8_t chk_round_s8(int8_t x) { //
  return x;
}

CHK_CORE_API int16_t chk_round_s16(int16_t x) { //
  return x;
}

CHK_CORE_API int32_t chk_round_s32(int32_t x) { //
  return x;
}

CHK_CORE_API int64_t chk_round_s64(int64_t x) { //
  return x;
}

CHK_CORE_API float chk_round_f32(float x) { //
  return roundf(x);
}

CHK_CORE_API double chk_round_f64(double x) { //
  return round(x);
}

CHK_CORE_API uint8_t chk_min_u8(uint8_t a, uint8_t b) { //
  return a < b ? a : b;
}

CHK_CORE_API uint16_t chk_min_u16(uint16_t a, uint16_t b) { //
  return a < b ? a : b;
}

CHK_CORE_API uint32_t chk_min_u32(uint32_t a, uint32_t b) { //
  return a < b ? a : b;
}

CHK_CORE_API uint64_t chk_min_u64(uint64_t a, uint64_t b) { //
  return a < b ? a : b;
}

CHK_CORE_API int8_t chk_min_s8(int8_t a, int8_t b) { //
  return a < b ? a : b;
}

CHK_CORE_API int16_t chk_min_s16(int16_t a, int16_t b) { //
  return a < b ? a : b;
}

CHK_CORE_API int32_t chk_min_s32(int32_t a, int32_t b) { //
  return a < b ? a : b;
}

CHK_CORE_API int64_t chk_min_s64(int64_t a, int64_t b) { //
  return a < b ? a : b;
}

CHK_CORE_API float chk_min_f32(float a, float b) { //
  return fminf(a, b);
}

CHK_CORE_API double chk_min_f64(double a, double b) { //
  return fmin(a, b);
}

CHK_CORE_API uint8_t chk_max_u8(uint8_t a, uint8_t b) { //
  return a > b ? a : b;
}

CHK_CORE_API uint16_t chk_max_u16(uint16_t a, uint16_t b) { //
  return a > b ? a : b;
}

CHK_CORE_API uint32_t chk_max_u32(uint32_t a, uint32_t b) { //
  return a > b ? a : b;
}

CHK_CORE_API uint64_t chk_max_u64(uint64_t a, uint64_t b) { //
  return a > b ? a : b;
}

CHK_CORE_API int8_t chk_max_s8(int8_t a, int8_t b) { //
  return a > b ? a : b;
}

CHK_CORE_API int16_t chk_max_s16(int16_t a, int16_t b) { //
  return a > b ? a : b;
}

CHK_CORE_API int32_t chk_max_s32(int32_t a, int32_t b) { //
  return a > b ? a : b;
}

CHK_CORE_API int64_t chk_max_s64(int64_t a, int64_t b) { //
  return a > b ? a : b;
}

CHK_CORE_API float chk_max_f32(float a, float b) { //
  return fmaxf(a, b);
}

CHK_CORE_API double chk_max_f64(double a, double b) { //
  return fmax(a, b);
}

CHK_CORE_API float chk_sqrt_f32(float x) { //
  return sqrtf(x);
}

CHK_CORE_API double chk_sqrt_f64(double x) { //
  return sqrt(x);
}

CHK_CORE_API float chk_pow_f32(float x, float y) { //
  return powf(x, y);
}

CHK_CORE_API double chk_pow_f64(double x, double y) { //
  return pow(x, y);
}

CHK_CORE_API float chk_exp_f32(float x) { //
  return expf(x);
}

CHK_CORE_API double chk_exp_f64(double x) { //
  return exp(x);
}

CHK_CORE_API float chk_logE_f32(float x) { //
  return logf(x);
}

CHK_CORE_API double chk_logE_f64(double x) { //
  return log(x);
}

CHK_CORE_API float chk_log10_f32(float x) { //
  return log10f(x);
}

CHK_CORE_API double chk_log10_f64(double x) { //
  return log10(x);
}

CHK_CORE_API float chk_log2_f32(float x) { //
  return log2f(x);
}

CHK_CORE_API double chk_log2_f64(double x) { //
  return log2(x);
}
