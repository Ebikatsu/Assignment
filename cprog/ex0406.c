/*
  読み込んだ非負の整数値を逆順に表示
*/

#include<stdio.h>

int main(void)
{
  int num;

  do {
    printf("非負の整数を入力してください:");
    scanf("%d",&num);
    if(num < 0)
      puts("\a負の数を入力しないでください。");
  } while(num<0); /*numは0以上となっている*/

  printf("%dを逆から読むと", num);
  do {
    printf("%d",num%10); /*最下位の桁の値を表示*/
    num /= 10; /*右に1桁ずらす*/
  } while(num > 0);
  puts("です。");

  return (0);
}
