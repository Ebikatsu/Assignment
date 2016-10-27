#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct statistics {
  char city[1024]; // 都市名
  int population; // 人口
};
// (3) 関数 func のプロトタイプ宣言
struct statistics func(struct statistics p);
  int main(void){
    // 構造体 statistics の構造体変数 p1 を宣言し,{"鳥取市", 193945}で初期化
    struct statistics p1 = {"鳥取市", 193945};
    //構造体 statistics の構造体変数 p2 の宣言
    struct statistics p2;
    // (1) func 関数の呼び出し.
    //    構造体変数 p1 を実引数とし,構造体 statistics の構造体変数を返り値として p2 で受け取る.
    p2 = func(p1);
      // (B) 構造体変数 p1 の人口を出力
      printf("%d\n", p1.population);
    // (C) 構造体変数 p2 の人口を出力
    printf("%d\n", p2.population);
    /*
(A), (B), (C) の出力結果と,その結果が得られる理由を説明せよ
出力
200000
193945
208613
理由
(A)では、直前にp.populationに200000が代入されているので200000が出力される。
(B)では、p1は人口が193945で初期化され、(1)ではp1がfunc関数に値渡しされているので変更されずに193945が出力される。
(C)では、(1)でfunc関数の返り値が代入されているので、func関数の返り値の人口が出力される。func関数では(6)でp3の人口に208613が代入されて返されているので、208613が出力される。
    */
       return EXIT_SUCCESS;
  }
// (2) func 関数の定義
//構造体 statistics の構造体変数 p を仮引数とし,構造体 statistics の構造体変数を返り値とする.
struct statistics func(struct statistics p)
{
  // (4) 構造体 statistics の構造体変数 p3 の宣言
  struct statistics p3;
  // 構造体変数 p の人口を 200000 にする
  p.population = 200000;
  // (A) 構造体変数 p の人口を出力
  printf("%d\n", p.population);
  // (5) 構造体変数 p3 の city に"松江市"を代入
  strcpy(p3.city,"松江市");
  // (6) 構造体変数 p3 の population に 208613 を代入
  p3.population = 208613;
  // (7) 構造体変数 p3 を返す
  return p3;
}
