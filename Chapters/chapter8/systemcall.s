	.file	"systemcall.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"hello, world\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB26:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$13, %edx
	movl	$.LC0, %esi
	movl	$1, %edi
	call	write
	movl	$0, %edi
	call	_exit
	.cfi_endproc
.LFE26:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
