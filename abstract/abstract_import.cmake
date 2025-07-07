add_library(ABSTRACT_FILES STATIC)

target_include_directories(ABSTRACT_FILES PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(ABSTRACT_FILES PRIVATE
)

target_sources(ABSTRACT_FILES PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/parser/parser.c
)
