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
	#$v0:fact($t0:n)
	#$t0:n
fact:
	#{
	#$t0:n = $a0:n
	move $t0,$a0
	#	if(n == 0)return 1;
	#if($t0:n != $zero:0)goto else;
	bne	$t0,$zero,else
	#$v0:fact($t0:n:0):1 = 1;
	li	$v0,1
	#return;
	j	$ra
	#	else return n * fact(n -1);
	#$t0:n
	#$a0:($t0:n - 1)
	#$v0:($t0:n) * fact($a0:($t0:n - 1))
else:
	#$a0:($t0:n - 1) = $t0:n - 1;
	addi	$a0,$t0,-1
	#$v0:($t0:n) * fact($a0:($t0:n - 1)) = fact($a0:($t0:n - 1));
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
	#$v0:($t0:n) * fact($a0:($t0:n - 1)) = $t0:n * $v0:fact($a0:($t0:n - 1));
	#	Lo = $t0:n * $v0:fact($a0:($t0:n - 1));
	mult	$t0,$v0
	#	$v0:($t0:n) * fact($a0:($t0:n - 1)) = Lo;
	mflo	$v0
	#return;
	j	$ra
	#}
