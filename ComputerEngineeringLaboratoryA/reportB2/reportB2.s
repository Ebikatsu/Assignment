	.data
array:	.word 1
	.word 2
	.word 4
	.word 8
	.word 16
	.word 32
	.word 64
	.word 128		#int array[] = {1,2,4,8,16,32,64,128};
	.text
	.align	2
	.globl	main
main:				#int main(){
	move	$a0,$0		#	int sum = 0;
	la	$t0,array	#	int *a = array;
	li	$t1,8		#	int i = 8;
loop:				#	do{
	lw	$t2,0($t0)	#		int x = *a;
	addu	$a0,$a0,$t2	#		sum = sum + x;
	addu	$t0,$t0,4	#		a++;
	subu	$t1,$t1,1	#		i--;
	bne	$t1,$0,loop	#	}while(i != 0);
	li	$v0,1		#	printf("%d", sum);
	syscall
	move	$v0,$0		#	return 0;
	j	$ra		#}
