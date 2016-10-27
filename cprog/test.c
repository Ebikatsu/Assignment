#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[], char *env[])
{
  int i;
  for(i=0; i<argc; i++)printf("%s\n", argv[i]); //main関数に渡された引数を全て表示します。
                                             //argv[0]はプログラム自身の名前です。
                                             //argv[1]以降はプログラムに渡された引数です。
  for(i=0; env[i]!=NULL; i++)printf("%s\n", env[i]);//環境変数を全て表示します。
  return EXIT_SUCCESS;
}
