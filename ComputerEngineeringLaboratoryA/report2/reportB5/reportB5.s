	##include<stdio.h>
	##include<stdlib.h>
	.data
	#int array[15] = {0,0,0,0,0,1,2,3,4,5,6,7,8,9,10};
array:	.word	0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
enter:	.asciiz	"\n"
colon:	.asciiz	":"
	#int main(void)
	.text
	.align	2
	.globl	main
	#{
main:
	#	int * const from = array + 5;
	#	int * const to = array;
	#	int * i;
	#	//$t0:from
	#	//$t1:to
	#	//$t2:i
	#	//$t3:5
	#	//$t4:5 << 2
	#$t3:5 = 5
	li	$t3,5
	#$t4:(5 << 2) = $t3 << 2 = 5 << 2
	sll	$t4,$t3,2
	#$t0:from:(array + 5) = array
	la	$t0,array
	#$t0:from:(array + 5) = $t0 + $t4:array + (5 << 2)
	addu	$t0,$t0,$t4
	#$t1:to:array = array
	la	$t1,array
	#	for(i = array; i < array + 10; i++)*i = i[from - to];
	#	//$t0:from
	#	//$t1:to
	#	//$t2:i
	#	//$t4:i + from - to
	#	//$t5:*(i + from - to)
	#	//$t6:array + 10
	#	//$t7:10 << 2
	#$t2:i:array = array
	la	$t2,array
	#$t7:(10 << 2) = 10
	li	$t7,10
	#$t7:(10 << 2) = 10 << 2
	sll	$t7,$t7,2
	#$t6:(array + 10) = array
	la	$t6,array
	#$t6:(array + 10) = array:$t6 + 10:$t7
	addu	$t6,$t6,$t7
loop1:
	#$t4:(i + from - to) = i:$t2
	move	$t4,$t2
	#$t4:(i + from - to) = i:$t4 + from:$t0
	addu	$t4,$t4,$t0
	#$t4:(i + from - to) = (i + from):$t4 - to:$t1
	subu	$t4,$t4,$t1
	#$t5:*$t4:*(i + from - to) = *$t4
	lw	$t5,0($t4)
	#*$t2:*i = $t5:*(i + from - to)
	sw	$t5,0($t2)
	#$t2:i++
	addiu	$t2,$t2,4
	#if $t2:i < $t6:(array + 10) then jump to loop1
	blt	$t2,$t6,loop1
	#older	for(i = array; i < array + 15; i++)printf("%d\n", *i);
	#	for(i = array; i < array + 15; i++)printf("%u:%d\n", i, *i);
	#	//$t2:i
	#	//$t3:*i
	#	//$t4:array + 15
	#	//$t5:15 << 2
	#$t2:i:array = array
	la	$t2,array
	#$t5:(15 << 2) = 15
	li	$t5,15
	#$t5:(15 << 2) = 15 << 2
	sll	$t5,$t5,2
	#$t4:(array + 15) = array
	la	$t4,array
	#$t4:(array + 15) = $t4:array + $t5:(15 << 2)
	addu	$t4,$t4,$t5
loop2:
	#$t3:*i = *i:*$t2
	lw	$t3,0($t2)
	#print i:$t2
	move	$a0,$t2
	li	$v0,1
	syscall
	#print colon:":"
	la	$a0,colon
	li	$v0,4
	syscall
	#print *i:*$t3
	move	$a0,$t3
	li	$v0,1
	syscall
	#print enter:"\n"
	la	$a0,enter
	li	$v0,4
	syscall
	#i:$t2++
	addiu	$t2,$t2,4
	#if i:$t2 < (array + 15):$t4 then jump to loop2
	blt	$t2,$t4,loop2
	#	return EXIT_SUCCESS;
	li	$v0,10
	syscall
	#}
