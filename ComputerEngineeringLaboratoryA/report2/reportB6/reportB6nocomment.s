	.data
array:	.word	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0, 0, 0, 0
colon:	.asciiz ":"
enter:	.asciiz	"\n"
	.text
	.align	2
	.globl	main
main:
	li	$t2,5
	sll	$t2,$t2,2
	la	$t0,array
	la	$t1,array
	addu	$t1,$t1,$t2
	li	$t5,9
	sll	$t5,$t5,2
	la	$t2,array
	addu	$t2,$t2,$t5
loop1:
	move	$t3,$t2
	addu	$t3,$t3,$t1
	subu	$t3,$t3,$t0
	lw	$t4,0($t2)
	sw	$t4,0($t3)
	addi	$t2,$t2,-4
	bge	$t2,$t0,loop1
	la	$t2,array
	li	$t5,15
	sll	$t5,$t5,2
	la	$t4,array
	addu	$t4,$t4,$t5
loop2:
	move	$a0,$t2
	li	$v0,1
	syscall
	la	$a0,colon
	li	$v0,4
	syscall
	lw	$t3,0($t2)
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
