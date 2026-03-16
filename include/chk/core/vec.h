#pragma once

#include <chk/core/export.h>

#include <chk/core/core.h>

typedef union chk_v2 {
  struct {
    double x, y;
  };
  struct {
    double w, h;
  };
  struct {
    double u, v;
  };
  double _raw[2];
} chk_v2_t;

typedef union chk_v3 {
  struct {
    double x, y, z;
  };
  struct {
    chk_v2_t xy;
    double   _2;
  };
  struct {
    double   _3;
    chk_v2_t yz;
  };
  double _raw[3];
} chk_v3_t;

typedef union chk_v4 {
  struct {
    double x, y, z, w;
  };
  struct {
    chk_v3_t xyz;
    double   _0;
  };
  struct {
    double   _1;
    chk_v3_t yzw;
  };
  struct {
    chk_v2_t xy;
    chk_v2_t zw;
  };
  struct {
    double   _2;
    chk_v2_t yz;
    double   _3;
  };
  struct {
    chk_v2_t pos;
    chk_v2_t size;
  };
  double _raw[4];
} chk_v4_t;

CHK_CORE_API chk_v2_t chk_v2_make(double x, double y);
CHK_CORE_API chk_v3_t chk_v3_make(double x, double y, double z);
CHK_CORE_API chk_v4_t chk_v4_make(double x, double y, double z, double w);

CHK_CORE_API chk_v2_t chk_v2_zero(void);
CHK_CORE_API chk_v3_t chk_v3_zero(void);
CHK_CORE_API chk_v4_t chk_v4_zero(void);

CHK_CORE_API chk_v2_t chk_v2_one(void);
CHK_CORE_API chk_v3_t chk_v3_one(void);
CHK_CORE_API chk_v4_t chk_v4_one(void);

CHK_CORE_API chk_v2_t chk_v2_add(chk_v2_t a, chk_v2_t b);
CHK_CORE_API chk_v3_t chk_v3_add(chk_v3_t a, chk_v3_t b);
CHK_CORE_API chk_v4_t chk_v4_add(chk_v4_t a, chk_v4_t b);

CHK_CORE_API chk_v2_t chk_v2_sub(chk_v2_t a, chk_v2_t b);
CHK_CORE_API chk_v3_t chk_v3_sub(chk_v3_t a, chk_v3_t b);
CHK_CORE_API chk_v4_t chk_v4_sub(chk_v4_t a, chk_v4_t b);

CHK_CORE_API chk_v2_t chk_v2_hadamard(chk_v2_t a, chk_v2_t b);
CHK_CORE_API chk_v3_t chk_v3_hadamard(chk_v3_t a, chk_v3_t b);
CHK_CORE_API chk_v4_t chk_v4_hadamard(chk_v4_t a, chk_v4_t b);

CHK_CORE_API chk_v2_t chk_v2_scale(chk_v2_t v, double s);
CHK_CORE_API chk_v3_t chk_v3_scale(chk_v3_t v, double s);
CHK_CORE_API chk_v4_t chk_v4_scale(chk_v4_t v, double s);

CHK_CORE_API chk_v2_t chk_v2_scale_left(double s, chk_v2_t v);
CHK_CORE_API chk_v3_t chk_v3_scale_left(double s, chk_v3_t v);
CHK_CORE_API chk_v4_t chk_v4_scale_left(double s, chk_v4_t v);

CHK_CORE_API chk_v2_t chk_v2_div(chk_v2_t a, double d);
CHK_CORE_API chk_v3_t chk_v3_div(chk_v3_t a, double d);
CHK_CORE_API chk_v4_t chk_v4_div(chk_v4_t a, double d);

CHK_CORE_API chk_v2_t chk_v2_div_left(double d, chk_v2_t a);
CHK_CORE_API chk_v3_t chk_v3_div_left(double d, chk_v3_t a);
CHK_CORE_API chk_v4_t chk_v4_div_left(double d, chk_v4_t a);

CHK_CORE_API double chk_v2_dot(chk_v2_t a, chk_v2_t b);
CHK_CORE_API double chk_v3_dot(chk_v3_t a, chk_v3_t b);
CHK_CORE_API double chk_v4_dot(chk_v4_t a, chk_v4_t b);

CHK_CORE_API double chk_v2_length_sq(chk_v2_t v);
CHK_CORE_API double chk_v3_length_sq(chk_v3_t v);
CHK_CORE_API double chk_v4_length_sq(chk_v4_t v);

CHK_CORE_API double chk_v2_length(chk_v2_t v);
CHK_CORE_API double chk_v3_length(chk_v3_t v);
CHK_CORE_API double chk_v4_length(chk_v4_t v);

CHK_CORE_API double chk_v2_distance_sq(chk_v2_t a, chk_v2_t b);
CHK_CORE_API double chk_v3_distance_sq(chk_v3_t a, chk_v3_t b);
CHK_CORE_API double chk_v4_distance_sq(chk_v4_t a, chk_v4_t b);

CHK_CORE_API double chk_v2_distance(chk_v2_t a, chk_v2_t b);
CHK_CORE_API double chk_v3_distance(chk_v3_t a, chk_v3_t b);
CHK_CORE_API double chk_v4_distance(chk_v4_t a, chk_v4_t b);

CHK_CORE_API chk_v2_t chk_v2_normalize(chk_v2_t v);
CHK_CORE_API chk_v3_t chk_v3_normalize(chk_v3_t v);
CHK_CORE_API chk_v4_t chk_v4_normalize(chk_v4_t v);

CHK_CORE_API chk_v2_t chk_v2_lerp(chk_v2_t a, chk_v2_t b, double t);
CHK_CORE_API chk_v3_t chk_v3_lerp(chk_v3_t a, chk_v3_t b, double t);
CHK_CORE_API chk_v4_t chk_v4_lerp(chk_v4_t a, chk_v4_t b, double t);

CHK_CORE_API chk_v2_t chk_v2_clamp(chk_v2_t v, double min, double max);
CHK_CORE_API chk_v3_t chk_v3_clamp(chk_v3_t v, double min, double max);
CHK_CORE_API chk_v4_t chk_v4_clamp(chk_v4_t v, double min, double max);

CHK_CORE_API chk_v2_t chk_v2_clamp_vec(chk_v2_t v, chk_v2_t min, chk_v2_t max);
CHK_CORE_API chk_v3_t chk_v3_clamp_vec(chk_v3_t v, chk_v3_t min, chk_v3_t max);
CHK_CORE_API chk_v4_t chk_v4_clamp_vec(chk_v4_t v, chk_v4_t min, chk_v4_t max);

CHK_CORE_API chk_v3_t chk_v3_cross(chk_v3_t a, chk_v3_t b);
