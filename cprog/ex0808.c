/*
  組み合わせの数を求める
*/

#include<stdio.h>

/*--- 異なるn個からr個の整数を取り出す組み合わせの数を返す ---*/
int combination(int n,int r)
{
  if(r==0||r==n)
    return(1);
  else if(r==1)
    return(n);
  return(combination(n-1,r-1)+combination(n-1,r));
}

int main(void)
{
  int n,r;

  puts("異なるn個からr個の整数を取り出す組み合わせの数を求めます。");
  printf("n:");scanf("%d",&n);
  printf("r:");scanf("%d",&r);

  printf("組み合わせの数は%dです。\n",combination(n,r));

  return(0);
}
