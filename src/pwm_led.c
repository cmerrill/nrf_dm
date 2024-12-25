/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include "pwm_led.h"
#include <nrfx.h>
#include <nrfx_gpiote.h>
#include <zephyr/drivers/pwm.h>

#define PWM_LED0_NODE	DT_ALIAS(pwm_led0)
#define PWM_LED1_NODE	DT_ALIAS(pwm_led1)
#define PWM_LED2_NODE	DT_ALIAS(pwm_led2)

static const struct pwm_dt_spec led_red = PWM_DT_SPEC_GET(PWM_LED0_NODE);
static const struct pwm_dt_spec led_green = PWM_DT_SPEC_GET(PWM_LED1_NODE);
static const struct pwm_dt_spec led_blue = PWM_DT_SPEC_GET(PWM_LED2_NODE);
static const struct pwm_dt_spec* led_array[] = {&led_red, &led_green, &led_blue};

#define PWM_PERIOD	1024
#define LIGHTNESS_MAX	UINT16_MAX

int pwm_led_init(void)
{
	if (!device_is_ready(led_red.dev) && !device_is_ready(led_green.dev) 
			&& !device_is_ready(led_blue.dev)) {
		return -1;
	}

	return 0;
}

void pwm_led_set_one(PwmLedIndex index, uint16_t desired_level)
{
	if (index < (sizeof(led_array)/sizeof(led_array[0]))) {
		uint32_t scaled_level = (PWM_PERIOD * desired_level) / LIGHTNESS_MAX;
		pwm_set_dt(led_array[index], PWM_USEC(PWM_PERIOD), PWM_USEC(scaled_level));
	}
}

void pwm_led_set_all(uint16_t desired_red, uint16_t desired_green, uint16_t desired_blue)
{
	pwm_led_set_one(PWM_LED_INDEX_RED, desired_red);
	pwm_led_set_one(PWM_LED_INDEX_GREEN, desired_green);
	pwm_led_set_one(PWM_LED_INDEX_BLUE, desired_blue);
}
