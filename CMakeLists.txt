cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(LIBRARY_DIR ${CMAKE_CURRENT_LIST_DIR}/lib)

include(${CMAKE_SOURCE_DIR}/port/pico-sdk/pico_sdk_config.cmake)
include(${CMAKE_SOURCE_DIR}/port/mbedtls/mbedtls_config.cmake)
include(${CMAKE_SOURCE_DIR}/port/ioLibrary_Driver/wiznet_config.cmake)
include(${CMAKE_SOURCE_DIR}/hardware/hardware_import.cmake)
include(${CMAKE_SOURCE_DIR}/abstract/abstract_import.cmake)

project(GRYF_RPI C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${PROJECT_NAME}
  src/main.c
)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 1)
pico_add_extra_outputs(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC
  PICO_SDK_FILES

  HARDWARE_FILES
)
