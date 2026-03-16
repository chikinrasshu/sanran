#pragma once

#include <chk/sanran/export.h>

#include <chk/core/core.h>

typedef enum chk_render_cmd_type {
  CHK_RENDER_CMD_NONE = 0,

  CHK_RENDER_CMD_CLEAR,

  CHK_RENDER_CMD_POINT,
  CHK_RENDER_CMD_LINE,
  CHK_RENDER_CMD_TRIANGLE,
  CHK_RENDER_CMD_RECT,
  CHK_RENDER_CMD_CIRCLE,
  CHK_RENDER_CMD_POLYGON,

  CHK_RENDER_CMD_SPRITE,
  CHK_RENDER_CMD_SPRITE_3X3,

  CHK_RENDER_CMD_TEXT,

  CHK_RENDER_CMD_COUNT,
} chk_render_cmd_type_t;

CHK_SANRAN_API const char* chk_render_cmd_type_to_str(chk_render_cmd_type_t type);

typedef struct chk_render_cmd_clear {
  float r, g, b, a;
} chk_render_cmd_clear_t;

typedef struct chk_render_cmd_point {
  float  r, g, b, a;
  double x, y;
} chk_render_cmd_point_t;

typedef struct chk_render_cmd_line {
  float  r, g, b, a;
  double x1, y1;
  double x2, y2;
} chk_render_cmd_line_t;

typedef struct chk_render_cmd_triangle {
  float  r, g, b, a;
  double x1, y1;
  double x2, y2;
  double x3, y3;
} chk_render_cmd_triangle_t;

typedef struct chk_render_cmd_rect {
  float  r, g, b, a;
  double x, y;
  double w, h;
} chk_render_cmd_rect_t;

typedef struct chk_render_cmd_circle {
  float  r, g, b, a;
  double x, y;
  double radius;
} chk_render_cmd_circle_t;

typedef struct chk_render_cmd_polygon {
  float   r, g, b, a;
  double* points; // [x1, y1, x2, y2, ...]
  size_t  count;  // number of points (not number of vertices)
} chk_render_cmd_polygon_t;

typedef struct chk_render_cmd_sprite {
  float  r, g, b, a;
  double x, y;
  double w, h;

  const void* texture;
} chk_render_cmd_sprite_t;

typedef struct chk_render_cmd_sprite_3x3 {
  chk_render_cmd_sprite_t sprite;

  double l, r, t, b;
} chk_render_cmd_sprite_3x3_t;

typedef struct chk_render_cmd_text {
  float  r, g, b, a;
  double x, y;

  const char* text;
  const void* font;
} chk_render_cmd_text_t;

typedef struct chk_render_cmd {
  chk_render_cmd_type_t type;
  union {
    chk_render_cmd_clear_t      clear;
    chk_render_cmd_point_t      point;
    chk_render_cmd_line_t       line;
    chk_render_cmd_triangle_t   triangle;
    chk_render_cmd_rect_t       rect;
    chk_render_cmd_circle_t     circle;
    chk_render_cmd_polygon_t    polygon;
    chk_render_cmd_sprite_t     sprite;
    chk_render_cmd_sprite_3x3_t sprite_3x3;
    chk_render_cmd_text_t       text;
  };
} chk_render_cmd_t;

CHK_SANRAN_API size_t chk_render_cmd_size(chk_render_cmd_type_t type);
