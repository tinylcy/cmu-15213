	.file	"exercise_3_7.c"
	.text
	.globl	scale2
	.type	scale2, @function
scale2:
.LFB0:
	.cfi_startproc
	leaq	(%rdi,%rdi,4), %rax
	leaq	(%rax,%rsi,2), %rax
	leaq	(%rax,%rdx,8), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	scale2, .-scale2
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
