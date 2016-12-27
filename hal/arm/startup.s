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
    // Initialize stack pointer.
    ldr     sp, =_stackStart_pa

    // Initialize registers for clearing .bss section.
    mov     r0, #0
    ldr     r1, =_bssStart_pa
    ldr     r2, =_bssEnd_pa

bssClear:
    cmp     r1, r2
    strlo   r0, [r1], #4
    blo     bssClear

    blx     mmu_init

    ldr     lr, =main
    bx      lr

    .endfunc
