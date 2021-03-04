ENTRY(_start)

MEMORY {
	DRAM (rwx) : ORIGIN = 0x00000000, LENGTH = 32m
	RAM  (rwx) : ORIGIN = 0x80000000, LENGTH = 4k
	ROM  (rx)  : ORIGIN = 0x40000000, LENGTH = 256
}

SECTIONS {
	.text : {
		. = ALIGN(4);
		_stext = .;
		src/start.o(.text*)
		*(.text*)
		*(.rodata*)
		. = ALIGN(4);
		_etext = .;
	} >ROM

	.data : {
		. = ALIGN(4);
		_sdata = .;
		_sdata_rom = LOADADDR(.data);
		*(.data*)
		*(COMMON)
		. = ALIGN(4);
		_edata = .;
	} >RAM AT>ROM

	.bss : {
		. = ALIGN(4);
		_sbss = .;
		*(.bss*)
		. = ALIGN(4);
		_ebss = .;
		_stack = ORIGIN(DRAM) + LENGTH(DRAM) - 1M;
	} >RAM
}
