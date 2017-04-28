/*
 * RSA暗号によって復号化を行うプログラム
 * (1)～(3)の部分は各自で追加すること
 */

#include <stdio.h>
#include <stdlib.h>

/*
  引き渡された文字を復号化して返す関数
  バイナリ法を利用して (c^d) mod n を計算する
  c      : 暗号文の文字(16ビット)
  d      : 鍵1 (指数)
  n      : 鍵2 (除数)
  戻り値 : 復号化された文字(8ビット)
*/
int decrypt(int c, int d, int n)
{
	int result = 1;

	while (d >= 1) {
		if (d % 2 == 1)
			result = (result * c) % n/***** (1) 何で割った余りになる？ *****/;
		d >>= 1;
		c = (c * c) % n/***** (1) 2行前と同じ *****/;
	}

	return result;
}


/*
  引数が素数かどうかを判定する関数
  n : 判定すべき数
  戻り値 : nが素数なら1、nが素数でないなら0
*/
int isPrime(int n)
{
	int i;

	if (n <= 1) {  /* 判定される数が1以下のとき */
		return(0);  /* 素数でない */
	}

	for (i = 2; i <= n - 1; i++)
		if (n % i == 0)  /* 判定される数がより小さい値で割り切れるとき */
			return(0);  /* 素数でない */

	/* いずれの数でも割り切れなかったとき */
	return(1);  /* 素数である */
}


/*
  プログラムの開始点
*/
int main(int argc, char *argv[])
{
	int key1;           /* 暗号鍵1 */
	int key2;	        /* 暗号鍵2 */
	FILE *infile;       /* 入力ファイル名 */
	FILE *outfile;      /* 出力ファイル名 */
	unsigned char c;    /* 読み込んだ文字 */
	int block;          /* ブロック長 */
	int code;           /* ブロックの値 */
	unsigned char data;

	if (argc != 3) {  /* 実行時パラメータの個数が合致しないとき */
		fprintf(stderr, "usage: %s <encrypted-file> <decrypted-file>\n", argv[0]);
		exit(1);  /* 異常終了 */
	}

	/*** ファイルハンドラの取得 ***/

	infile = fopen(argv[1], "rb");   /* 入力ファイルを開く */
	outfile = fopen(argv[2], "wb");  /* 出力ファイルを開く */

	if (infile == NULL || outfile == NULL) {  /* ファイルを開けなかったとき */
		fprintf(stderr, "ファイルを開けません。\n");  /* エラーメッセージを表示 */
		exit(1);  /* 異常終了 */
	}

	/*** 鍵の設定 ***/

	key1 = key2 =  0;  /* 鍵の値を初期化 */

	do {
		printf("鍵(E or D)を入力してください: ");   /* 鍵の入力を促す */
		scanf("%d", &key1);           /* 標準入力から鍵の値を読み込む */
		printf("鍵(N)を入力してください：");   /* 鍵の入力を促す */
		scanf("%d", &key2);

	} while(key1 >= key2 || !isPrime(key1));  /* 鍵の値が規定の範囲外の間は繰り返し */

	/*** 復号化 ***/

    fread(&c, 1, 1, infile);  /* 入力ファイルから1バイト読み込む */
	code = c * 0x100/***** (3) 8ビットの左シフトを乗算で行うには？ *****/; /* cを8ビット左にシフトしたデータをcodeに代入 */
	fread(&c, 1, 1, infile);  /* 入力ファイルから1バイト読み込む */
	code += (int)c;           /* cをcodeに加算する */


	while (!feof(infile)) {  /* ファイルの終端に到達していないとき */
		c = decrypt(code, key1, key2 /***** (2) 第2,第3引数は何になる？ *****/);  /* 読み込んだ文字を復号化 */
		fwrite(&c, 1, 1, outfile);      /* 復号化した文字を出力ファイルに書き出す */
		fread(&c, 1, 1, infile);        /* 入力ファイルから1バイト読み込む */
		code = c * 0x100/***** (3) 上の(3)と同じく、乗算で左シフトするには？ *****/; /* cを8ビットだけ左にシフトしたデータをcodeに代入 */
		fread(&c, 1, 1, infile);        /* 入力ファイルから1バイトを読み込む */
		code += (int)c;                 /* cをcodeに加算する */
	}

	/*** ファイルハンドラの解放 ***/

	fclose(infile);   /* 入力ファイルを閉じる */
	fclose(outfile);  /* 出力ファイルを閉じる */

	return 0;
}
