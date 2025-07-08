add_library(HARDWARE_FILES STATIC)

set(COMMUNICATION_DIR ${CMAKE_CURRENT_LIST_DIR}/com)
set(CORE_DIR ${CMAKE_CURRENT_LIST_DIR}/core)
set(FLASH_DIR ${CMAKE_CURRENT_LIST_DIR}/flash)

target_include_directories(HARDWARE_FILES PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/com/eth
  ${CMAKE_CURRENT_LIST_DIR}/com

  ${CMAKE_CURRENT_LIST_DIR}/core/assert
  ${CMAKE_CURRENT_LIST_DIR}/core/multicore
  ${CMAKE_CURRENT_LIST_DIR}/core/watchdog
  ${CMAKE_CURRENT_LIST_DIR}/core/reset
  
  ${CMAKE_CURRENT_LIST_DIR}/flash
)

target_link_libraries(HARDWARE_FILES PUBLIC
  PICO_SDK_FILES

  ETHERNET_FILES
  IOLIBRARY_FILES

  TIMER_FILES
  DHCP_FILES
  DNS_FILES

  LOOPBACK_FILES
 
  GRYF_CONFIG
)

target_sources(HARDWARE_FILES PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/com/eth/gEth.c
  ${CMAKE_CURRENT_LIST_DIR}/com/eth/gTcp.c
  ${CMAKE_CURRENT_LIST_DIR}/com/eth/gUdp.c
  ${CMAKE_CURRENT_LIST_DIR}/com/eth/gDhcp.c
  ${CMAKE_CURRENT_LIST_DIR}/com/gUart.c

  ${CMAKE_CURRENT_LIST_DIR}/core/assert/gAssert.c
  ${CMAKE_CURRENT_LIST_DIR}/core/multicore/gMulticore.c
  # ${CMAKE_CURRENT_LIST_DIR}/core/watchog/gWatchdog.c
  ${CMAKE_CURRENT_LIST_DIR}/core/reset/gReset.c

  ${CMAKE_CURRENT_LIST_DIR}/flash/gFlash.c
)
