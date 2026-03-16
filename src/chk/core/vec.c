#include <chk/core/vec.h>

#include <chk/core/math.h>

CHK_CORE_API chk_v2_t chk_v2_make(double x, double y) {
  chk_v2_t v = {.x = x, .y = y};
  return v;
}

CHK_CORE_API chk_v3_t chk_v3_make(double x, double y, double z) {
  chk_v3_t v = {.x = x, .y = y, .z = z};
  return v;
}

CHK_CORE_API chk_v4_t chk_v4_make(double x, double y, double z, double w) {
  chk_v4_t v = {.x = x, .y = y, .z = z, .w = w};
  return v;
}

CHK_CORE_API chk_v2_t chk_v2_zero(void) {
  chk_v2_t v = chk_v2_make(0.0, 0.0);
  return v;
}

CHK_CORE_API chk_v3_t chk_v3_zero(void) {
  chk_v3_t v = chk_v3_make(0.0, 0.0, 0.0);
  return v;
}

CHK_CORE_API chk_v4_t chk_v4_zero(void) {
  chk_v4_t v = chk_v4_make(0.0, 0.0, 0.0, 0.0);
  return v;
}

CHK_CORE_API chk_v2_t chk_v2_one(void) {
  chk_v2_t v = chk_v2_make(1.0, 1.0);
  return v;
}

CHK_CORE_API chk_v3_t chk_v3_one(void) {
  chk_v3_t v = chk_v3_make(1.0, 1.0, 1.0);
  return v;
}

CHK_CORE_API chk_v4_t chk_v4_one(void) {
  chk_v4_t v = chk_v4_make(1.0, 1.0, 1.0, 1.0);
  return v;
}

CHK_CORE_API chk_v2_t chk_v2_add(chk_v2_t a, chk_v2_t b) {
  chk_v2_t result = {.x = a.x + b.x, .y = a.y + b.y};
  return result;
}

CHK_CORE_API chk_v3_t chk_v3_add(chk_v3_t a, chk_v3_t b) {
  chk_v3_t result = {.x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z};
  return result;
}

CHK_CORE_API chk_v4_t chk_v4_add(chk_v4_t a, chk_v4_t b) {
  chk_v4_t result = {.x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z, .w = a.w + b.w};
  return result;
}

CHK_CORE_API chk_v2_t chk_v2_sub(chk_v2_t a, chk_v2_t b) {
  chk_v2_t result = {.x = a.x - b.x, .y = a.y - b.y};
  return result;
}

CHK_CORE_API chk_v3_t chk_v3_sub(chk_v3_t a, chk_v3_t b) {
  chk_v3_t result = {.x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z};
  return result;
}

CHK_CORE_API chk_v4_t chk_v4_sub(chk_v4_t a, chk_v4_t b) {
  chk_v4_t result = {.x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z, .w = a.w - b.w};
  return result;
}

CHK_CORE_API chk_v2_t chk_v2_hadamard(chk_v2_t a, chk_v2_t b) {
  chk_v2_t result = {.x = a.x * b.x, .y = a.y * b.y};
  return result;
}

CHK_CORE_API chk_v3_t chk_v3_hadamard(chk_v3_t a, chk_v3_t b) {
  chk_v3_t result = {.x = a.x * b.x, .y = a.y * b.y, .z = a.z * b.z};
  return result;
}

CHK_CORE_API chk_v4_t chk_v4_hadamard(chk_v4_t a, chk_v4_t b) {
  chk_v4_t result = {.x = a.x * b.x, .y = a.y * b.y, .z = a.z * b.z, .w = a.w * b.w};
  return result;
}

CHK_CORE_API chk_v2_t chk_v2_scale(chk_v2_t v, double s) {
  chk_v2_t result = {.x = v.x * s, .y = v.y * s};
  return result;
}

CHK_CORE_API chk_v3_t chk_v3_scale(chk_v3_t v, double s) {
  chk_v3_t result = {.x = v.x * s, .y = v.y * s, .z = v.z * s};
  return result;
}

CHK_CORE_API chk_v4_t chk_v4_scale(chk_v4_t v, double s) {
  chk_v4_t result = {.x = v.x * s, .y = v.y * s, .z = v.z * s, .w = v.w * s};
  return result;
}

CHK_CORE_API chk_v2_t chk_v2_scale_left(double s, chk_v2_t v) {
  chk_v2_t result = {.x = v.x * s, .y = v.y * s};
  return result;
}

CHK_CORE_API chk_v3_t chk_v3_scale_left(double s, chk_v3_t v) {
  chk_v3_t result = {.x = v.x * s, .y = v.y * s, .z = v.z * s};
  return result;
}

CHK_CORE_API chk_v4_t chk_v4_scale_left(double s, chk_v4_t v) {
  chk_v4_t result = {.x = v.x * s, .y = v.y * s, .z = v.z * s, .w = v.w * s};
  return result;
}

CHK_CORE_API chk_v2_t chk_v2_div(chk_v2_t a, double d) {
  chk_v2_t result = {.x = a.x / d, .y = a.y / d};
  return result;
}

CHK_CORE_API chk_v3_t chk_v3_div(chk_v3_t a, double d) {
  chk_v3_t result = {.x = a.x / d, .y = a.y / d, .z = a.z / d};
  return result;
}

CHK_CORE_API chk_v4_t chk_v4_div(chk_v4_t a, double d) {
  chk_v4_t result = {.x = a.x / d, .y = a.y / d, .z = a.z / d, .w = a.w / d};
  return result;
}

CHK_CORE_API chk_v2_t chk_v2_div_left(double d, chk_v2_t a) {
  chk_v2_t result = {.x = d / a.x, .y = d / a.y};
  return result;
}

CHK_CORE_API chk_v3_t chk_v3_div_left(double d, chk_v3_t a) {
  chk_v3_t result = {.x = d / a.x, .y = d / a.y, .z = d / a.z};
  return result;
}

CHK_CORE_API chk_v4_t chk_v4_div_left(double d, chk_v4_t a) {
  chk_v4_t result = {.x = d / a.x, .y = d / a.y, .z = d / a.z, .w = d / a.w};
  return result;
}

CHK_CORE_API double chk_v2_dot(chk_v2_t a, chk_v2_t b) { //
  return a.x * b.x + a.y * b.y;
}

CHK_CORE_API double chk_v3_dot(chk_v3_t a, chk_v3_t b) { //
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

CHK_CORE_API double chk_v4_dot(chk_v4_t a, chk_v4_t b) { //
  return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

CHK_CORE_API double chk_v2_length_sq(chk_v2_t v) { //
  return v.x * v.x + v.y * v.y;
}

CHK_CORE_API double chk_v3_length_sq(chk_v3_t v) { //
  return v.x * v.x + v.y * v.y + v.z * v.z;
}

CHK_CORE_API double chk_v4_length_sq(chk_v4_t v) { //
  return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

CHK_CORE_API double chk_v2_length(chk_v2_t v) { //
  return chk_sqrt(v.x * v.x + v.y * v.y);
}

CHK_CORE_API double chk_v3_length(chk_v3_t v) { //
  return chk_sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

CHK_CORE_API double chk_v4_length(chk_v4_t v) { //
  return chk_sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

CHK_CORE_API double chk_v2_distance_sq(chk_v2_t a, chk_v2_t b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return dx * dx + dy * dy;
}
CHK_CORE_API double chk_v3_distance_sq(chk_v3_t a, chk_v3_t b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  double dz = a.z - b.z;
  return dx * dx + dy * dy + dz * dz;
}
CHK_CORE_API double chk_v4_distance_sq(chk_v4_t a, chk_v4_t b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  double dz = a.z - b.z;
  double dw = a.w - b.w;
  return dx * dx + dy * dy + dz * dz + dw * dw;
}

CHK_CORE_API double chk_v2_distance(chk_v2_t a, chk_v2_t b) {
  double dsq = chk_v2_distance_sq(a, b);
  return chk_sqrt(dsq);
}

CHK_CORE_API double chk_v3_distance(chk_v3_t a, chk_v3_t b) {
  double dsq = chk_v3_distance_sq(a, b);
  return chk_sqrt(dsq);
}
CHK_CORE_API double chk_v4_distance(chk_v4_t a, chk_v4_t b) {
  double dsq = chk_v4_distance_sq(a, b);
  return chk_sqrt(dsq);
}

CHK_CORE_API chk_v2_t chk_v2_normalize(chk_v2_t v) {
  double len = chk_v2_length(v);
  if (len > 0.0) {
    return chk_v2_div(v, len);
  } else {
    return chk_v2_zero();
  }
}

CHK_CORE_API chk_v3_t chk_v3_normalize(chk_v3_t v) {
  double len = chk_v3_length(v);
  if (len > 0.0) {
    return chk_v3_div(v, len);
  } else {
    return chk_v3_zero();
  }
}

CHK_CORE_API chk_v4_t chk_v4_normalize(chk_v4_t v) {
  double len = chk_v4_length(v);
  if (len > 0.0) {
    return chk_v4_div(v, len);
  } else {
    return chk_v4_zero();
  }
}

CHK_CORE_API chk_v2_t chk_v2_lerp(chk_v2_t a, chk_v2_t b, double t) {
  chk_v2_t result = {.x = chk_lerp(a.x, b.x, t), //
                     .y = chk_lerp(a.y, b.y, t)};
  return result;
}

CHK_CORE_API chk_v3_t chk_v3_lerp(chk_v3_t a, chk_v3_t b, double t) {
  chk_v3_t result = {.x = chk_lerp(a.x, b.x, t), //
                     .y = chk_lerp(a.y, b.y, t), //
                     .z = chk_lerp(a.z, b.z, t)};
  return result;
}

CHK_CORE_API chk_v4_t chk_v4_lerp(chk_v4_t a, chk_v4_t b, double t) {
  chk_v4_t result = {.x = chk_lerp(a.x, b.x, t), //
                     .y = chk_lerp(a.y, b.y, t), //
                     .z = chk_lerp(a.z, b.z, t), //
                     .w = chk_lerp(a.w, b.w, t)};
  return result;
}

CHK_CORE_API chk_v2_t chk_v2_clamp(chk_v2_t v, double min, double max) {
  chk_v2_t result = {.x = chk_clamp(v.x, min, max), //
                     .y = chk_clamp(v.y, min, max)};
  return result;
}

CHK_CORE_API chk_v3_t chk_v3_clamp(chk_v3_t v, double min, double max) {
  chk_v3_t result = {.x = chk_clamp(v.x, min, max), //
                     .y = chk_clamp(v.y, min, max), //
                     .z = chk_clamp(v.z, min, max)};
  return result;
}

CHK_CORE_API chk_v4_t chk_v4_clamp(chk_v4_t v, double min, double max) {
  chk_v4_t result = {.x = chk_clamp(v.x, min, max), //
                     .y = chk_clamp(v.y, min, max), //
                     .z = chk_clamp(v.z, min, max), //
                     .w = chk_clamp(v.w, min, max)};
  return result;
}

CHK_CORE_API chk_v2_t chk_v2_clamp_vec(chk_v2_t v, chk_v2_t min, chk_v2_t max) {
  chk_v2_t result = {.x = chk_clamp(v.x, min.x, max.x), //
                     .y = chk_clamp(v.y, min.y, max.y)};
  return result;
}

CHK_CORE_API chk_v3_t chk_v3_clamp_vec(chk_v3_t v, chk_v3_t min, chk_v3_t max) {
  chk_v3_t result = {.x = chk_clamp(v.x, min.x, max.x), //
                     .y = chk_clamp(v.y, min.y, max.y), //
                     .z = chk_clamp(v.z, min.z, max.z)};
  return result;
}

CHK_CORE_API chk_v4_t chk_v4_clamp_vec(chk_v4_t v, chk_v4_t min, chk_v4_t max) {
  chk_v4_t result = {.x = chk_clamp(v.x, min.x, max.x), //
                     .y = chk_clamp(v.y, min.y, max.y), //
                     .z = chk_clamp(v.z, min.z, max.z), //
                     .w = chk_clamp(v.w, min.w, max.w)};
  return result;
}

CHK_CORE_API chk_v3_t chk_v3_cross(chk_v3_t a, chk_v3_t b) {
  chk_v3_t result = {.x = a.y * b.z - a.z * b.y, //
                     .y = a.z * b.x - a.x * b.z, //
                     .z = a.x * b.y - a.y * b.x};
  return result;
}
