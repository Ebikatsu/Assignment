/*
  ハノイの塔
*/

#include<stdio.h>

#define N 3 /*枚数*/

/*---円盤をx軸からy軸へ移動---*/
void move(int no,int x,int y)
{
  if(no>1)
    move(no-1,x,6-x-y);
  printf("%dを%d軸から%d軸へ移動\n",no,x,y);
  if(no>1)
    move(no-1,6-x-y,y);
}

int main(void)
{
  move(N,1,3);
  return(0);
}
