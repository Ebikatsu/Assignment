#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 5    /* スレッド数 */
#define WAKEUP  10   /* 休眠・起床回数 */

int number[THREADS];

void run(void *);

int sum;
pthread_mutex_t mutex;

/*
   プログラムの開始点
*/
int main(void)
{
    pthread_t thread[THREADS];
    int i;      //ループ用
    int status; //返り値確認用

    sum = 0;
    pthread_mutex_init(&mutex,NULL);

    srand(time(NULL));

    for (i = 0; i <= THREADS - 1; i++) {
        number[i] = i;
        status = pthread_create(&thread[i], NULL,
            (void *)run, (void *)(&number[i]));

        if (status != 0) {
	    fprintf(stderr,
	      "Error: cannot create a thread.\n");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i <= THREADS - 1; i++) {
        pthread_join(thread[i], NULL);
    }
    printf("sum = %d\n",sum);

    return(EXIT_SUCCESS);
}


/*
  スレッド関数
*/
void run(void *num)
{
    int number;
    //int local_sum;

    number = *(int *)(num);

    //local_sum = sum;
    sleep(rand() % 5 + 1);
    if(pthread_mutex_lock(&mutex) != 0) {
        fprintf(stderr, "Error: cannot lock a mutex.\n");
        exit(EXIT_FAILURE);
    }
    //sum = local_sum + number;
    sum += number;
    if(pthread_mutex_unlock(&mutex) != 0) {
        fprintf(stderr, "Error: cannot unlock a mutex.\n");
        exit(EXIT_FAILURE);
    }

}
