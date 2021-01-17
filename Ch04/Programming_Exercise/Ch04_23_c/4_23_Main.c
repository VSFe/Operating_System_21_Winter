/** 
 * @file 4.23_Main.c
 * @brief Solution code of Operating System Concepts 10e Excercise 4.23
 * @date 2021-01-17
 * 
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

void *printPrime (void *param);

int main (int argc, char *argv[]) {
    pthread_t tid;
    pthread_attr_t attr;

    if(argc != 2) {
        fprintf(stderr, "usage: test <Integer value>\n");
        return -1;
    }

    if(atoi(argv[1]) <= 0) {
        fprintf(stderr, "%d must be > 0\n", atoi(argv[1]));
        return -1;
    }

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, printPrime, argv[1]);
    pthread_join(tid, NULL);
}

void *printPrime (void *param) {
    int size = atoi((char*)param);
    bool *isPrime = (bool*)malloc(sizeof(bool) * (size + 1));
    memset(isPrime, 1, sizeof(isPrime) * size);

    for(long long i = 3; i <= size; i += 2) {
        if(isPrime[i]) {
            printf("%d\n", i);
            for(long long j = i * i; j <= size; j += i)
                isPrime[j] = false;                
        }
    }

    free(isPrime);
    pthread_exit(0);
}