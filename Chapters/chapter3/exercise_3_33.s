	.file	"exercise_3_33.c"
	.text
	.globl	procprob
	.type	procprob, @function
procprob:
.LFB0:
	.cfi_startproc
	movslq	%edi, %rdi
	addq	%rdi, (%rdx)
	addb	%sil, (%rcx)
	movl	$6, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	procprob, .-procprob
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
