/*
 * Copyright 2017, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(DATA61_GPL)
 */

#ifndef __PLAT_MACHINE_H
#define __PLAT_MACHINE_H
#include <plat/machine/devices.h>
#include <machine/io.h>

#define N_INTERRUPTS     216

#define BASIC_IRQ_OFFSET                64
#define NORMAL_IRQ_OFFSET               (BASIC_IRQ_OFFSET + 32) //96

#define MAX_IRQ (216)
enum IRQConstants {
    INTERRUPT_CORE_CNTPSIRQ                  =  0,
    INTERRUPT_CORE_CNTPNSIRQ                 =  1,
    INTERRUPT_CORE_CNTHPIRQ                  =  2,
    INTERRUPT_CORE_CNTVIRQ                   =  3,
    INTERRUPT_CORE_MAILBOX_0                 =  4,
    INTERRUPT_CORE_MAILBOX_1                 =  5,
    INTERRUPT_CORE_MAILBOX_2                 =  6,
    INTERRUPT_CORE_MAILBOX_3                 =  7,
    INTERRUPT_CORE_GPU                       =  8,
    INTERRUPT_CORE_PMU                       =  9,
    INTERRUPT_CORE_AXI                       = 10,
    INTERRUPT_CORE_LOCAL_TIMER               = 11,
    //17:12 Peripheral 1..15 interrupt (Currently not used)
    //31:28 <Reserved>

    INTERRUPT_BASIC_IRQ_ARM_TIMER            =  (BASIC_IRQ_OFFSET + 0),
    INTERRUPT_BASIC_IRQ_ARM_MAILBOX          =  (BASIC_IRQ_OFFSET + 1),
    INTERRUPT_BASIC_IRQ_ARM_DOORBELL0        =  (BASIC_IRQ_OFFSET + 2),
    INTERRUPT_BASIC_IRQ_ARM_DOORBELL1        =  (BASIC_IRQ_OFFSET + 3),
    INTERRUPT_BASIC_IRQ_GPU0_HALTED          =  (BASIC_IRQ_OFFSET + 4),
    INTERRUPT_BASIC_IRQ_GPU1_HALTED          =  (BASIC_IRQ_OFFSET + 5),
    INTERRUPT_BASIC_IRQ_ILLEGAL_ACCESS_TYPE1 =  (BASIC_IRQ_OFFSET + 6),
    INTERRUPT_BASIC_IRQ_ILLEGAL_ACCESS_TYPE0 =  (BASIC_IRQ_OFFSET + 7),
    INTERRUPT_BASIC_IRQ_PENDING_REGISTER1    =  (BASIC_IRQ_OFFSET + 8),
    INTERRUPT_BASIC_IRQ_PENDING_REGISTER2    =  (BASIC_IRQ_OFFSET + 9),
    INTERRUPT_BASIC_IRQ_GPU_IRQ_7            = (BASIC_IRQ_OFFSET + 10),
    INTERRUPT_BASIC_IRQ_GPU_IRQ_9            = (BASIC_IRQ_OFFSET + 11),
    INTERRUPT_BASIC_IRQ_GPU_IRQ_10           = (BASIC_IRQ_OFFSET + 12),
    INTERRUPT_BASIC_IRQ_GPU_IRQ_18           = (BASIC_IRQ_OFFSET + 13),
    INTERRUPT_BASIC_IRQ_GPU_IRQ_19           = (BASIC_IRQ_OFFSET + 14),
    INTERRUPT_BASIC_IRQ_GPU_IRQ_53           = (BASIC_IRQ_OFFSET + 15),
    INTERRUPT_BASIC_IRQ_GPU_IRQ_54           = (BASIC_IRQ_OFFSET + 16),
    INTERRUPT_BASIC_IRQ_GPU_IRQ_55           = (BASIC_IRQ_OFFSET + 17),
    INTERRUPT_BASIC_IRQ_GPU_IRQ_56           = (BASIC_IRQ_OFFSET + 18),
    INTERRUPT_BASIC_IRQ_GPU_IRQ_57           = (BASIC_IRQ_OFFSET + 19),
    INTERRUPT_BASIC_IRQ_GPU_IRQ_62           = (BASIC_IRQ_OFFSET + 20),
    // 31:21 <unused>

    INTERRUPT_IRQ_AUX                        = (NORMAL_IRQ_OFFSET + 29),
    INTERRUPT_IRQ_I2C_SPI_SLV                = (NORMAL_IRQ_OFFSET + 43),
    INTERRUPT_IRQ_PWA0                       = (NORMAL_IRQ_OFFSET + 45),
    INTERRUPT_IRQ_PWA1                       = (NORMAL_IRQ_OFFSET + 46),
    INTERRUPT_IRQ_SMI                        = (NORMAL_IRQ_OFFSET + 48),
    INTERRUPT_IRQ_GPIO0                      = (NORMAL_IRQ_OFFSET + 49),
    INTERRUPT_IRQ_GPIO1                      = (NORMAL_IRQ_OFFSET + 50),
    INTERRUPT_IRQ_GPIO2                      = (NORMAL_IRQ_OFFSET + 51),
    INTERRUPT_IRQ_GPIO3                      = (NORMAL_IRQ_OFFSET + 52),
    INTERRUPT_IRQ_I2C                        = (NORMAL_IRQ_OFFSET + 53),
    INTERRUPT_IRQ_SPI                        = (NORMAL_IRQ_OFFSET + 54),
    INTERRUPT_IRQ_PCM                        = (NORMAL_IRQ_OFFSET + 55),
    INTERRUPT_IRQ_UART                       = (NORMAL_IRQ_OFFSET + 57),
    maxIRQ = MAX_IRQ
} platform_interrupt_t;

#define IRQ_CNODE_BITS 12

#define KERNEL_TIMER_IRQ INTERRUPT_CORE_CNTVIRQ

#define FIQCTRL_FIQ_ENABLE                   BIT(7)
#define FIQCTRL_FIQ_SRC_GPU_IRQ(x)           (x)
#define FIQCTRL_FIQ_SRC_ARM_TIMER            64
#define FIQCTRL_FIQ_SRC_ARM_MAILBOX          65
#define FIQCTRL_FIQ_SRC_ARM_DOORBELL0        66
#define FIQCTRL_FIQ_SRC_ARM_DOORBELL1        67
#define FIQCTRL_FIQ_SRC_GPU0_HALTED          68
#define FIQCTRL_FIQ_SRC_GPU1_HALTED          69
#define FIQCTRL_FIQ_SRC_ILLEGAL_ACCESS_TYPE1 70
#define FIQCTRL_FIQ_SRC_ILLEGAL_ACCESS_TYPE0 71
#define FIQCTRL_FIQ_SRC(src)                 (FIQCTRL_FIQ_SRC_##src)

#include <arch/machine/gic_pl390.h>

#endif /* !__PLAT_MACHINE_H */
