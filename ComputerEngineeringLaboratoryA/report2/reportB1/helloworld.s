	.data
str:	.asciiz	"Hello,World\n"
	.text
	.align	2
	.globl	main
main:
	li	$v0,4
	la	$a0,str
	syscall
	move	$v0,$0
	j	$ra
