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

void pwm_led_set(uint16_t desired_red, uint16_t desired_green, uint16_t desired_blue)
{
	uint32_t scaled_red = (PWM_PERIOD * desired_red) / LIGHTNESS_MAX;
	uint32_t scaled_green = (PWM_PERIOD * desired_green) / LIGHTNESS_MAX;
	uint32_t scaled_blue = (PWM_PERIOD * desired_blue) / LIGHTNESS_MAX;

	pwm_set_dt(&led_red, PWM_USEC(PWM_PERIOD), PWM_USEC(scaled_red));
	pwm_set_dt(&led_green, PWM_USEC(PWM_PERIOD), PWM_USEC(scaled_green));
	pwm_set_dt(&led_blue, PWM_USEC(PWM_PERIOD), PWM_USEC(scaled_blue));
}
