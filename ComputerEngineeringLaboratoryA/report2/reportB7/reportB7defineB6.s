	##include<stdio.h>
	##include<stdlib.h>
	.data
	#int array[15] = {0,0,0,0,0,1,2,3,4,5,6,7,8,9,10};
array:	.word	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0, 0, 0, 0
enter:	.asciiz	"\n"
	#int main(void)
	.text
	.align	2
	.globl	main
	#{
main:
	#	int * const from = array;
	#	int * const to = array + 5;
	#	int * i;
	#	//$t0:from:array
	#	//$t1:to:(array + 5)
	#	//$t2:5 << 2;
	#$t2:(5 << 2) = 5
	li	$t2,5
	#$t2:(5 << 2) = 5 << 2
	sll	$t2,$t2,2
	#$t0:from:array = array
	la	$t0,array
	#$t1:to:(array + 5) = array
	la	$t1,array
	#$t1:to:(array + 5) = $t1:array + $t2:(5 << 2)
	addu	$t1,$t1,$t2
	#	if(from > to)for(i = array; i < array + 10; i++)*i = i[from - to];
	#	//$t0:from
	#	//$t1:to
	#	//$t2:i
	#	//$t4:i + from - to
	#	//$t5:*(i + from - to)
	#	//$t6:array + 10
	#	//$t7:10 << 2
	# if $t0:from <= $t1:to then jumpo to else
	ble	$t0,$t1,else
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
else:
	#	else for(i = array + 9; i >= array; i--)i[to - from] = *i;
	#	//$t0:from
	#	//$t1:to
	#	//$t2:i
	#	//$t3:i + to - from
	#	//$t4:i*
	#	//$t5:9 << 2
	#if $t0:from > $t1:to then jump to print
	bgt	$t0,$t1,print
	#$t5:(9 << 2) = 9
	li	$t5,9
	#$t5:(9 << 2) = 9 << 2
	sll	$t5,$t5,2
	#$t2:i = array
	la	$t2,array
	#$t2:i = $t2:array + $t5:(9 << 2)
	addu	$t2,$t2,$t5
loop2:
	#$t3:(i + to - from) = $t2:i
	move	$t3,$t2
	#$t3:(i + to - from) = $t3:i + $t1:to
	addu	$t3,$t3,$t1
	#$t3:(i + to - from) = $t3:(i + to) - $t0:from
	subu	$t3,$t3,$t0
	#$t4:*i = *$t2:*i
	lw	$t4,0($t2)
	#*$t3:*(i + to - from) = $t4
	sw	$t4,0($t3)
	#$t2:i--
	addi	$t2,$t2,-4
	#if $t2:i >= $t0:from:array then jump to loop2
	bge	$t2,$t0,loop2
print:
	#	for(i = array; i < array + 15; i++)printf("%d\n", *i);
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
loop3:
	#$t3:*i = *i:*$t2
	lw	$t3,0($t2)
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
	#if i:$t2 < (array + 15):$t4 then jump to loop3
	blt	$t2,$t4,loop3
	#	return EXIT_SUCCESS;
	li	$v0,10
	syscall
	#}
