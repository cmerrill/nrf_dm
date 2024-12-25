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


add_custom_target(force_merged_hex ALL)
cmake_language(DEFER DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} CALL add_dependencies force_merged_hex app)
cmake_language(DEFER DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} CALL set_target_properties force_merged_hex PROPERTIES ADDITIONAL_CLEAN_FILES "${CMAKE_BINARY_DIR}/../merged.hex")

zephyr_library_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
