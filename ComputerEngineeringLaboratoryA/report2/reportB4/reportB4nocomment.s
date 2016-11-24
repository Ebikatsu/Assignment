		.data
array:		.word	0, 0, 0, 0, 0, 0, 0, 0, 0, 0
prompt:		.asciiz	">"
enter:		.asciiz "\n"
colon:		.asciiz	":"
		.text
		.align	2
		.globl	main
main:
		la	$a0,prompt
		li	$v0,4
		syscall
		li	$v0,5
		syscall
		move	$t0,$v0
		li	$t1,0
		blt	$t0,$t1,printt0
		li	$t1,10
		bge	$t0,$t1,printt0
		la	$t1,array
		sll	$t2,$t0,2
		addu	$t1,$t1,$t2
		lw	$t2,0($t1)
		addiu	$t2,$t2,1
		sw	$t2,0($t1)
printt0:
		move	$a0,$t0
		li	$v0,1
		syscall
		la	$a0,enter
		li	$v0,4
		syscall
		li	$t1,0
		bge	$t0,$t1,main
		li	$t0,0
loop:
		move	$a0,$t0
		li	$v0,1
		syscall
		la	$a0,colon
		li	$v0,4
		syscall
		la	$t1,array
		sll	$t2,$t0,2
		addu	$t1,$t1,$t2
		lw	$t1,0($t1)
		move	$a0,$t1
		li	$v0,1
		syscall
		la	$a0,enter
		li	$v0,4
		syscall
		addiu	$t0,$t0,1
		li	$t1,10
		blt	$t0,$t1,loop
		li	$v0,10
		syscall
