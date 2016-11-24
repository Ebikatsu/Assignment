		##include<stdio.h>
		##include<stdlib.h>
		.data
		#unsigned int result[40];
result:		.word	0:40
enter:		.asciiz	"\n"
		.text
		.align	2
		.globl	main
		#int main()
main:
		#$t0:top
		#$t1:kake
		#$t2:agari
		#$t3:i
		#$t4:t
		#{
		#	unsigned int top = 0;
		#$t0:top = 0;
		li	$t0,0
		#	unsigned int kake;
		#	unsigned int agari;
		#	int i, t;
		#	result[0] = 1;
		#$t5:1
		#$t5:1 = 1
		li	$t5,1
		#*result = $t5:1;
		sw	$t5,result($zero)
		#	for(kake = 2; kake <= 100; kake++)
		#$t1:kake = 2;
		li	$t1,2
kakeloop:
		#	{
		#		agari = 0;
		#$t2:agari = 0;
		li	$t2,0
		#		for(i = 0; i <= top; i++)
		#$t3:i = 0;
		li	$t3,0
iloop:
		#		{
		#			t = result[i] * kake;
		#$t1:kake
		#$t3:i
		#$t4:t
		#$t5:result[i]
		#$t6:i << 2
		#$t6:($t3:i << 2) = $t3:i << 2;
		sll	$t6,$t3,2
		#$t5:result[i] = result[i];
		lw	$t5,result($t6)
		#Lo = $t5:result[i] * $t1:kake;
		mult	$t5,$t1
		#$t4:t = Lo;
		mflo	$t4
		#			t = t + agari;
		#$t4:t = $t4:t + $t2:agari;
		add	$t4,$t4,$t2
		#			agari = t / 10000;
		#			result[i] = t % 10000;
		#$t5:10000
		#$t5:10000 = 10000
		#$t6:t % 10000
		#$t7:i << 2
		li	$t5,10000
		#Lo = $t4:t / $t5:10000; Hi = $t4:t % $t5:10000;
		div	$t4,$t5
		#$t2:agari = Lo;
		mflo	$t2
		#$t6:(t % 10000) = Hi
		mfhi	$t6
		#$t7:($t3:i << 2) = $t3:i << 2
		sll	$t7,$t3,2
		#result[i:$t7] = $t6:t % 10000
		sw	$t6,result($t7)
		#$t3:i++
		addi	$t3,$t3,1
		#if($t3:i <= $t0:top)goto iloop;
		ble	$t3,$t0,iloop
		#		}
		#		if(agari > 0)
		#if($t2:agari <= $zero:0)goto else;
		ble	$t2,$zero,else
		#		{
		#			top ++;
		#$t0:top++
		addi	$t0,$t0,1
		#			result[top] = agari;
		#$t5:top << 2
		#$t5:(top << 2) = $t0:top << 2
		sll	$t5,$t0,2
		#result[$t5:top] = $t2:agari
		sw	$t2,result($t5)
		#		}
else:
		#$t1:kake++
		addi	$t1,$t1,1
		#if($t1:kake <= 100)goto kakeloop;
		#	$t5:100
		#	$t5:100 = 100
		li	$t5,100
		ble	$t1,$t5,kakeloop
		#	}
		#	for(i = top; i >= 0; i--)printf("%d", result[i]);
		#$t0:top
		#$t3:i
		#$t3:i = $t0:top
		move	$t3,$t0
printloop:
		#printf("%d",result[$t3:i]);
		#	$a0:result[i]
		#	$t5:i << 2
		#	$t5:(i << 2) = $t3:i << 2
		sll	$t5,$t3,2
		#	$a0:result[i] = result[i]
		lw	$a0,result($t5)
		#	printf("%d", $a0:result[i]);
		li	$v0,1
		syscall
		#$t3:i--
		addi	$t3,$t3,-1
		#if($t3:i >= $zero:0)goto printloop;
		bge	$t3,$zero,printloop
		#	printf("\n");
		#printf(enter:"\n");
		la	$a0,enter
		li	$v0,4
		syscall
		#	return EXIT_SUCCESS;
		li	$v0,10
		syscall
		#}
		#
