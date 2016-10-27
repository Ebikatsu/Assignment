#include<stdio.h>

int main(void)
{
  int cnt;
  int na,nb;

  puts("二つの整数を入力してください。");
  printf("整数A:");scanf("%d",&na);
  printf("整数B:");scanf("%d",&nb);

  cnt=0;
  if(na%2==0)cnt=cnt+1;
  if(nb%2==0)cnt=cnt+1;

  switch(cnt)
    {
    case 0:puts("両方とも奇数です。");break;
    case 1:puts("片方が偶数です。");break;
    case 2:puts("両方とも偶数です。");break;
    }

  return 0;
}
