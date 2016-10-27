#include<stdio.h>
int abs(int n){
  if(n<0){return(n+=-2*n);}
  else{return(n);}}
int main(void){
  int x;
  printf("整数を入力してください:");
  scanf("%d\n",&x);
  printf("%dの絶対値は%dです。",x,abs(x));
  return(0);}
