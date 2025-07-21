include(${CMAKE_CURRENT_LIST_DIR}/AT-Commands-Lib/at-commands-lib.cmake)

add_library(ABSTRACT_FILES STATIC)

target_include_directories(ABSTRACT_FILES PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/command_builder
  ${CMAKE_CURRENT_LIST_DIR}/analyse
)

target_link_libraries(ABSTRACT_FILES PUBLIC
  AT_commands_lib 

  GRYF_CONFIG
)

target_sources(ABSTRACT_FILES PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/command_builder/gCommand_builder.c
  ${CMAKE_CURRENT_LIST_DIR}/analyse/analyse.c
)
