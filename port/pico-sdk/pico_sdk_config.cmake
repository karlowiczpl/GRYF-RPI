include(${CMAKE_SOURCE_DIR}/lib/pico-sdk/external/pico_sdk_import.cmake)

add_library(PICO_SDK_FILES STATIC)

target_link_libraries(PICO_SDK_FILES PUBLIC
  pico_stdlib

  hardware_flash
)
