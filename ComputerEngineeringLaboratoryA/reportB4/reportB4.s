		##include<stdio.h>
		##include<stdlib.h>
		.data
		#const int arraylength = 10;
		#int array[10] = {0,0,0,0,0,0,0,0,0,0};
array:		.word	0, 0, 0, 0, 0, 0, 0, 0, 0, 0
prompt:		.asciiz	">"
enter:		.asciiz "\n"
colon:		.asciiz	":"
		.text
		.align	2
		.globl	main
main:		#int main(void)
		#{
		#	do
		#	{
		#		printf(">");
		#		//prompt:">"
		la	$a0,prompt
		li	$v0,4
		syscall
		#		scanf("%d", &c);
		#		//$t0:c
		li	$v0,5
		syscall
		move	$t0,$v0
		#		if(0 <= 0 && c < arraylength)
		#		//$t0:c
		#		//$t1:0,arraylength
		li	$t1,0
		blt	$t0,$t1,printt0
		li	$t1,10
		bge	$t0,$t1,printt0
		#			array[c]++;
		#			//$t0:c
		#			//$t1:array+c
		#			//$t2:c * sizeof(int),++array[c]
		la	$t1,array
		sll	$t2,$t0,2
		addu	$t1,$t1,$t2
		lw	$t2,0($t1)
		addiu	$t2,$t2,1
		sw	$t2,0($t1)
printt0:
		#		printf("%d\n", c);
		#		//$t0:c
		#		//enter:"\n"
		move	$a0,$t0
		li	$v0,1
		syscall
		la	$a0,enter
		li	$v0,4
		syscall
		#	}while(c >= 0)
		#	//$t0:c
		#	//$t1:0
		li	$t1,0
		bge	$t0,$t1,main
		#	for(i = 0; i < arraylength; i++)
		#	//$t0:i
		li	$t0,0
loop:
		#		printf("%d:%d\n", i, array[i]);
		#		//$t0:i
		#		//$t1:array + i, array[i]
		#		//$t2:c * sizeof(int)
		#print i
		move	$a0,$t0
		li	$v0,1
		syscall
		#print colon
		la	$a0,colon
		li	$v0,4
		syscall
		#$t1 = array;
		la	$t1,array
		#$t2 = i << 2;
		sll	$t2,$t0,2
		#$t1 = $t1 + $t2 = array + i;
		addu	$t1,$t1,$t2
		#$t1 = *$t1 = array[i];
		lw	$t1,0($t1)
		#print array[i]
		move	$a0,$t1
		li	$v0,1
		syscall
		#print enter
		la	$a0,enter
		li	$v0,4
		syscall
		#i++
		addiu	$t0,$t0,1
		#?i < arraylength
		#$t1:arraylength
		li	$t1,10
		blt	$t0,$t1,loop
		#	return EXIT_SUCCESS;
		li	$v0,10
		syscall
		#}
