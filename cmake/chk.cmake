include_guard()

include(GenerateExportHeader)

macro(chk_gen_export)
  cmake_parse_arguments(CHK "" "NAME;PREFIX;BIN_BASE" "" ${ARGN})

  if (NOT CHK_NAME)
    message(FATAL_ERROR "NAME is required")
  endif()
  if (NOT CHK_PREFIX)
    set(CHK_PREFIX "chk")
  endif()
  if (NOT CHK_BIN_BASE)
    set(CHK_BIN_BASE ${CMAKE_CURRENT_BINARY_DIR})
  endif()

  string(TOUPPER ${CHK_PREFIX} CHK_PREFIX_CAPS)
  string(TOUPPER ${CHK_NAME} CHK_NAME_CAPS)
  set(CHK_NAME_PREFIXED "${CHK_PREFIX}_${CHK_NAME}")
  
  file(MAKE_DIRECTORY ${CHK_BIN_BASE}/include/${CHK_PREFIX}/${CHK_NAME}/)

  generate_export_header(${CHK_NAME_PREFIXED}
    EXPORT_FILE_NAME ${CHK_BIN_BASE}/include/${CHK_PREFIX}/${CHK_NAME}/export.h
    EXPORT_MACRO_NAME ${CHK_NAME_CAPS}_API
    NO_EXPORT_MACRO_NAME ${CHK_NAME_CAPS}_LOCAL
    PREFIX_NAME ${CHK_PREFIX_CAPS}_
  )
endmacro(chk_gen_export)

macro(chk_add)
  cmake_parse_arguments(CHK "" "NAME;TYPE;PREFIX;SRC_BASE;BIN_BASE" "HDR;SRC;PUB;PRV" ${ARGN})

  if (NOT CHK_NAME)
    message(FATAL_ERROR "NAME is required")
  endif()
  if (NOT CHK_TYPE)
    message(FATAL_ERROR "TYPE is required")
  endif()
  if (NOT CHK_PREFIX)
    set(CHK_PREFIX "chk")
  endif()
  if (NOT CHK_SRC_BASE)
    set(CHK_SRC_BASE ${CMAKE_CURRENT_SOURCE_DIR})
  endif()
  if (NOT CHK_BIN_BASE)
    set(CHK_BIN_BASE ${CMAKE_CURRENT_BINARY_DIR})
  endif()
  set(CHK_IS_LIB FALSE)
  set(CHK_IS_EXE FALSE)
  if (CHK_TYPE STREQUAL "lib")
    set(CHK_IS_LIB TRUE)
  elseif (CHK_TYPE STREQUAL "exe")
    set(CHK_IS_EXE TRUE)
  else()
    message(FATAL_ERROR "TYPE must be either 'lib' or 'exe'")
  endif()
  if (NOT CHK_PREFIX)
    set(CHK_PREFIX "chk")
  endif()
  if (NOT CHK_HDR AND NOT CHK_SRC)
    message(FATAL_ERROR "At least one of HDR or SRC is required")
  endif()
  if (CHK_HDR AND NOT CHK_SRC)
    message(FATAL_ERROR "SRC is required when HDR is provided")
  endif()

  set(CHK_NAME_PREFIXED "${CHK_PREFIX}_${CHK_NAME}")

  if (CHK_IS_LIB)
    add_library(${CHK_NAME_PREFIXED})
    add_library(${CHK_PREFIX}::${CHK_NAME} ALIAS ${CHK_NAME_PREFIXED})
  elseif (CHK_IS_EXE)
    add_executable(${CHK_NAME_PREFIXED})
  endif()

  list(TRANSFORM CHK_HDR PREPEND ${CHK_SRC_BASE}/include/${CHK_PREFIX}/${CHK_NAME}/)
  list(TRANSFORM CHK_SRC PREPEND ${CHK_SRC_BASE}/src/${CHK_PREFIX}/${CHK_NAME}/)

  if (CHK_IS_LIB)
    chk_gen_export(NAME ${CHK_NAME} PREFIX ${CHK_PREFIX} BIN_BASE ${CHK_BIN_BASE})
    list(APPEND CHK_HDR ${CHK_BIN_BASE}/include/${CHK_PREFIX}/${CHK_NAME}/export.h)
  endif()

  target_sources(${CHK_NAME_PREFIXED}
    PUBLIC 
      FILE_SET ${CHK_NAME_PREFIXED}_headers
      TYPE HEADERS 
      BASE_DIRS 
        ${CHK_SRC_BASE}/include 
        ${CHK_BIN_BASE}/include 
      FILES
        ${CHK_HDR}
    PRIVATE
      ${CHK_SRC}
  )
  target_include_directories(${CHK_NAME_PREFIXED}
    PUBLIC
      $<BUILD_INTERFACE:${CHK_SRC_BASE}/include>
      $<BUILD_INTERFACE:${CHK_BIN_BASE}/include>
      $<INSTALL_INTERFACE:include>
  )
  target_compile_features(${CHK_NAME_PREFIXED} PUBLIC c_std_11)
  if (CHK_PUB)
    target_link_libraries(${CHK_NAME_PREFIXED} PUBLIC ${CHK_PUB})
  endif()
  if (CHK_PRV)
    target_link_libraries(${CHK_NAME_PREFIXED} PRIVATE ${CHK_PRV})
  endif()

  set_target_properties(${CHK_NAME_PREFIXED} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CHK_BIN_BASE}/${CHK_NAME}"
    ARCHIVE_OUTPUT_DIRECTORY "${CHK_BIN_BASE}/${CHK_NAME}"
    RUNTIME_OUTPUT_DIRECTORY "${CHK_BIN_BASE}/${CHK_NAME}"
  )

  if (CHK_IS_EXE AND BUILD_SHARED_LIBS AND WIN32)
    add_custom_target(${CHK_NAME_PREFIXED}_copy_dlls ALL
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:${CHK_NAME_PREFIXED}>
        $<TARGET_FILE_DIR:${CHK_NAME_PREFIXED}>
      DEPENDS ${CHK_NAME_PREFIXED}
      COMMAND_EXPAND_LISTS
    )
  endif()
endmacro(chk_add)
