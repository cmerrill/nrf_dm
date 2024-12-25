#
# Copyright (c) 2021 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#
cmake_minimum_required(VERSION 3.20)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(nrf_dm)

# NORDIC SDK APP START
target_sources(app PRIVATE
  src/main.c
  src/pwm_led.c
  src/peer.c
  src/service.c
  )
# NORDIC SDK APP END

add_custom_target(ensure_merged_hex ALL
    COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_BINARY_DIR}/merged.hex
)

message(STATUS "Kernel Hex File Name: ${BYPRODUCT_KERNEL_HEX_NAME}")
message(STATUS "Merged Hex File Name: ${CMAKE_BINARY_DIR}/merged.hex")

zephyr_library_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
