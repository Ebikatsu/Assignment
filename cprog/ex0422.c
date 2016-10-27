/*
  横長の長方形を描画
*/

#include<stdio.h>

int main(void)
{
  int i,j;
  int ln1,ln2,width,height;
  puts("長方形を作りましょう。");
  printf("一辺(その1):");scanf("%d",&ln1);
  printf("一辺(その2):");scanf("%d",&ln2);
  if(ln1<ln2){
    height=ln1;
    width=ln2;
  }else{
    height=ln2;
    width= ln1;
  }
  for(i=1;i<=height;i++){
    for(j=1;j<=width;j++)
      putchar('*');
    putchar('\n');
  }
  return 0;
}
