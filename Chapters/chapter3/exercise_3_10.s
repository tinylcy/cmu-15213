	.file	"exercise_3_10.c"
	.text
	.globl	arith2
	.type	arith2, @function
arith2:
.LFB0:
	.cfi_startproc
	orq	%rdi, %rsi
	sarq	$3, %rsi
	notq	%rsi
	movq	%rdx, %rax
	subq	%rsi, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	arith2, .-arith2
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
