/** 
 * @file 4.27_Main.c
 * @brief Solution code of Operating System Concepts 10e Excercise 4.27
 * @date 2021-01-17
 * 
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void *getFibo (void *param);

int *fibo_table;

int main (int argc, char *argv[]) {
    pthread_t fiboMain;
    int size;

    if(argc != 2) {
        fprintf(stderr, "usage: a.out <integer value>\n");
        return -1;
    }

    if (atoi(argv[1]) < 0) {
        fprintf(stderr, "%d must be > 0\n", atoi(argv[1]));
        return -1;
    }

    size = atoi(argv[1]) - 1;
    fibo_table = (int*)malloc(sizeof(int) * (size + 1));
    memset(fibo_table, -1, sizeof(int) * (size + 1));
    fibo_table[0] = 1, fibo_table[1] = 1;

    pthread_create(&fiboMain, NULL, getFibo, &size);
    pthread_join(fiboMain, NULL);

    printf("%d\n", fibo_table[size]);
    
    free(fibo_table);
    return 0;
}

void *getFibo (void *param) {
    int target_index = *((int*)param);

    if(fibo_table[target_index] == -1) {
        pthread_t fibo_left, fibo_right;
        int left = target_index - 2, right = target_index - 1;

        /*
        Prevent Race Condition.
        We will cover this issue Ch.05
        */

        pthread_create(&fibo_left, NULL, getFibo, &left);
        pthread_join(fibo_left, NULL);

        pthread_create(&fibo_right, NULL, getFibo, &right);
        pthread_join(fibo_left, NULL);

        fibo_table[target_index] = fibo_table[target_index - 1] + fibo_table[target_index - 2];
    }

    pthread_exit(0);
}