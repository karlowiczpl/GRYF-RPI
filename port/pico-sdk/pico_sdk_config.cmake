include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

add_library(PICO_SDK_FILES STATIC)

target_link_libraries(PICO_SDK_FILES PUBLIC
  pico_stdlib
  pico_multicore

  pico_bootsel_via_double_reset

  hardware_flash
)
