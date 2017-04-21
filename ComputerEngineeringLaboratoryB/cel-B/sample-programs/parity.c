/*
  1ビット垂直パリティ符号のサンプルプログラム
  
  7ビットの情報語に1ビットのパリティ符号を加えます。
  このプログラムでは偶数パリティを使用しています。
  符号語の各ビットには同じ確率でビット誤りが生じます。
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_LENGTH 256       /* 標準入力からの最大入力文字数 */
#define ERROR_PROBABILITY 0.08  /* ビット誤り確率 */
#define INFORMATION_LENGTH 7    /* 情報語のビット数 */
#define CODE_LENGTH 8           /* 符号語のビット数 */

char *bit_name[] = {"f6", "f5", "f4", "f3", "f2", "f1", "f0", "p0"};


/**** 情報語と検査語を表示する関数 ****/
void print_code(char *title, int code[]) {
	int i;
	
	/*** タイトルを表示 ***/
	printf("%s ", title);
	
	/*** 各ビットの値を表示 ***/
	for(i = 0; i <= CODE_LENGTH - 1; i++) {
		if (i == INFORMATION_LENGTH)
			printf(" ");
			
		printf("%d", code[i]);
	}
	
	/*** 各ビットの名称を表示 ***/
	
	printf("  (");
	
	for(i = 0; i <= CODE_LENGTH - 1; i++) {
		if (i == INFORMATION_LENGTH)
			printf(" ");
		printf("%s", bit_name[i]);
	}
	
	printf(")\n");
}

/**** 伝送誤りを発生させる関数 ****/
void transmission_error(int code[]) {
	
	int i;
	double r;
	
	for (i = 0; i <= CODE_LENGTH - 1; i++) {
		
		r = (double)rand() / ((double)RAND_MAX + 1.0);
		
		if (r < ERROR_PROBABILITY)  /* 伝送誤りが発生したとき */
			code[i] = (code[i] + 1) % 2;  /* ビットを反転 */
	}
}

/**** プログラムの開始点 ****/
int main(void)
{
	
	char str[BUFFER_LENGTH];  /* 情報語の文字表現 */
	int x;                    /* 符号語の数値表現 */
	int code[CODE_LENGTH];    /* 符号語のビット列を格納する配列 */
	int even_parity;  /* 受信した符号語から算出されるパリティ */
	int i;  /* カウンタ用変数 */
	int n;  /* 情報語内の1の個数 */
	int a;  /* ビットの値を格納する変数 */
	
	printf("********\n");
	printf("  1ビット垂直パリティ検査を体験するプログラムです。\n");
	printf("  7ビットの情報語に1ビットの検査語を加えて伝送します。\n");
	printf("  ここでは偶数パリティを使用しています。\n");
	printf("********\n\n");
	
	/*** 乱数の初期化 ***/
	srand(time(NULL));
	
	/*** 無限ループ ***/
	while (1) {
		
		/**** 情報語の入力部分   ***/
		
		printf("情報語を10進数で入力してください(0?127  エンターのみで終了): ");
		
		fgets(str, BUFFER_LENGTH, stdin);  /* 標準入力から情報語を読み込む */
		
		if (str[0] == '\n')  	/* エンターのみが入力されたとき */
		    break;  /* 無限ループから抜ける */
		
		x = atoi(str);  /* 情報語を数値に変換 */
 		
		printf("入力値(10進数) = %d\n", x);
		
		if (x >= 128 || x <= -1) {  /* 入力値が規定の範囲外のとき */
			 printf("Warning: 規定の範囲外の値が入力されました。\n\n");
			 continue;
		}
		
		/**** 偶数パリティの値を計算する部分 ****/
		
		n = 0; /* 1の個数を初期化 */
		
		/* ビットごとに分解するループ */
		for (i = 0; i <= INFORMATION_LENGTH - 1; i++) {
			a = x >> ((INFORMATION_LENGTH - 1) - i) & 1;  /* 上位からi+1番目のビットを抽出 */
			code[i] = a;  /* ビットの値を配列の要素に格納 */
			if (a == 1)  /* 抽出したビットの値が1のとき */
				n++;  /* 1の個数を増加 */
		}
		
		printf("入力値( 2進数) = ");
		
		for (i = 0; i <= INFORMATION_LENGTH - 1; i++) {
			printf("%d", code[i]);
		}
		printf("\n");
		
		i = CODE_LENGTH - 1;
		
		if (n % 2 == 0)  /* 1の個数が偶数のとき */
			code[i] = 0;  /* 検査ビットを0に設定 */
		else  /* 1の個数が奇数のとき */
			code[i] = 1;  /* 検査ビットを1に設定 */
		
		printf("\n");
		
		/**** 送信側の符号語を表示する部分 ****/
		print_code("送信データ", code);
		
		/**** 伝送エラーを発生させる部分 ****/
		transmission_error(code);
		
		/**** 受信側の符号語を表示する部分 ****/
		print_code("受信データ", code);
		
		/**** 偶数パリティの値を計算する部分 ****/
		
		n = 0; /* 1の個数を初期化 */
		
		/* ビットごとに分解するループ */
		for (i = 0; i <= INFORMATION_LENGTH - 1; i++) {
			if (code[i] == 1)  /* 抽出したビットの値が1のとき */
				n++;  /* 1の個数を増加 */
		}
		
		if (n % 2 == 0)  /* 1の個数が偶数のとき */
			even_parity = 0;  /* 偶数パリティは0 */
		else  /* 1の個数が奇数のとき */
			even_parity = 1;  /* 偶数パリティは1 */
		
		printf("  算出された検査ビット = %d\n", even_parity);
		printf("\n");
		
		if (code[CODE_LENGTH - 1] == even_parity)  /* エラーが検出されなかったとき */
			printf("伝送誤りはありません。\n");
		else  /* エラーが検出されたとき */
			printf("伝送誤りが検出されました。\n");
			
		printf("\n");

	}
	
	return 0;
}
