/*
  読み込んだ非負の整数値の桁数を求める。
*/

#include<stdio.h>

int main(void)
{
  int num,temp;
  int dig;//桁数

  do
    {
      printf("非負の整数を入力してください。:");
      scanf("%d",&num);
      if(num<0)puts("\a負の数を入力しないでください。");
    }while(num<0);//numは0以上となっている。

  temp=num;
  dig=0;

  do
    {
      temp=temp/10;//右に一桁ずらす。
      dig=dig+1;
    }while(temp>0);
  printf("%dは%d桁です。\n",num,dig);

  return 0;
}
