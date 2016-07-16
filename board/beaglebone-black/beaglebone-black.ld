OUTPUT_FORMAT("elf32-littlearm")
ENTRY(_start)

MEMORY
{
	ddr (rwx)      :      ORIGIN = 0x00000000, LENGTH = 512M       /* External DDR3 RAM */
    sram (rwx)     :      ORIGIN = 0x402f0400, LENGTH = 32K        /* Internal on-chip SRAM */
}

_bootStart_vma = ORIGIN(sram); /* Kernel .boot VMA should be the same as LMA, as MMU is not configured. */
_textStart_vma = 0x80000000;   /* Kernel .text starts at 2 GB. */
_stackSize     = 0x1000;       /* Stak size is 4KB.*/

SECTIONS
{
    /* Starup code. */
    .boot _bootStart_vma :
    {
        _bootStart_lma = .;

        *(.boot)

        _bootEnd_lma = .;
    } AT > sram

    /* Data. */
	.data :
	{
		*(.data .data.* .gnu.linkonce.d.*)
		*(.data1)
	} AT > sram
	
	/* BSS. */
	.bss :
	{
		_bssStart_lma = .;

		*(.dynsbss)
		*(.sbss .sbss.* .gnu.linkonce.sb.*)
		*(.scommon)
		*(.dynbss)
		*(.bss .bss.* .gnu.linkonce.b.*)
		*(COMMON)

		. = ALIGN(2);
		_bssEnd_lma = .;
	} AT > sram

	/* Stack. */
	.stack : ALIGN(4)
	{
        . += _stackSize;
	} AT > sram

    /* Kernel code. */
    .text _textStart_vma :
    {
        _textStart_lma = .;

        *(.text)                /* .text sections (code). */
        *(.text*)               /* .text* sections (code) - this will merge all symbols in .text into one section. */
        *(.rodata)              /* .rodata sections (constants, strings, etc.). */
        *(.rodata*)             /* .rodata* sections (constants, strings, etc.). */
        *(.glue_7)              /* Glue arm to thumb code. */
        *(.glue_7t)             /* Glue thumb to arm code. */
        *(.eh_frame)
        KEEP (*(.init))
        KEEP (*(.fini))

        _textEnd_lma = .;
    } AT > ddr
    
    /* Constructors and destructors. */
	.ctors :
	{
		KEEP (*crtbegin*.o(.ctors))
		KEEP (*(EXCLUDE_FILE (*crtend*.o ) .ctors))
		KEEP (*(SORT(.ctors.*)))
		KEEP (*(.ctors))
	} AT > ddr

	.dtors :
	{
		KEEP (*crtbegin*.o(.dtors))
		KEEP (*(EXCLUDE_FILE (*crtend*.o ) .dtors))
		KEEP (*(SORT(.dtors.*)))
		KEEP (*(.dtors))
	} AT > ddr
	
    /* Stabs debugging sections. */
	.stab          0 : { *(.stab) }
	.stabstr       0 : { *(.stabstr) }
	.stab.excl     0 : { *(.stab.excl) }
	.stab.exclstr  0 : { *(.stab.exclstr) }
	.stab.index    0 : { *(.stab.index) }
	.stab.indexstr 0 : { *(.stab.indexstr) }
	.comment       0 : { *(.comment) }

	/* DWARF debug sections. Symbols in the DWARF debugging sections are relative to the beginning of the section so we begin them at 0. */
	/* DWARF 1 */
	.debug          0 : { *(.debug) }
	.line           0 : { *(.line) }

	/* GNU DWARF 1 extensions */
	.debug_srcinfo  0 : { *(.debug_srcinfo) }
	.debug_sfnames  0 : { *(.debug_sfnames) }

	/* DWARF 1.1 and DWARF 2 */
	.debug_aranges  0 : { *(.debug_aranges) }
	.debug_pubnames 0 : { *(.debug_pubnames) }

	/* DWARF 2 */
	.debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
	.debug_abbrev   0 : { *(.debug_abbrev) }
	.debug_line     0 : { *(.debug_line) }
	.debug_frame    0 : { *(.debug_frame) }
	.debug_str      0 : { *(.debug_str) }
	.debug_loc      0 : { *(.debug_loc) }
	.debug_macinfo  0 : { *(.debug_macinfo) }

	/* SGI/MIPS DWARF 2 extensions */
	.debug_weaknames 0 : { *(.debug_weaknames) }
	.debug_funcnames 0 : { *(.debug_funcnames) }
	.debug_typenames 0 : { *(.debug_typenames) }
	.debug_varnames  0 : { *(.debug_varnames) }
}
