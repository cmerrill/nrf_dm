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

typedef enum {
    PWM_LED_INDEX_RED,
    PWM_LED_INDEX_GREEN,
    PWM_LED_INDEX_BLUE
} PwmLedIndex;

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
void pwm_led_set_all(uint16_t desired_red, uint16_t desired_green, uint16_t desired_blue);

/** @brief Set the RGB PWM level.
 *
 *  @param index Index of the LED to affect
 *  @param desired_level PWM level
 */
void pwm_led_set_one(PwmLedIndex index, uint16_t desired_level);


#ifdef __cplusplus
}
#endif

#endif /* PWM_LED_H_ */
