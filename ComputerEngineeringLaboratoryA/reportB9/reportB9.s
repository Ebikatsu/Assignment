
	##include<stdio.h>
	##include<stdlib.h>
	#int fact(int n);
	.data
facteq:	.asciiz	"!="
enter:	.asciiz	"\n"
	.text
	.align	2
	.globl	main
	#int main(void)
main:
	#{
	#	int i;
	#	for(i = 10; i >= 0; i--)printf("%d!=%d\n", i, fact(i));
	#$t0:i
	#$v0:fact(i)
	li	$t0,10
loop:
	#printf("%d",$t0:i);
	move	$a0,$t0
	li	$v0,1
	syscall
	#printf(facteq:"!=");
	la	$a0,facteq
	li	$v0,4
	syscall
	#$v0:fact($t0:i) = fact($t0:i);
	#	$a0 = $t0:i;
	move	$a0,$t0
	#	$sp-=8;
	addi	$sp,$sp,-8
	#	*($sp+4) = $t0;
	sw	$t0,4($sp)
	#	*$sp = $ra;
	sw	$ra,0($sp)
	#	goto fact;
	jal	fact
	#	$ra = *$sp;
	lw	$ra,0($sp)
	#	$t0 = *($sp + 4);
	lw	$t0,4($sp)
	#	$sp+=8;
	addi	$sp,$sp,8
	#printf("%d",$v0:fact($t0:i));
	move	$a0,$v0
	li	$v0,1
	syscall
	#printf(enter:"\n");
	la	$a0,enter
	li	$v0,4
	syscall
	#$t0:i--
	addi	$t0,$t0,-1
	#if($t0:i >= 0)goto loop;
	bge	$t0,$zero,loop
	#	return EXIT_SUCCESS;
	li	$v0,10
	syscall
	#}
	#int fact(int n)
	#$v0:fact($t0:n):result
	#$t0:n
	#$t1:i
fact:
	#{
	#$t0:n = $a0:n
	move $t0,$a0
	#	int i, result = 1;
	#$v0:result = 1;
	li	$v0,1
	#	for(i = 1; i <= n; i++)result *= i;
	#$t1:i = 1;
	li	$t1,1
floop:
	#Lo = $v0:result * $t1:i
	mult	$v0,$t1
	#$v0:result = Lo;
	mflo	$v0
	#$t1:i++
	addi	$t1,$t1,1
	#if($t1:i <= $t0:n)goto floop;
	ble	$t1,$t0,floop
	#	return result;
	j	$ra
	#}
