/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef PWM_LED_H_
#define PWM_LED_H_

#include <zephyr/kernel.h>
#include <stdlib.h>
#include <zephyr/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Initialize the PWM LED.
 *
 *  @param None
 *
 *  @retval 0 if the operation was successful, otherwise a (negative) error code.
 */
int pwm_led_init(void);

/** @brief Set the RGB PWM level.
 *
 *  @param desired_red Red Value.
 *  @param desired_green Green Value.
 *  @param desired_blue Blue Value.
 */
void pwm_led_set(uint16_t desired_red, uint16_t desired_green, uint16_t desired_blue);

#ifdef __cplusplus
}
#endif

#endif /* PWM_LED_H_ */
