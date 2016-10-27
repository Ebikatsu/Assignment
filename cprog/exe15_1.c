#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
  //FILE構造体のポインタfpを宣言しexe15_input.txtを読み込みモードで開く。
  FILE *fp = fopen("exe15_input.txt", "r");
  //要素数1024のchar型配列buffとtextを宣言する。
  char buff[1024], text[1024];
  //ファイルから一行読み込みbuffに格納し、ファイルの終わりに到達するまでtextに連結する。
  while(fgets(buff,1024,fp)!=NULL)strcat(text,buff);
  //ファイルを閉じる。
  fclose(fp);
  //textを表示する。
  printf("%s\n",text);
  //プログラムを終了する。
  return EXIT_SUCCESS;
}
