cmake_minimum_required(VERSION 3.30)
project(chk_sanran LANGUAGES C VERSION 0.1.0)

include(cmake/chk.cmake)

# Dependencies

include(FetchContent)

FetchContent_Declare(glfw 
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG fdd14e65b1c29e4e6df875fb5669ec00d6793531 # Mar 6, 2026
)

FetchContent_Declare(glad_gen 
  GIT_REPOSITORY https://github.com/Dav1dde/glad.git
  GIT_TAG a4ca574522ff69d0bb584584977aa9a53ace29d9 # Jan 31, 2026
  SOURCE_SUBDIR cmake
)

FetchContent_MakeAvailable(glfw glad_gen)

glad_add_library(glad_gl REPRODUCIBLE API gl:core=4.1)

add_library(glfw::glfw ALIAS glfw)
add_library(glad::gl ALIAS glad_gl)

# Core library

chk_add(NAME core TYPE lib
  HDR 
    "core.h"
    "log.h"
    "math.h"
    "vec.h"
  SRC
    "core.c"
    "log.c"
    "math.c"
    "vec.c"
)

# Sanran library

chk_add(NAME sanran TYPE lib
  HDR 
    "render_cmd.h"
    "render_list.h"
    "sanran.h"
    "window.h"
  SRC
    "render_cmd.c"
    "render_list.c"
    "sanran.c"
    "window.c"
  PUB
    chk::core
  PRV
    glfw::glfw
    glad::gl
)

# Launcher executable

chk_add(NAME launcher TYPE exe
  SRC
    "main.c"
  PUB
    chk::core
    chk::sanran
)
