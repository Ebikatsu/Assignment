#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 5    /* スレッド数 */
#define WAKEUP  10   /* 休眠・起床回数 */

int number[THREADS];

void *run(void *);

/*
 * プログラムの開始点
 */
int main(void)
{
  pthread_t thread[THREADS];  /* スレッド */
  int i;  /* カウンタ変数 */
  int status;  /* 関数の実効結果 */

  /*** 乱数の発生系列に現在時刻を設定する。 ***/
  srand(time(NULL));

  for (i = 0; i <= THREADS - 1; i++) {
    number[i] = i;

    /*** 新しいスレッドを生成する。 ***/
    status = pthread_create(&thread[i], NULL, run, (void *)(&number[i]));

    /*** 上記処理に失敗したら、エラーメッセージを表示して異常終了 ***/
    if (status != 0) {
      fprintf(stderr, "Error: cannot create a thread.\n");
      exit(EXIT_FAILURE);
    }
  }

  for (i = 0; i <= THREADS - 1; i++) {
    /*** 指定されたスレッドが終了するまで呼び出し元のメインスレッドをブロックする。 ***/
    pthread_join(thread[i], NULL);
  }

  /*** 正常終了 ***/
  return(EXIT_SUCCESS);
}

/*
 * スレッド関数
 */
void *run(void *num)
{
  int number;  /* スレッド番号 */
  int interval;  /* 休眠時間[sec] */
  int i;  /* カウンタ変数 */

  /*** スレッド番号を設定 ***/
  number = *(int *)(num);

  for (i = 1; i <= WAKEUP; i++) {

    /*** 1以上5以下の乱数をintervalに代入する。 ***/
    interval = rand() % 5 + 1;

    /*** 待つ。 ***/
    sleep(interval);

    /*** スレッド起床時にメッセージを表示 ***/
    printf("thread %d wakes up %d times.\n", number, i);
  }
  return NULL;
}
