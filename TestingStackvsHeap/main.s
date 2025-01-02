	.file	"main.cpp"
	.text
	.section	.text._ZN7Vector3C2Ev,"axG",@progbits,_ZN7Vector3C5Ev,comdat
	.align 2
	.weak	_ZN7Vector3C2Ev
	.type	_ZN7Vector3C2Ev, @function
_ZN7Vector3C2Ev:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, (%rax)
	movq	-8(%rbp), %rax
	movss	.LC1(%rip), %xmm0
	movss	%xmm0, 4(%rax)
	movq	-8(%rbp), %rax
	movss	.LC2(%rip), %xmm0
	movss	%xmm0, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_ZN7Vector3C2Ev, .-_ZN7Vector3C2Ev
	.weak	_ZN7Vector3C1Ev
	.set	_ZN7Vector3C1Ev,_ZN7Vector3C2Ev
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movl	$5, -20(%rbp)
	movl	$1, -80(%rbp)
	movl	$2, -76(%rbp)
	movl	$3, -72(%rbp)
	movl	$4, -68(%rbp)
	movl	$5, -64(%rbp)
	leaq	-92(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7Vector3C1Ev
	movl	$4, %edi
	call	_Znwm
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movl	$5, (%rax)
	movl	$20, %edi
	call	_Znam
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movl	$1, (%rax)
	movq	-40(%rbp), %rax
	addq	$4, %rax
	movl	$2, (%rax)
	movq	-40(%rbp), %rax
	addq	$8, %rax
	movl	$3, (%rax)
	movq	-40(%rbp), %rax
	addq	$12, %rax
	movl	$4, (%rax)
	movq	-40(%rbp), %rax
	addq	$16, %rax
	movl	$5, (%rax)
	movl	$12, %edi
	call	_Znwm
	movq	%rax, %rbx
	movq	%rbx, %rdi
	call	_ZN7Vector3C1Ev
	movq	%rbx, -48(%rbp)
	movl	$0, %eax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1092616192
	.align 4
.LC1:
	.long	1093664768
	.align 4
.LC2:
	.long	1094713344
	.ident	"GCC: (GNU) 14.2.1 20240912 (Red Hat 14.2.1-3)"
	.section	.note.GNU-stack,"",@progbits
