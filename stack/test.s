	.file	"test.c"
	.text
.globl stack_test
	.type	stack_test, @function
stack_test:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$13107, %eax
	popl	%ebp
	ret
	.size	stack_test, .-stack_test
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"you should run here!,ret: %x\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	movl	$8738, 4(%esp)
	movl	$4369, (%esp)
	call	stack_test
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	leave
	ret
	.size	main, .-main
	.section	.rodata.str1.1
.LC1:
	.string	"you are a good man!"
	.text
.globl bug
	.type	bug, @function
bug:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$.LC1, (%esp)
	call	puts
	movl	$5, (%esp)
	call	sleep
	leave
	ret
	.size	bug, .-bug
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-11)"
	.section	.note.GNU-stack,"",@progbits
