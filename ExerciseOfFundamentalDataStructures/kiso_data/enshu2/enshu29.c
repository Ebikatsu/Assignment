#include<stdio.h>

int main (void){

  // 文字配列の初期化設定
  char name0[4][9] = {"Taro","Masatake","Kouichi","Yutaka"};

  char name1[3][7] = {"Kaori","Mariko","Mari"};

  int i;

  // 配列 name0 の表示
  for (i = 0; i < 4; i++){
    printf("name0[%1d]:%-8s\n", i, name0[i]); 
  }

  /* 
   表示形式を定める書式指定文字の %-8s の意味は、
   - : 左づめで、
   8 : 範囲は８桁
   s : 文字列を指定する
       指示されたアドレスから文字を順番に 「\0」が現れるまで出力する。
       printf文中で各文字の先頭アドレス name[0], name[1], name[2], name[3]
       を指定する。
   */

  // 配列 name1 の表示
 for (i = 0; i < 3; i++){
    printf("name1[%1d]:%10s\n", i, name1[i]); 
    // %10s : 10桁の範囲に右づめで, 文字列を出力するように指定する。
  }

 return 0;
}

