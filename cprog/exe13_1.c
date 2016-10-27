#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 構造体 statistics の宣言
struct statistics{
  // メンバとして、char 型配列 city の宣言。1024 文字分の記憶領域を確保。
  char city[1024];
  // メンバとして、int 型変数 population の宣言
  int population;
};
// (5) 関数 func のプロトタイプ宣言
void func(struct statistics *p);
int main(void){
  // 構造体 statistics に対する,構造体変数 p1 を宣言し、{"鳥取市", 193945}で初期化
  struct statistics p1 = {"鳥取市", 193945};
  // (1) 構造体 statistics に対する,構造体ポインタ p2 の宣言
  struct statistics *p2;
  // (2) 構造体ポインタ p2 に構造体変数 p1 のアドレスを代入
  p2 = &p1;
  // (A) 構造体変数 p1 の各メンバの値を出力
  printf("%s\n", p1.city);
  printf("%d\n", p1.population);
  // (3) func 関数の呼び出し.
  //構造体ポインタ p2 を実引数とし,返り値は無し.
  func(p2);
    // (C) 構造体変数 p1 の各メンバの値を出力
    printf("%s\n", p1.city);
  printf("%d\n", p1.population);
  /*
(A), (B), (C) の出力結果と,その結果が得られる理由を記述せよ
(A)では、p1が{"鳥取市",193945}で初期化され、(A)までp1の内容が変更されていないため、出力は、
鳥取市
193945
となる。
(B)では、(2)でp2にp1のアドレスが格納され、(3)でp2を実引数としてfunc関数が呼び出されているので、func関数にp1のアドレスが渡される。func関数ではp1のメンバpopulationが200000に変更されているので、出力は、
鳥取市
200000
となる。
(C)では、func関数によってp1.populationは200000に変更されているので、出力は、
鳥取市
200000
となる。
  */
return EXIT_SUCCESS;
}
// (4) func 関数の定義
//構造体 statistics の構造体ポインタ p を仮引数とし,返り値は無し.
void func(struct statistics *p)
{
  // (6) 構造体ポインタ p の人口を 200000 にする
  p->population=200000;
  // (B) 構造体変数 p の各メンバの値を出力
  printf("%s\n", p->city);
 printf("%d\n", p->population);
}
