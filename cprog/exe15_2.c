#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
  //FILE構造体のポインタfpinを宣言しexe15_input.txtを読み込みモードで開く。
  //FILE構造体のポインタfpoutを宣言しexe15_output.txtを書き込みモードで開く。
  FILE *fpin = fopen("exe15_input.txt", "r"), *fpout = fopen("exe15_output.txt", "w");
  //要素数1024のchar型配列buffとtextを宣言する。
  char buff[1024], text[1024];
  //ファイルから一行読み込みbuffに格納し、ファイルの終わりに到達するまでtextに連結する。
  while(fgets(buff,1024,fpin)!=NULL)strcat(text,buff);
  //textをexe15_output.exeに出力する。
  fputs(text, fpout);
  //fpinを閉じる。
  fclose(fpin);
  //fpoutを閉じる。
  fclose(fpout);
  //プログラムを終了する。
  return EXIT_SUCCESS;
}
