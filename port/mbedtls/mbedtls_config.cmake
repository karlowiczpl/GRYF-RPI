set(PORT_DIR ${CMAKE_SOURCE_DIR}/port)

set(ENABLE_PROGRAMS OFF CACHE BOOL "Build mbedtls programs")
set(ENABLE_TESTING OFF CACHE BOOL "Build mbedtls testing")

set(WIZNET_CHIP W5500)
add_definitions(
    -D_WIZCHIP_=${WIZNET_CHIP}
    -DDEVICE_BOARD_NAME=${BOARD_NAME}
)
add_definitions(
    -DMBEDTLS_CONFIG_FILE="${PORT_DIR}/mbedtls/ssl_config.h"
    -DSET_TRUSTED_CERT_IN_SAMPLES
)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/mbedtls)

target_sources(mbedtls PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/ssl_config.h
)
