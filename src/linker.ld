ENTRY(_start)

MEMORY {
	RAM (rwx) : ORIGIN = 0x00000000, LENGTH = 32m
	ROM  (rx) : ORIGIN = 0xF0000000, LENGTH = 1k
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
		_stack = ORIGIN(RAM) + LENGTH(RAM) - 1M;
	} >RAM
}
