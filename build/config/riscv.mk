CONFIG_TOOLCHAIN?=llvm
CONFIG_ARCH?=riscv64
CONFIG_BOOTLOADER?=kernel
CONFIG_HOST_ARCH?=$(shell uname -m)
CONFIG_BOARD?=virt
