add_library(ABSTRACT_FILES STATIC)

target_include_directories(ABSTRACT_FILES PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/command_builder
)

target_link_libraries(ABSTRACT_FILES PUBLIC
  GRYF_CONFIG
)

target_sources(ABSTRACT_FILES PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/parser/parser.c
  ${CMAKE_CURRENT_LIST_DIR}/command_builder/gCommand_builder.c
)
