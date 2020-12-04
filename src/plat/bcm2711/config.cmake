#
# Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
#
# SPDX-License-Identifier: GPL-2.0-only
#

cmake_minimum_required(VERSION 3.7.2)

declare_platform(bcm2711 KernelPlatformRpi4 PLAT_BCM2711 KernelArchARM)

if(KernelPlatformRpi4)
    if("${KernelSel4Arch}" STREQUAL aarch32)
        declare_seL4_arch(aarch32)
    elseif("${KernelSel4Arch}" STREQUAL aarch64)
        declare_seL4_arch(aarch64)
    else()
        fallback_declare_seL4_arch_default(aarch32)
    endif()
    set(KernelArmCortexA72 ON)
    #set(KernelArmCortexA53 ON)
    set(KernelArchArmV8a ON)
    config_set(KernelARMPlatform ARM_PLAT rpi4)
    #config_set(KernelL1CacheLineSizeBits L1_CACHE_LINE_SIZE_BITS 6)
    set(KernelArmMachFeatureModifiers "+crc" CACHE INTERNAL "")
    list(APPEND KernelDTSList "tools/dts/rpi4.dts")
    list(APPEND KernelDTSList "src/plat/bcm2711/overlay-rpi4.dts")

    declare_default_headers(
        TIMER_FREQUENCY 54000000llu
        MAX_IRQ 216
        NUM_PPI 32
        TIMER drivers/timer/arm_generic.h
        INTERRUPT_CONTROLLER arch/machine/gic_v2.h
        KERNEL_WCET 10u
        CLK_MAGIC 5337599559llu 
        CLK_SHIFT 58u
    )
endif()

add_sources(
    DEP "KernelPlatformRpi4"
    CFILES src/arch/arm/machine/gic_v2.c src/arch/arm/machine/l2c_nop.c
)
