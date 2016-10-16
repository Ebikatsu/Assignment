		.data
prompt:		.asciiz	">"
enterprompt:	.asciiz "\n>"
		.text
		.align	2
		.globl	main
main:
		la	$a0,prompt
		li	$v0,4
		syscall
loop:
		li	$v0,5
		syscall
		move	$t0,$v0
		move	$a0,$t0
		li	$v0,1
		syscall
		la	$a0,enterprompt
		li	$v0,4
		syscall
		li	$t1,-1
		slt	$t0,$t1,$t0
		li	$t1,1
		beq	$t0,$t1,loop
		move	$v0,$0
		j	$ra
