	.file	"program.c"
	.text
	.globl	includingStruct
	.bss
	.align 4
	.type	includingStruct, @object
	.size	includingStruct, 4
includingStruct:
	.zero	4
	.globl	includingUnion
	.align 4
	.type	includingUnion, @object
	.size	includingUnion, 4
includingUnion:
	.zero	4
	.section	.rodata
.LC0:
	.string	"Hello world!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 14.2.1 20240910"
	.section	.note.GNU-stack,"",@progbits
