#include<stdio.h>
#include<stdlib.h>
#define NUMBER 7
int main(void)
{
  int i;
  int ave=0,h[NUMBER];
  printf("身長を入力してください。\n");
  for(i=0;i<NUMBER;i++){
    printf("%d番:",i+1);
    scanf("%d",&h[i]);
    ave+=h[i];
  }
  printf("平均身長:%.1f\n",(float)ave/NUMBER);
  return EXIT_SUCCESS;
}
