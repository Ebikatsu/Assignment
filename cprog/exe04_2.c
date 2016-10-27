#include<stdio.h>
#include<stdlib.h>

void fivetimes(int *a);

int main(void){
  int x = 5;
  int *y;
  y = &x;

  // (1) ポインタ変数yのみを用いて,変数xの値に1加える
  (*y)++;

  //xは5で宣言時に初期化され、このアドレスがyに代入されてyの保持するアドレスに存在する値に1が足されているのでxと*yは6となる。
  printf("%d\n", x);
  printf("%d\n", *y);

  // (2) ポインタ変数yに格納されたアドレスを関数fivetimesに渡す
  fivetimes(y);

  //fivetimes関数によって*yの値が5倍され30となる。xと*yは同一のアドレスに存在するためxも30である。
  printf("%d\n", x);
  printf("%d\n", *y);

  return EXIT_SUCCESS;
}

void fivetimes(int *a){
  // (3) main関数のint型変数xの値を5倍する
  *a*=5;
}
