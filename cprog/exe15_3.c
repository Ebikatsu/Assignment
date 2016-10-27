#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
  //FILE構造体のポインタfpinを宣言しexe15_input.txtを読み込みモードで開く。
  //FILE構造体のポインタfpoutを宣言しexe15_add.txtを書き込みモードで開く。
  FILE *fpin = fopen("exe15_input.txt", "r"), *fpadd = fopen("exe15_add.txt", "a");
  //要素数1024のchar型配列buffとtextを宣言する。
  char buff[1024], text[1024];
  //ファイルから一行読み込みbuffに格納し、ファイルの終わりに到達するまでtextに連結する。
  while(fgets(buff,1024,fpin)!=NULL)strcat(text,buff);
  //textをexe15_add.exeに出力する。
  fprintf(fpadd, "%s", text);
  //fpinを閉じる。
  fclose(fpin);
  //fpaddを閉じる。
  fclose(fpadd);
  //プログラムを終了する。
  return EXIT_SUCCESS;
}
