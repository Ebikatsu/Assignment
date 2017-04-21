/*
  7ビットのCRC検査のサンプルプログラム
  生成多項式は4ビット(検査語は3ビット)
  生成多項式G(x)=x^3+x+1
  情報語は4ビット
  
  (1)から(3)の部分は各自で書き加えること
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ERROR_PROBABILITY 0.8  /* 符号誤り確率 */

#define WORD_LENGTH          7  /* 符号語長 */
#define INFORMATION_LENGTH   4  /* 情報語長 */
#define CHECK_LENGTH         3  /* 検査語長 */

#define BUFFER_LENGTH 256  /* 入力バッファ長 */

/* 各ビットの名称 */
char *bit_name[] = {"r0", "r1", "r2", "f0", "f1", "f2", "f3"};


/*** 符号語を生成多項式で除算して剰余を求める関数 ***/
void getCRC(int code[], int s[])
{
	int i;                /* カウンタ用変数 */
	int r[CHECK_LENGTH];  /* 剰余 */
	int w1;               /* フィードバック係数 */

	memset(r, 0, sizeof(int) * CHECK_LENGTH);    /* 剰余を初期化 */
	
	/* 生成多項式 x^3 + x + 1 */
	
	for (i = 0; i <= WORD_LENGTH - 1; i++) {
		w1 = r[2];
		r[2] = r[1];
		r[1] = (r[0]+ w1) % 2;
		r[0] = (w1 + code[WORD_LENGTH - 1 - i]) % 2;
	}
	
	/*** 剰余(シンドローム)を算出 ***/
	for (i = 0; i <= CHECK_LENGTH - 1; i++) {
		s[2 -i] = r[2];
		r[2] = r[1];
		r[1] = r[0];
	}

}


/*** 符号語を2進数表現で表示する関数 ***/
void print_code(char *title, int code[])
{
	int i;  /* カウンタ用変数 */
	
	/*** タイトルを表示 ***/
	printf("%s ", title);
	
	/*** 各ビットの値を表示 ***/
	for (i = 0; i <= WORD_LENGTH - 1; i++) {
		printf("%d", code[WORD_LENGTH - i - 1]);
		if (i == INFORMATION_LENGTH - 1) {
			printf(" ");
		}
	}
	
	/*** 各ビットの名称を表示 ***/
	printf("  (");
	
	for (i = 0; i <= WORD_LENGTH - 1; i++) {
		printf("%s", bit_name[WORD_LENGTH - i - 1]);
		if (i == INFORMATION_LENGTH - 1) {
			printf(" ");
		}
	}
	
	printf(")\n");
	
}


/*** 伝送誤りを発生させる関数 ***/
void transmission_error(int code[])
{
	double r;  /* 誤りの有無を判定する乱数の値 */
	int n;     /* 誤りの位置を判定する乱数の値 */
	
	r = (double)rand() / ((double)RAND_MAX + 1.0);  /* [0,1)の乱数を発生 */
	
	if (r < ERROR_PROBABILITY) {      /* 伝送誤りが発生したとき */
		n = rand() % WORD_LENGTH;     /* 誤りが発生した位置を設定 */
		code[n] = (code[n] + 1) % 2;  /* 該当するビットの値を反転 */
	}
}

/*** プログラムの開始点 ***/
int main(void)
{
	char str[BUFFER_LENGTH];           /* 入力バッファ */
	int input;                         /* 情報語の10進数表現 */
	int code[WORD_LENGTH];             /* 送信側の符号語 */
	int r[CHECK_LENGTH] = {0, 0, 0};   /* 剰余 */
	int y[WORD_LENGTH];                /* 受信側の符号語 */
	int s[CHECK_LENGTH] = {0, 0, 0};   /* シンドローム */
	int error_bit;                     /* エラー発生位置 */
	int i;                             /* カウンタ用変数 */
	
	printf("********\n");
	printf("  CRC符号の符号化と復号化を体験するプログラムです。\n");
	printf("  4ビットの情報語に3ビットの検査語を加えて伝送します。\n");
	printf("********\n\n");
	
	/*** 乱数の初期化 ***/
	srand(time(NULL));
	
	/*** 無限ループ ***/
	while (1) {
		/**** 情報語の入力部分   ***/
		
		printf("情報語を10進数で入力してください(0?15  エンターのみで終了): ");
		
		fgets(str, BUFFER_LENGTH, stdin);  /* 標準入力から情報語を読み込む */
		
		if (str[0] == '\n')  	/* エンターのみが入力されたとき */
		    break;  /* 無限ループから抜ける */
		
		input = atoi(str);  /* 情報語を数値に変換 */
 		
		printf("入力値(10進数) = %d\n", input);
		
		if (input >= 16 || input <= -1) {  /* 入力値が規定の範囲外のとき */
			 printf("Warning: 規定の範囲外の値が入力されました。\n\n");
			 continue;
		}
		
		memset(code, 0, sizeof(int) * WORD_LENGTH);  /* 符号語を初期化 */
		memset(r, 0, sizeof(int) * CHECK_LENGTH);    /* 剰余を初期化 */
		
		/*** 情報語を検査語のビット数だけ左シフトしたビット列を生成 ***/
		for (i = CHECK_LENGTH; input != 0/***** (1) このループを抜ける条件は？ *****/; i++) {
			code[i] = input % 2;
			input = input / 2;
		}
		
		
		/*** 生成したビット列を生成多項式で除算(符号化回路1/2) ***/
		getCRC(code, r);
		
		/*** 剰余(検査語)をビット列の下位桁に加算(符号化回路2/2) ***/
		for (i = 0; i <= CHECK_LENGTH - 1; i++)code[i]=r[i];
			/**** (2) 何に何を代入すれば良い？ *****/
		
		/*** 送信側の符号語を表示 ***/
		print_code("送信データ", code);
		
		/*** 伝送誤りを追加 ***/
		transmission_error(code);
		
		/*** 符号語の受信 ***/
		for (i = 0; i <= WORD_LENGTH - 1; i++)
			y[i] = code[i];
			
		
		/*** 受信側の符号語を表示 ***/
		print_code("受信データ", y);
		
		/**** 受信した符号語を生成多項式で除算(復号化) ****/
		getCRC(y ,s);
		
		/*** シンドロームの値を表示 ***/
		printf("    シンドローム %d %d %d  (s2 s1 s0) \n", s[2], s[1], s[0]);
		
		/**** シンドロームの値と誤り発生位置の対応付け ****/
		switch (4 * s[2] + 2 * s[1] + s[0]) {
			case 0:
				error_bit = -1;
				break;
			case 1:
				error_bit = 0;
				break;
			case 2:
				error_bit = 1;
				break;
			case 3:
				error_bit = 3;
				break;
			case 4:
				error_bit = 2;
				break;
			case 5:
				error_bit = 6;
				break;
			case 6:
				error_bit = 4;
				break;
			case 7:
				error_bit = 5;
				break;
			default:
				error_bit = -1;
				break;
		}
		
		/*** 誤り発生位置の表示 ***/
		if (error_bit >= 0) {
			printf("    誤り発生位置 = %d  (%s)\n", error_bit, bit_name[error_bit]);
			y[error_bit] = (y[error_bit] + 1) % 2;
		}
		else {
			printf("    誤りなし\n");
		}
		
		/*** 訂正処理後の符号語を表示 ***/
		print_code("訂正データ",y /***** (3) 第2引数で渡すべきものは？ *****/);
		
		printf("\n");
	
	}
	
	return(0);
}
