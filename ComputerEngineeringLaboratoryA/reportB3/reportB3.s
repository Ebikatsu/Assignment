		.data
prompt:		.asciiz	">"
enterprompt:	.asciiz "\n>"
		.text
		.align	2
		.globl	main
main:
		#write prompt to stdout
		la	$a0,prompt
		li	$v0,4
		syscall
loop:
		#read int from stdin to $t0
		li	$v0,5
		syscall
		move	$t0,$v0
		#write $t0 to stdout
		move	$a0,$t0
		li	$v0,1
		syscall
		#write enterprompt to stdout
		la	$a0,enterprompt
		li	$v0,4
		syscall
		#break and exit
		li	$t1,-1
		slt	$t0,$t1,$t0
		li	$t1,1
		beq	$t0,$t1,loop
		move	$v0,$0
		j	$ra
