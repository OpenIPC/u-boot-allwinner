#!/bin/sh
export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabi-

rm -rf output
mkdir -p output

for soc in v851s; do
	make ${soc}_defconfig
	make -j8 KCFLAGS=-DPRODUCT_SOC=${soc}
	mv u-boot-sunxi-with-spl.bin output/u-boot-${soc}-nor.bin
done
