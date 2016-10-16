	.data
facteq:	.asciiz	"!="
enter:	.asciiz	"\n"
	.text
	.align	2
	.globl	main
main:
	li	$t0,10
loop:
	move	$a0,$t0
	li	$v0,1
	syscall
	la	$a0,facteq
	li	$v0,4
	syscall
	move	$a0,$t0
	addi	$sp,$sp,-8
	sw	$t0,4($sp)
	sw	$ra,0($sp)
	jal	fact
	lw	$ra,0($sp)
	lw	$t0,4($sp)
	addi	$sp,$sp,8
	move	$a0,$v0
	li	$v0,1
	syscall
	la	$a0,enter
	li	$v0,4
	syscall
	addi	$t0,$t0,-1
	bge	$t0,$zero,loop
	li	$v0,10
	syscall
fact:
	move $t0,$a0
	bne	$t0,$zero,else
	li	$v0,1
	j	$ra
else:
	addi	$a0,$t0,-1
	addi	$sp,$sp,-8
	sw	$t0,4($sp)
	sw	$ra,0($sp)
	jal	fact
	lw	$ra,0($sp)
	lw	$t0,4($sp)
	addi	$sp,$sp,8
	mult	$t0,$v0
	mflo	$v0
	j	$ra
