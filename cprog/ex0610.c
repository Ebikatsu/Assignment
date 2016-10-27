/*
  配列の全ての要素に同じ値を代入する関数
*/

#include<stdio.h>
#define NUMBER 5 /*配列の要素数*/

/*--- 要素数noの配列vcの全要素にxを代入 ---*/
void fill(int vc[],int no,int x)
{
  int i;
  for(i=0;i<no;i++)
    vc[i]=x;
}

int main(void)
{
  int i;
  int x[NUMBER]={5,4,3,2,1};
  fill(x,NUMBER,2);
  for(i=0;i<NUMBER;i++)
    printf("x[%d]=%d\n",i,x[i]);
  return(0);
}
