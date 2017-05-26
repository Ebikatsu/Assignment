#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define PHILOSOPHERS 4

pthread_mutex_t chopsticks[PHILOSOPHERS];
int philosophers_status[PHILOSOPHERS] = {0};
int chopsticks_status[PHILOSOPHERS] = {0};
int number[PHILOSOPHERS];

/*
 * philosopher関数
 */
void philosopher(int *num)
{
    int id;
    int i;
    int status;

    /***  ***/
    id = *(int *)(num);

    /*** 無限ループ ***/
    while (1) {

        /***  ***/
        sleep(rand() % 5 + 1); 

        /***  ***/
        status = pthread_mutex_lock(&chopsticks[id]);

        /***  ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot lock a mutex.\n");
            exit(EXIT_FAILURE);
        }

        /***  ***/
        chopsticks_status[id] = 1;
 
        /***  ***/
        status = pthread_mutex_lock(&chopsticks[(id + 1) % PHILOSOPHERS]);

        /***  ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot lock a mutex.\n");
            exit(EXIT_FAILURE);
        }

        /***  ***/
        chopsticks_status[(id + 1) % PHILOSOPHERS] = 1;

        /***  ***/
        philosophers_status[id] = 1;

        /***  ***/
        for (i = 0; i <= PHILOSOPHERS - 1; i++) {
            printf("%d", philosophers_status[i]);
        }

        /*** スペースを表示 ***/
        printf("  ");

        /***  ***/
        for (i = 0; i <= PHILOSOPHERS - 1; i++) {
            printf("%d", chopsticks_status[i]);
        }

        /*** 改行 ***/
        printf("\n");

        /***  ***/
        sleep(rand() % 10 + 1);

        /***  ***/
        philosophers_status[id] = 0;

        /***  ***/
        status = pthread_mutex_unlock(&chopsticks[id]);

        /***  ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot unlock a mutex.\n");
            exit(EXIT_FAILURE);
        }

        /***  ***/
        chopsticks_status[id] = 0;

        /***  ***/
        status = pthread_mutex_unlock(&chopsticks[(id + 1) % PHILOSOPHERS]);

        /***  ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot unlock a mutex.\n");
            exit(EXIT_FAILURE);
        }

        /***  ***/
        chopsticks_status[(id + 1) % PHILOSOPHERS] = 0;
    }
}

/*
 * プログラムの開始点
 */
int main(void)
{
    pthread_t philosophers[PHILOSOPHERS];
    int i;
    int status;

    /***  ***/
    for (i = 0; i <= PHILOSOPHERS - 1; i++) {
        pthread_mutex_init(&chopsticks[i], NULL);
    }
    
    /***  ***/
    for (i = 0; i <= PHILOSOPHERS - 1; i++) {
        /***  ***/
        number[i] = i;
        status = pthread_create(&philosophers[i], NULL, 
            (void *)philosopher, (void *)&number[i]);

        /***  ***/
        if (status != 0) {
            fprintf(stderr, "Error: cannot create a thread.\n");
            exit(EXIT_FAILURE);
        }
    }

    /***  ***/
    for (i = 0; i <= PHILOSOPHERS - 1; i++) {
        pthread_join(philosophers[i], NULL);
    }

    /*** 正常終了 ***/
    return(EXIT_SUCCESS);
}
