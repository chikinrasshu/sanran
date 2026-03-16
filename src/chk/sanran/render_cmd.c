#include <chk/sanran/render_cmd.h>

#include <chk/core/log.h>

CHK_SANRAN_API const char* chk_render_cmd_type_to_str(chk_render_cmd_type_t type) {
  const char* name = "UNK";
  switch (type) {
    case CHK_RENDER_CMD_NONE:
    case CHK_RENDER_CMD_COUNT: break;

    case CHK_RENDER_CMD_CLEAR: name = "Clear"; break;

    case CHK_RENDER_CMD_POINT:    name = "Point"; break;
    case CHK_RENDER_CMD_LINE:     name = "Line"; break;
    case CHK_RENDER_CMD_TRIANGLE: name = "Triangle"; break;
    case CHK_RENDER_CMD_RECT:     name = "Rect"; break;
    case CHK_RENDER_CMD_CIRCLE:   name = "Circle"; break;
    case CHK_RENDER_CMD_POLYGON:  name = "Polygon"; break;

    case CHK_RENDER_CMD_SPRITE:     name = "Sprite"; break;
    case CHK_RENDER_CMD_SPRITE_3X3: name = "Sprite3x3"; break;

    case CHK_RENDER_CMD_TEXT: name = "Text"; break;
  }

  return name;
}

CHK_SANRAN_API size_t chk_render_cmd_size(chk_render_cmd_type_t type) {
  size_t size = 0;

  switch (type) {
    case CHK_RENDER_CMD_NONE:
    case CHK_RENDER_CMD_COUNT: break;

    case CHK_RENDER_CMD_CLEAR: size = sizeof(chk_render_cmd_clear_t); break;

    case CHK_RENDER_CMD_POINT:    size = sizeof(chk_render_cmd_point_t); break;
    case CHK_RENDER_CMD_LINE:     size = sizeof(chk_render_cmd_line_t); break;
    case CHK_RENDER_CMD_TRIANGLE: size = sizeof(chk_render_cmd_triangle_t); break;
    case CHK_RENDER_CMD_RECT:     size = sizeof(chk_render_cmd_rect_t); break;
    case CHK_RENDER_CMD_CIRCLE:   size = sizeof(chk_render_cmd_circle_t); break;
    case CHK_RENDER_CMD_POLYGON:  size = sizeof(chk_render_cmd_polygon_t); break;

    case CHK_RENDER_CMD_SPRITE:     size = sizeof(chk_render_cmd_sprite_t); break;
    case CHK_RENDER_CMD_SPRITE_3X3: size = sizeof(chk_render_cmd_sprite_3x3_t); break;

    case CHK_RENDER_CMD_TEXT: size = sizeof(chk_render_cmd_text_t); break;
  }

  if (size == 0) { chk_log_warn("Unknown render command type: %d", type); }

  return size;
}
