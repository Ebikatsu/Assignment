#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASCIIMAX (0x7f)

char encrypt(char c, char *key)
{
	return key[c];
}

int main(int argc, char *argv[])
{
	char key[ASCIIMAX + 1];            /* 共通鍵 */
	FILE *infile;             /* 入力ファイル */
	FILE *outfile;            /* 出力ファイル */
	char c;                   /* 読み込んだ文字 */
	int i,j,k;
	
	if (argc != 3) {  /* 実行時パラメータの個数が合致しないとき */
		fprintf(stderr, "usage: %s <original-file> <encrypted-file>\n", argv[0]);
		exit(1);  /* 異常終了 */
	}
	
	/*** ファイルハンドラの取得 ***/
	
	infile = fopen(argv[1], "r");   /* 入力ファイルを開く */
	outfile = fopen(argv[2], "w");  /* 出力ファイルを開く */
	
	if (infile == NULL || outfile == NULL) {  /* ファイルを開けなかったとき */
		fprintf(stderr, "ファイルを開けません。\n");  /* エラーメッセージを表示 */
		exit(1);  /* 異常終了 */
	}
	
	/*** 鍵の設定 ***/
	memset(key, ASCIIMAX + 1, sizeof(char) * (ASCIIMAX + 1));
	for(i = 0; i <= ASCIIMAX; i++)
	{
		int buffer;//入力された数字を直接char型に入れる入力指定子がなかったので入力された数字を一時的に入れておくint型変数を作成した。
		for(j = 0; j <= ASCIIMAX; j++)printf(" %d",key[j]);
		printf("\n");
		//まだ入力されていない数字の一覧を表示する。
		for(j = 0; j <= ASCIIMAX; j++)
		{
			int entered = 0;//その数字が既に入力されたかどうか
			for(k = 0; k <= ASCIIMAX; k++)if(j == key[k])
			{
				entered = 1;
				break;
			}
			if(!entered)printf(" %d", j);
		}
		printf("\n");
		//入力する。
		printf("key[%d]の値を入力してください。",i);
		scanf("%d",&buffer);
		key[i] = (char)buffer;
		//正しい値が入力されたかどうか確認する。
		for(k = 0; k <= ASCIIMAX; k++)if(i != k && key[i] == key[k])
		{
			printf("既に入力された値が入力されました。入力しなおしてください。");
			i--;
			break;
		}
	}
	
	/*** 暗号化 ***/
	
	c = fgetc(infile);  /* 入力ファイルから1文字読み込む */
	
	while (!feof(infile)) {  /* ファイルの終端に到達していないとき */
		c = encrypt(c,key/***** (2) 引数は何になる？ *****/);  /* 読み込んだ文字を暗号化 */
		putc(c,outfile)/***** (3) C言語でやったファイル出力を思い出そう！ *****/;  /* 暗号化した文字を出力ファイルに書き出す */
		c = fgetc(infile);  /* 入力ファイルから1文字読み込む */
	}
	
	/*** ファイルハンドラの解放 ***/
	
	fclose(infile);   /* 入力ファイルを閉じる */
	fclose(outfile);  /* 出力ファイルを閉じる */
	return EXIT_SUCCESS;
}
