/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2012-2012 Henrik Nordstrom <henrik@henriknordstrom.net>
 *
 * (C) Copyright 2007-2011
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Tom Cubie <tangliang@allwinnertech.com>
 *
 * Configuration settings for the Allwinner sunxi series of boards.
 */

#ifndef _SUNXI_COMMON_CONFIG_H
#define _SUNXI_COMMON_CONFIG_H

#include <linux/stringify.h>

/****************************************************************************
 *                  base addresses for the SPL UART driver                  *
 ****************************************************************************/
#ifdef CONFIG_MACH_SUNIV
/* suniv doesn't have apb2 and uart is connected to apb1 */
#define CFG_SYS_NS16550_CLK		100000000
#else
#define CFG_SYS_NS16550_CLK		24000000
#endif
#if !CONFIG_IS_ENABLED(DM_SERIAL)
#include <asm/arch/serial.h>
# define CFG_SYS_NS16550_COM1		SUNXI_UART0_BASE
# define CFG_SYS_NS16550_COM2		SUNXI_UART1_BASE
# define CFG_SYS_NS16550_COM3		SUNXI_UART2_BASE
# define CFG_SYS_NS16550_COM4		SUNXI_UART3_BASE
# define CFG_SYS_NS16550_COM5		SUNXI_R_UART_BASE
#endif

/****************************************************************************
 *                             DRAM base address                            *
 ****************************************************************************/
/*
 * The DRAM Base differs between some models. We cannot use macros for the
 * CONFIG_FOO defines which contain the DRAM base address since they end
 * up unexpanded in include/autoconf.mk .
 *
 * So we have to have this #ifdef #else #endif block for these.
 */
#ifdef CONFIG_MACH_SUN9I
#define SDRAM_OFFSET(x) 0x2##x
#define CFG_SYS_SDRAM_BASE		0x20000000
#elif defined(CONFIG_MACH_SUNIV)
#define SDRAM_OFFSET(x) 0x8##x
#define CFG_SYS_SDRAM_BASE		0x80000000
#else
#define SDRAM_OFFSET(x) 0x4##x
#define CFG_SYS_SDRAM_BASE		0x40000000
/* V3s do not have enough memory to place code at 0x4a000000 */
#endif

#define CFG_SYS_INIT_RAM_ADDR	CONFIG_SUNXI_SRAM_ADDRESS
/* FIXME: this may be larger on some SoCs */
#define CFG_SYS_INIT_RAM_SIZE	0x8000 /* 32 KiB */

#define PHYS_SDRAM_0			CFG_SYS_SDRAM_BASE
#define PHYS_SDRAM_0_SIZE		0x80000000 /* 2 GiB */

/****************************************************************************
 *           environment variables holding default load addresses           *
 ****************************************************************************/
#undef CONFIG_BOOTARGS
#define CONFIG_BOOTARGS "console=ttyS0,115200 panic=20 root=/dev/mtdblock3 init=/init mtdparts=spi0.0:256k(boot),64k(env),2048k(kernel),\\${rootmtd}(rootfs),-(rootfs_data)"
#define CONFIG_BOOTCOMMAND "setenv bootcmd ${cmdnor}; sf probe 0; saveenv; run bootcmd"

#define CONFIG_ENV_KERNADDR 0x50000
#define CONFIG_ENV_KERNSIZE 0x200000
#define CONFIG_ENV_ROOTADDR 0x250000
#define CONFIG_ENV_ROOTSIZE 0x500000

#define CFG_EXTRA_ENV_SETTINGS \
	"baseaddr=" __stringify(CONFIG_SYS_LOAD_ADDR) "\0" \
	"kernaddr=" __stringify(CONFIG_ENV_KERNADDR) "\0" \
	"kernsize=" __stringify(CONFIG_ENV_KERNSIZE) "\0" \
	"rootaddr=" __stringify(CONFIG_ENV_ROOTADDR) "\0" \
	"rootsize=" __stringify(CONFIG_ENV_ROOTSIZE) "\0" \
	"rootmtd=5120k\0" \
	"cmdnor=sf probe 0; setenv setargs setenv bootargs ${bootargs}; run setargs; sf read ${baseaddr} ${kernaddr} ${kernsize}; bootm ${baseaddr}\0" \
	"ubnor=${device} ${baseaddr} u-boot-${soc}-nor.bin && run ubwrite\0" \
	"uknor=${device} ${baseaddr} uImage.${soc} && run ukwrite\0" \
	"urnor=${device} ${baseaddr} rootfs.squashfs.${soc} && run urwrite\0" \
	"ubwrite=sf probe 0; sf erase 0x0 ${kernaddr}; sf write ${baseaddr} 0x0 ${kernaddr}\0" \
	"ukwrite=sf probe 0; sf erase ${kernaddr} ${kernsize}; sf write ${baseaddr} ${kernaddr} ${filesize}\0" \
	"urwrite=sf probe 0; sf erase ${rootaddr} ${rootsize}; sf write ${baseaddr} ${rootaddr} ${filesize}\0" \
	"device=fatload mmc 0\0" \
	"soc=" __stringify(PRODUCT_SOC)

#endif
