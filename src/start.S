.section .text
.globl _vectors
_vectors:
.long _stack
.long _start

.section .text
.globl _start
_start:
	nop
	move.w #0x2700, %sr
	bsr.w main
