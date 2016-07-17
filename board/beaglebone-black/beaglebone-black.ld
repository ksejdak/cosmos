OUTPUT_FORMAT("elf32-littlearm")
ENTRY(_start)

MEMORY {
	ddr (rwx)      :      ORIGIN = 0x00000000, LENGTH = 512M       /* External DDR3 RAM */
    sram (rwx)     :      ORIGIN = 0x402f0400, LENGTH = 32K        /* Internal on-chip SRAM */
}

_bootStart_va = ORIGIN(sram); /* Kernel .boot VMA should be the same as LMA, as MMU is not configured. */
_textStart_va = 0x80000000;   /* Kernel .text starts at 2 GB. */
_stackSize    = 0x1000;       /* Stak size is 4KB.*/

SECTIONS {
    /* Starup code. */
    .boot _bootStart_va : {
        _bootStart_pa = .;

        *(.boot)

        _bootEnd_pa = .;
    } AT > sram

    /* Kernel code. */
    /* .text _textStart_va : */
    .text : { /* TODO: change to above in future. */
        *(.text)                /* .text sections (code). */
        *(.text*)               /* .text* sections (code) - this will merge all symbols in .text into one section. */
        *(.glue_7)              /* Glue arm to thumb code. */
        *(.glue_7t)             /* Glue thumb to arm code. */
        *(.eh_frame)
        KEEP (*(.init))
        KEEP (*(.fini))
    } AT > sram /* TODO: change to ddr in future. */

    /* Constructors and destructors. */
	.ctors : {
		KEEP (*crtbegin*.o(.ctors))
		KEEP (*(EXCLUDE_FILE (*crtend*.o ) .ctors))
		KEEP (*(SORT(.ctors.*)))
		KEEP (*(.ctors))
	} AT > sram /* TODO: change to ddr in future. */

	.dtors : {
		KEEP (*crtbegin*.o(.dtors))
		KEEP (*(EXCLUDE_FILE (*crtend*.o ) .dtors))
		KEEP (*(SORT(.dtors.*)))
		KEEP (*(.dtors))
	} AT > sram /* TODO: change to ddr in future. */

    /* Data. */
	.data : {
		*(.data .data.* .gnu.linkonce.d.*)
		*(.data1)
	} AT > sram = 0
	
	/* Read only data */
	.rodata : ALIGN(8) {
        *(.rodata .rodata.* .gnu.linkonce.r.*)
        *(.rodata1)
    } AT > sram = 0

	/* BSS. */
	.bss : {
		_bssStart_pa = .;

		*(.dynsbss)
		*(.sbss .sbss.* .gnu.linkonce.sb.*)
		*(.scommon)
		*(.dynbss)
		*(.bss .bss.* .gnu.linkonce.b.*)
		*(COMMON)

		. = ALIGN(4);
		_bssEnd_pa = .;
	} AT > sram

	/* Stack. */
	.stack : ALIGN(4) {
        . += _stackSize;
	} AT > sram

	/* Calculate physical addresses of .bss and .stack for startup code. */
	_stackStart_pa = _bssEnd_pa + SIZEOF(.stack) - 4;
}
