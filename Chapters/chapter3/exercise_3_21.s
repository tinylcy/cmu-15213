	.file	"exercise_3_21.c"
	.text
	.globl	test
	.type	test, @function
test:
.LFB0:
	.cfi_startproc
	leaq	0(,%rdi,8), %rax
	testq	%rsi, %rsi
	jle	.L2
	cmpq	%rsi, %rdi
	jl	.L3
	movq	%rdi, %rax
	andq	%rsi, %rax
	ret
.L3:
	movq	%rsi, %rax
	subq	%rdi, %rax
	ret
.L2:
	cmpq	$-1, %rsi
	jge	.L4
	leaq	(%rdi,%rsi), %rax
.L4:
	rep ret
	.cfi_endproc
.LFE0:
	.size	test, .-test
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
