#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
  // (1) 構造体 statistics の宣言
  struct statistics{
  // (2) メンバとして、char 型配列 prefecture の宣言。128 文字分の記憶領域を確保。
    char prefecture[128];
  // (3) メンバとして、char 型配列 city の宣言。128 文字分の記憶領域を確保。
    char city[128];
  // (4) メンバとして、int 型変数 population の宣言
    int population;
  };
// (5) 構造体 statistics に対する,構造体変数 p1 と p2 の宣言
  struct statistics p1,p2;
// (6) 構造体 statistics に対する,構造体変数 p3 を宣言し、{"鳥取県", "鳥取市", 193945}で初期化
  struct statistics p3 = {"鳥取県", "鳥取市", 193945};

//     三つの構造体ポインタを宣言し、それぞれにp1,p2,p3のアドレスを代入
  struct statistics *ptr1=&p1,*ptr2=&p2,*ptr3=&p3;
// (7) 構造体変数 p1 の prefecture に"島根県"を代入
  strcpy(ptr1->prefecture, "島根県");
// (8) 構造体変数 p1 の city に"松江市"を代入
  strcpy(ptr1->city, "松江市");
// (9) 構造体変数 p1 の population に 208613 を代入
  ptr1->population=208613;
// (10) 構造体変数 p2 の prefecture に"島根県"を代入
  strcpy(ptr2->prefecture, "島根県");
// (11) 構造体変数 p2 の city に"出雲市"を代入
  strcpy(ptr2->city, "出雲市");
// (12) 構造体変数 p2 の population に 180000 を代入
  ptr2->population=180000;
// (13) 構造体変数 p1 の各メンバの値を出力
  printf("%s\n%s\n%d\n",ptr1->prefecture, ptr1->city, ptr1->population);
// (14) 出雲市の人口を 171485 に変更
  ptr2->population=171485;
// (15) 構造体変数 p2 の各メンバの値を出力
  printf("%s\n%s\n%d\n", ptr2->prefecture, ptr2->city, ptr2->population);
// (16) 今後、松江市と鳥取市の人口は変化することを前提として、
//人口の多い方の都市と人口差を出力する
//(つまり、どちらの人口が多いかは分からないとする。)
//(人口が同じ場合は想定しなくてもよい)
  printf("%s%d\n",ptr1->population>ptr3->population?ptr1->city:ptr3->city,ptr1->population>ptr3->population?ptr1->population-ptr3->population:ptr3->population-ptr1->population);
return EXIT_SUCCESS;
}
