OUTPUT_FORMAT("elf32-littlearm")
ENTRY(_start)

MEMORY {
	ddr (rwx)      :      ORIGIN = 0x00000000, LENGTH = 512M                        /* External DDR3 RAM */
    sram (rwx)     :      ORIGIN = 0x402f0400, LENGTH = (0x402fffff - 0x402f0400)   /* Internal on-chip SRAM */
}

_textStart_va        = 0x80000000;   /* Kernel .text starts at 2 GB. */
_pagePoolInitialSize = 0x1000;       /* Preallocated page for page pool.*/
_stackSize           = 0x1000;       /* Stack size is 4KB.*/

SECTIONS {
	/* Static page pool. */
	.pagePool : ALIGN(4) {
		_pagePoolStart_pa = .;

        . += _pagePoolInitialSize;
	} AT > sram = 0

    /* Starup code. */
    .boot : {
        _bootStart_pa = .;

        *(.boot)

        _bootEnd_pa = .;
    } AT > sram

    /* Kernel code. */
    .text : {
        *(.text)                /* .text sections (code). */
        *(.text*)               /* .text* sections (code). */
        *(.glue_7)              /* Glue ARM to Thumb code. */
        *(.glue_7t)             /* Glue Thumb to ARM code. */
        *(.eh_frame)
        KEEP (*(.init))
        KEEP (*(.fini))
    } AT > sram

    /* Memory regions provided for kernel. */
    .memory_regions : ALIGN(4) {
		_memoryRegions_pa = .;

	/*  Physical address    Total size          Used size */
        LONG(ORIGIN(sram))  LONG(LENGTH(sram))  LONG(_heapStart_pa - ORIGIN(sram))
        LONG(0)             LONG(0)             LONG(0)
    } AT > sram

    /* Constructors and destructors. */
	.ctors : {
		KEEP (*crtbegin*.o(.ctors))
		KEEP (*(EXCLUDE_FILE (*crtend*.o ) .ctors))
		KEEP (*(SORT(.ctors.*)))
		KEEP (*(.ctors))
	} AT > sram

	.dtors : {
		KEEP (*crtbegin*.o(.dtors))
		KEEP (*(EXCLUDE_FILE (*crtend*.o ) .dtors))
		KEEP (*(SORT(.dtors.*)))
		KEEP (*(.dtors))
	} AT > sram

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
	.bss : ALIGN(4) {
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

	/* Heap. */
	_heapStart_pa = .;
}
