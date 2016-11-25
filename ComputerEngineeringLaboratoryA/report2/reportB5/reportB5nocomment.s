	.data
array:	.word	0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
enter:	.asciiz	"\n"
colon:	.asciiz	":"
	.text
	.align	2
	.globl	main
main:
	li	$t3,5
	sll	$t4,$t3,2
	la	$t0,array
	addu	$t0,$t0,$t4
	la	$t1,array
	la	$t2,array
	li	$t7,10
	sll	$t7,$t7,2
	la	$t6,array
	addu	$t6,$t6,$t7
loop1:
	move	$t4,$t2
	addu	$t4,$t4,$t0
	subu	$t4,$t4,$t1
	lw	$t5,0($t4)
	sw	$t5,0($t2)
	addiu	$t2,$t2,4
	blt	$t2,$t6,loop1
	la	$t2,array
	li	$t5,15
	sll	$t5,$t5,2
	la	$t4,array
	addu	$t4,$t4,$t5
loop2:
	lw	$t3,0($t2)
	move	$a0,$t2
	li	$v0,1
	syscall
	la	$a0,colon
	li	$v0,4
	syscall
	move	$a0,$t3
	li	$v0,1
	syscall
	la	$a0,enter
	li	$v0,4
	syscall
	addiu	$t2,$t2,4
	blt	$t2,$t4,loop2
	li	$v0,10
	syscall
