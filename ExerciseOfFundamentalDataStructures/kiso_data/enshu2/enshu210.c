#include<stdio.h>
#include<string.h>

int main (void){

  int n1, n2; 

  char moji1[] = "GoodEvening",
       moji2[] = "こんばんは";

  n1 = strlen(moji1);
  n2 = strlen(moji2);

  printf("文字列1の文字数 = %d\n", n1);
  printf("文字列2の文字数 = %d\n", n2);

  return 0;
} 
