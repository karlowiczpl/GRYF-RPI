project(TESTS)
cmake_minimum_required(VERSION 3.16)

pico_sdk_init()

add_executable(TESTS
  ${CMAKE_CURRENT_LIST_DIR}/test_runner.c
)

target_link_libraries(TESTS
  pico_stdlib

  ABSTRACT_FILES
)
