.section .text
.globl _vectors
_vectors:
.long _stack
.long _start

.section .text
.globl _start
_start:
	nop
	nop
	move.w #0x2700, %sr
/* bss */
	move.l #_sbss, %a0
	move.l #_ebss, %a1
	cmp.l %a0, %a1
	beq.s 2f
1:
	clr.l (%a0)+
	cmp.l %a0, %a1
	bne.s 1b
2:
/* data */
	move.l #_sdata, %a0
	move.l #_edata, %a1
	cmp.l %a0, %a1
	beq.s 2f
	move.l #_sdata_rom, %a2
1:
	move.l (%a2)+, (%a0)+
	cmp.l %a0, %a1
	bne.s 1b
2:
	bsr.w main
1:
	bra.s 1b
