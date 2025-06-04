	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 2
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #128
	stp	x29, x30, [sp, #112]            ; 16-byte Folded Spill
	add	x29, sp, #112
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	stur	wzr, [x29, #-32]
	stur	w0, [x29, #-36]
	stur	x1, [x29, #-48]
                                        ; kill: def $x8 killed $xzr
	str	xzr, [sp, #48]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	mov	x9, sp
	sub	x8, x29, #52
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_scanf
	ldur	w8, [x29, #-52]
	adds	w8, w8, #1
	cset	w8, ne
	tbnz	w8, #0, LBB0_3
	b	LBB0_2
LBB0_2:
	b	LBB0_6
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	mov	x9, sp
	add	x8, sp, #56
	str	x8, [x9]
	sub	x8, x29, #28
	str	x8, [x9, #8]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_scanf
	b	LBB0_4
LBB0_4:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldur	w1, [x29, #-52]
	ldr	w2, [sp, #56]
	add	x0, sp, #48
	sub	x3, x29, #28
	bl	_add
	b	LBB0_5
LBB0_5:                                 ;   in Loop: Header=BB0_1 Depth=1
	mov	w8, #1                          ; =0x1
	tbnz	w8, #0, LBB0_1
	b	LBB0_6
LBB0_6:
	b	LBB0_7
LBB0_7:                                 ; =>This Inner Loop Header: Depth=1
	bl	_getchar
	str	w0, [sp, #44]
	subs	w8, w0, #10
	cset	w8, eq
	mov	w9, #0                          ; =0x0
	str	w9, [sp, #36]                   ; 4-byte Folded Spill
	tbnz	w8, #0, LBB0_9
	b	LBB0_8
LBB0_8:                                 ;   in Loop: Header=BB0_7 Depth=1
	ldr	w8, [sp, #44]
	adds	w8, w8, #1
	cset	w8, ne
	str	w8, [sp, #36]                   ; 4-byte Folded Spill
	b	LBB0_9
LBB0_9:                                 ;   in Loop: Header=BB0_7 Depth=1
	ldr	w8, [sp, #36]                   ; 4-byte Folded Reload
	tbz	w8, #0, LBB0_11
	b	LBB0_10
LBB0_10:                                ;   in Loop: Header=BB0_7 Depth=1
	b	LBB0_7
LBB0_11:
	add	x0, sp, #48
	str	x0, [sp, #24]                   ; 8-byte Folded Spill
	bl	_print
	mov	x9, sp
	sub	x8, x29, #28
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_scanf
	ldr	x1, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	bl	_removeIsland
	str	w0, [sp, #40]
	ldr	w8, [sp, #40]
	subs	w8, w8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB0_13
	b	LBB0_12
LBB0_12:
	add	x0, sp, #48
	bl	_print
	b	LBB0_13
LBB0_13:
	ldur	x9, [x29, #-8]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	cset	w8, eq
	tbnz	w8, #0, LBB0_15
	b	LBB0_14
LBB0_14:
	bl	___stack_chk_fail
LBB0_15:
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp, #112]            ; 16-byte Folded Reload
	add	sp, sp, #128
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_add                            ; -- Begin function add
	.p2align	2
_add:                                   ; @add
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	stur	w2, [x29, #-16]
	str	x3, [sp, #24]
	mov	x0, #24                         ; =0x18
	bl	_malloc
	str	x0, [sp, #16]
	ldur	w8, [x29, #-12]
	ldr	x9, [sp, #16]
	str	w8, [x9]
	ldur	w8, [x29, #-16]
	ldr	x9, [sp, #16]
	str	w8, [x9, #4]
	ldr	x0, [sp, #24]
	bl	_strlen
	add	x0, x0, #1
	bl	_malloc
	ldr	x8, [sp, #16]
	str	x0, [x8, #8]
	ldr	x8, [sp, #16]
	ldr	x0, [x8, #8]
	ldr	x1, [sp, #24]
	mov	x2, #-1                         ; =0xffffffffffffffff
	bl	___strcpy_chk
	ldr	x8, [sp, #16]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #16]
	ldur	x8, [x29, #-8]
	ldr	x8, [x8]
	str	x8, [sp, #8]
	ldr	x8, [sp, #8]
	subs	x8, x8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB1_5
	b	LBB1_1
LBB1_1:
	b	LBB1_2
LBB1_2:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #8]
	ldr	x8, [x8, #16]
	subs	x8, x8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB1_4
	b	LBB1_3
LBB1_3:                                 ;   in Loop: Header=BB1_2 Depth=1
	ldr	x8, [sp, #8]
	ldr	x8, [x8, #16]
	str	x8, [sp, #8]
	b	LBB1_2
LBB1_4:
	ldr	x8, [sp, #16]
	ldr	x9, [sp, #8]
	str	x8, [x9, #16]
	b	LBB1_6
LBB1_5:
	ldr	x8, [sp, #16]
	ldur	x9, [x29, #-8]
	str	x8, [x9]
	b	LBB1_6
LBB1_6:
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_print                          ; -- Begin function print
	.p2align	2
_print:                                 ; @print
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	ldur	x8, [x29, #-8]
	ldr	x8, [x8]
	stur	x8, [x29, #-16]
	b	LBB2_1
LBB2_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	x8, [x29, #-16]
	subs	x8, x8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB2_4
	b	LBB2_2
LBB2_2:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldur	x8, [x29, #-16]
	ldr	w8, [x8]
                                        ; implicit-def: $x11
	mov	x11, x8
	ldur	x8, [x29, #-16]
	ldr	w8, [x8, #4]
                                        ; implicit-def: $x10
	mov	x10, x8
	ldur	x8, [x29, #-16]
	ldr	x8, [x8, #8]
	mov	x9, sp
	str	x11, [x9]
	str	x10, [x9, #8]
	str	x8, [x9, #16]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	b	LBB2_3
LBB2_3:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldur	x8, [x29, #-16]
	ldr	x8, [x8, #16]
	stur	x8, [x29, #-16]
	b	LBB2_1
LBB2_4:
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_removeIsland                   ; -- Begin function removeIsland
	.p2align	2
_removeIsland:                          ; @removeIsland
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	str	wzr, [sp, #12]
                                        ; kill: def $x8 killed $xzr
	str	xzr, [sp, #16]
	ldur	x8, [x29, #-8]
	ldr	x8, [x8]
	str	x8, [sp, #24]
	b	LBB3_1
LBB3_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #24]
	subs	x8, x8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB3_9
	b	LBB3_2
LBB3_2:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	x0, [x8, #8]
	ldur	x1, [x29, #-16]
	bl	_strcmp
	subs	w8, w0, #0
	cset	w8, ne
	tbnz	w8, #0, LBB3_7
	b	LBB3_3
LBB3_3:
	ldr	x8, [sp, #16]
	subs	x8, x8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB3_5
	b	LBB3_4
LBB3_4:
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #16]
	ldr	x9, [sp, #16]
	str	x8, [x9, #16]
	b	LBB3_6
LBB3_5:
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #16]
	ldur	x9, [x29, #-8]
	str	x8, [x9]
	b	LBB3_6
LBB3_6:
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	mov	w8, #1                          ; =0x1
	str	w8, [sp, #12]
	ldr	x0, [sp, #24]
	bl	_free
	b	LBB3_9
LBB3_7:                                 ;   in Loop: Header=BB3_1 Depth=1
	b	LBB3_8
LBB3_8:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #24]
	str	x8, [sp, #16]
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #16]
	str	x8, [sp, #24]
	b	LBB3_1
LBB3_9:
	ldr	w8, [sp, #12]
	subs	w8, w8, #1
	cset	w8, eq
	tbnz	w8, #0, LBB3_11
	b	LBB3_10
LBB3_10:
	adrp	x0, l_.str.6@PAGE
	add	x0, x0, l_.str.6@PAGEOFF
	bl	_printf
	b	LBB3_11
LBB3_11:
	ldr	w0, [sp, #12]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%d"

l_.str.1:                               ; @.str.1
	.asciz	"%d %s"

l_.str.2:                               ; @.str.2
	.asciz	"%s"

l_.str.3:                               ; @.str.3
	.asciz	"number:%d opens:%d name:%s\n"

l_.str.4:                               ; @.str.4
	.asciz	"\n"

l_.str.5:                               ; @.str.5
	.asciz	"is found\n"

l_.str.6:                               ; @.str.6
	.asciz	"not found\n"

.subsections_via_symbols
