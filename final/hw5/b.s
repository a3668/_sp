	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 2
	.globl	_mymin                          ; -- Begin function mymin
	.p2align	2
_mymin:                                 ; @mymin
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	w0, [sp, #8]
	str	w1, [sp, #4]
	ldr	w8, [sp, #8]
	ldr	w9, [sp, #4]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:
	ldr	w8, [sp, #8]
	str	w8, [sp, #12]
	b	LBB0_3
LBB0_2:
	ldr	w8, [sp, #4]
	str	w8, [sp, #12]
	b	LBB0_3
LBB0_3:
	ldr	w0, [sp, #12]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_mymax                          ; -- Begin function mymax
	.p2align	2
_mymax:                                 ; @mymax
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	w0, [sp, #8]
	str	w1, [sp, #4]
	ldr	w8, [sp, #8]
	ldr	w9, [sp, #4]
	subs	w8, w8, w9
	cset	w8, le
	tbnz	w8, #0, LBB1_2
	b	LBB1_1
LBB1_1:
	ldr	w8, [sp, #8]
	str	w8, [sp, #12]
	b	LBB1_3
LBB1_2:
	ldr	w8, [sp, #4]
	str	w8, [sp, #12]
	b	LBB1_3
LBB1_3:
	ldr	w0, [sp, #12]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_maxCap                         ; -- Begin function maxCap
	.p2align	2
_maxCap:                                ; @maxCap
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	str	wzr, [sp, #16]
	ldur	w8, [x29, #-12]
	subs	w8, w8, #1
	str	w8, [sp, #12]
	str	wzr, [sp, #8]
	b	LBB2_1
LBB2_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #16]
	ldr	w9, [sp, #12]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB2_6
	b	LBB2_2
LBB2_2:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldur	x8, [x29, #-8]
	ldrsw	x9, [sp, #16]
	ldr	w0, [x8, x9, lsl #2]
	ldur	x8, [x29, #-8]
	ldrsw	x9, [sp, #12]
	ldr	w1, [x8, x9, lsl #2]
	bl	_mymin
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #16]
	subs	w8, w8, w9
	mul	w8, w0, w8
	str	w8, [sp, #4]
	ldr	w0, [sp, #8]
	ldr	w1, [sp, #4]
	bl	_mymax
	str	w0, [sp, #8]
	ldur	x8, [x29, #-8]
	ldrsw	x9, [sp, #16]
	ldr	w8, [x8, x9, lsl #2]
	ldur	x9, [x29, #-8]
	ldrsw	x10, [sp, #12]
	ldr	w9, [x9, x10, lsl #2]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB2_4
	b	LBB2_3
LBB2_3:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp, #16]
	add	w8, w8, #1
	str	w8, [sp, #16]
	b	LBB2_5
LBB2_4:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp, #12]
	subs	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB2_5
LBB2_5:                                 ;   in Loop: Header=BB2_1 Depth=1
	b	LBB2_1
LBB2_6:
	ldr	w0, [sp, #8]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #96
	stp	x29, x30, [sp, #80]             ; 16-byte Folded Spill
	add	x29, sp, #80
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	str	wzr, [sp, #32]
	add	x0, sp, #36
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	mov	x2, #36                         ; =0x24
	adrp	x1, l___const.main.arr@PAGE
	add	x1, x1, l___const.main.arr@PAGEOFF
	bl	_memcpy
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	mov	w8, #9                          ; =0x9
	str	w8, [sp, #28]
	ldr	w1, [sp, #28]
	bl	_maxCap
	str	w0, [sp, #24]
	ldr	w9, [sp, #24]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldur	x9, [x29, #-8]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	cset	w8, eq
	tbnz	w8, #0, LBB3_2
	b	LBB3_1
LBB3_1:
	bl	___stack_chk_fail
LBB3_2:
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	add	sp, sp, #96
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__const
	.p2align	2, 0x0                          ; @__const.main.arr
l___const.main.arr:
	.long	1                               ; 0x1
	.long	8                               ; 0x8
	.long	6                               ; 0x6
	.long	2                               ; 0x2
	.long	5                               ; 0x5
	.long	4                               ; 0x4
	.long	8                               ; 0x8
	.long	3                               ; 0x3
	.long	7                               ; 0x7

	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Max capacity: %d\n"

.subsections_via_symbols
