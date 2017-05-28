#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define PHILOSOPHERS 4
#define EXIT_TIME 60

pthread_mutex_t chopsticks[PHILOSOPHERS];
int philosophers_status[PHILOSOPHERS] = {0};
int chopsticks_status[PHILOSOPHERS] = {0};
int number[PHILOSOPHERS];
time_t start_time;

/*
 * philosopher関数
 */
void *philosopher(void *num)
{
    int id;
    int i;
    int status;

    /*** 哲学者の番号 ***/
    id = *(int *)(num);

    /*** 無限ループ ***/
    while (1) {

        /*** 1秒以上5秒以下の時間待つ。 ***/
        sleep(rand() % 5 + 1); 

        //int pthread_mutex_lock(pthread_mutex_t *mutex);
        //mutex	ロックするmutexオブジェクトのアドレス
        //返り値は成功の時0、失敗の時0でないエラーコード。
        /*** 哲学者は自分の左側の箸を確保する。 ***/
        status = pthread_mutex_lock(&chopsticks[id]);

        /*** 哲学者が自分の左側の箸を取れなかった時の処理 ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot lock a mutex.\n");
            exit(EXIT_FAILURE);
        }

        /*** 箸は哲学者に確保された。 ***/
        chopsticks_status[id] = 1;
 
        /*** 哲学者は自分の右側の箸を確保する。 ***/
        status = pthread_mutex_lock(&chopsticks[(id + 1) % PHILOSOPHERS]);

        /*** 哲学者が自分の右側の箸を取れなかった時の処理 ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot lock a mutex.\n");
            exit(EXIT_FAILURE);
        }

        /*** 箸は哲学者に確保された。 ***/
        chopsticks_status[(id + 1) % PHILOSOPHERS] = 1;

        /*** 哲学者は食事を始める。 ***/
        philosophers_status[id] = 1;

        /*** 哲学者の状態を表示する。 ***/
        for (i = 0; i <= PHILOSOPHERS - 1; i++) {
            printf("%d", philosophers_status[i]);
        }

        /*** スペースを表示 ***/
        printf("  ");

        /*** 箸の状態を表示する。 ***/
        for (i = 0; i <= PHILOSOPHERS - 1; i++) {
            printf("%d", chopsticks_status[i]);
        }

        /*** 改行 ***/
        printf("\n");

        /*** 1秒以上10秒以下の時間待つ。 ***/
        sleep(rand() % 10 + 1);

        /*** 哲学者は食事をやめる。 ***/
        philosophers_status[id] = 0;

        /*** 箸は元の場所に戻される。 ***/
        chopsticks_status[id] = 0;

        //int pthread_mutex_unlock(pthread_mutex_t *mutex);
        //mutex ロックを解除するmutexオブジェクト
        //返り値は成功の時0、失敗の時0でないエラーコード。
        /*** 哲学者は箸を一本自分の左側に置く。 ***/
        status = pthread_mutex_unlock(&chopsticks[id]);

        /*** 箸を元の場所に置けなかった時の処理。 ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot unlock a mutex.\n");
            exit(EXIT_FAILURE);
        }

        /*** 箸は元の場所に戻される。 ***/
        chopsticks_status[(id + 1) % PHILOSOPHERS] = 0;

        /*** 哲学者は箸を一本自分の左側に置く。 ***/
        status = pthread_mutex_unlock(&chopsticks[(id + 1) % PHILOSOPHERS]);

        /*** 箸を元の場所に置けなかった時の処理。 ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot unlock a mutex.\n");
            exit(EXIT_FAILURE);
        }

    }
}

void *timer_function(void *dummy)
{
    while(1)if(time(NULL) - start_time > EXIT_TIME)exit(EXIT_SUCCESS);
    return NULL;
}

/*
 * プログラムの開始点
 */
int main(void)
{
    pthread_t philosophers[PHILOSOPHERS];
    pthread_t timer_thread;
    int i;
    int status;

    //現在時刻取得
    time(&start_time);

    //int pthread_init(pthread_mutex_t *mutex, pthread_mutexattr_t *attr);
    //mutex	ロックする資源があるアドレス
    //attr	属性
    //返り値は成功した時0、失敗した時-1。
    /*** mutexオブジェクトを初期化する。 ***/
    for (i = 0; i <= PHILOSOPHERS - 1; i++) {
        pthread_mutex_init(&chopsticks[i], NULL);
    }
    
    /***  ***/
    for (i = 0; i <= PHILOSOPHERS - 1; i++) {
        /*** スレッド（哲学者）を生成する。 ***/
        number[i] = i;
        status = pthread_create(&philosophers[i], NULL, 
            philosopher, (void *)&number[i]);

        /*** スレッド（哲学者）の生成に失敗した時の処理。 ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot create a thread.\n");
            exit(EXIT_FAILURE);
        }
    }

    if(pthread_create(&timer_thread, NULL, timer_function, NULL) != 0) {
        fprintf(stderr, "Error: cannot create a thread.\n");
        exit(EXIT_FAILURE);
    }

    /*** スレッド（哲学者）の終了を待つ。 ***/
    for (i = 0; i <= PHILOSOPHERS - 1; i++) {
        pthread_join(philosophers[i], NULL);
    }

    pthread_join(timer_thread, NULL);

    /*** 正常終了 ***/
    return(EXIT_SUCCESS);
}
