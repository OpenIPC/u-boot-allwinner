/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2016 Chen-Yu Tsai <wens@csie.org>
 *
 * X-Powers AXP809 Power Management IC driver
 */

#define AXP809_CHIP_ID		0x03

#define AXP809_OUTPUT_CTRL1	0x10
#define AXP809_OUTPUT_CTRL1_DC5LDO_EN	(1 << 0)
#define AXP809_OUTPUT_CTRL1_DCDC1_EN	(1 << 1)
#define AXP809_OUTPUT_CTRL1_DCDC2_EN	(1 << 2)
#define AXP809_OUTPUT_CTRL1_DCDC3_EN	(1 << 3)
#define AXP809_OUTPUT_CTRL1_DCDC4_EN	(1 << 4)
#define AXP809_OUTPUT_CTRL1_DCDC5_EN	(1 << 5)
#define AXP809_OUTPUT_CTRL1_ALDO1_EN	(1 << 6)
#define AXP809_OUTPUT_CTRL1_ALDO2_EN	(1 << 7)
#define AXP809_OUTPUT_CTRL2	0x12
#define AXP809_OUTPUT_CTRL2_ELDO1_EN	(1 << 0)
#define AXP809_OUTPUT_CTRL2_ELDO2_EN	(1 << 1)
#define AXP809_OUTPUT_CTRL2_ELDO3_EN	(1 << 2)
#define AXP809_OUTPUT_CTRL2_DLDO1_EN	(1 << 3)
#define AXP809_OUTPUT_CTRL2_DLDO2_EN	(1 << 4)
#define AXP809_OUTPUT_CTRL2_ALDO3_EN	(1 << 5)
#define AXP809_OUTPUT_CTRL2_SWOUT_EN	(1 << 6)
#define AXP809_OUTPUT_CTRL2_DC1SW_EN	(1 << 7)

#define AXP809_DLDO1_CTRL	0x15
#define AXP809_DLDO2_CTRL	0x16
#define AXP809_ELDO1_CTRL	0x19
#define AXP809_ELDO2_CTRL	0x1a
#define AXP809_ELDO3_CTRL	0x1b
#define AXP809_DC5LDO_CTRL	0x1c
#define AXP809_DCDC1_CTRL	0x21
#define AXP809_DCDC2_CTRL	0x22
#define AXP809_DCDC3_CTRL	0x23
#define AXP809_DCDC4_CTRL	0x24
#define AXP809_DCDC5_CTRL	0x25
#define AXP809_ALDO1_CTRL	0x28
#define AXP809_ALDO2_CTRL	0x29
#define AXP809_ALDO3_CTRL	0x2a
#define AXP809_SHUTDOWN		0x32
#define AXP809_SHUTDOWN_POWEROFF	(1 << 7)

/* For axp_gpio.c */
#ifdef CONFIG_AXP809_POWER
#define AXP_POWER_STATUS		0x00
#define AXP_POWER_STATUS_ALDO_IN		BIT(0)
#define AXP_VBUS_IPSOUT			0x30
#define AXP_VBUS_IPSOUT_DRIVEBUS		(1 << 2)
#define AXP_MISC_CTRL			0x8f
#define AXP_MISC_CTRL_N_VBUSEN_FUNC		(1 << 4)
#define AXP_GPIO0_CTRL			0x90
#define AXP_GPIO1_CTRL			0x92
#define AXP_GPIO_CTRL_OUTPUT_LOW	0x00 /* Drive pin low */
#define AXP_GPIO_CTRL_OUTPUT_HIGH	0x01 /* Drive pin high */
#define AXP_GPIO_CTRL_INPUT		0x02 /* Input */
#define AXP_GPIO_STATE			0x94
#define AXP_GPIO_STATE_OFFSET		0
#endif
