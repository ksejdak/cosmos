////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       16.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

    .section    .boot, "ax"
    .global     _start
    .func       _start

_start:
    ldr     lr, =SystemInit
    bx      lr

    ldr     lr, =BoardInit
    bx      lr

    ldr     lr, =main
    bx      lr
