/**
 * @file 4.22_Main.c
 * @brief Solution code of Operating System Concepts 10e Excercise 4.22
 * @date 2021-01-17
 * 
 */


#include <pthread.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int sum_result, min_result, max_result;
void *sum (void *param);
void *min (void *param);
void *max (void *param);

typedef struct node {
    int cnt;
    char **datas;
} node;

int main (int argc, char *argv[]) {
    pthread_t tid[3];
    pthread_attr_t attr[3];

    if (argc == 1) {
        fprintf(stderr, "usage: a.out <integer value>\n");
        return -1;
    }

    if (atoi(argv[1]) < 0) {
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
        return -1;
    }

    node test = {argc, argv};

    for(int i = 0; i < 3; i++) pthread_attr_init(&attr[i]);
    pthread_create(&tid[0], &attr[0], sum, &test);
    pthread_create(&tid[1], &attr[1], min, &test);
    pthread_create(&tid[2], &attr[2], max, &test);
    for(int i = 0; i < 3; i++) pthread_join(tid[i], NULL);

    printf("The average value is = %d\n", sum_result / argc);
    printf("The minimum value is = %d\n", min_result);
    printf("The maximum value is = %d\n", max_result);
}

void *sum (void *param) {
    node *nodePointer = (node*)param;

    int cnt = nodePointer->cnt;
    char **datas = nodePointer->datas;
    sum_result = 0;

    for(int i = 1; i < cnt; i++) {
        sum_result += atoi(datas[i]);
    }
    pthread_exit(0);
}

void *min (void *param) {
    node *nodePointer = (node*)param;

    int cnt = nodePointer->cnt;
    char **datas = nodePointer->datas;
    min_result = INT_MAX;

    for(int i = 1; i < cnt; i++) {
        if(min_result > atoi(datas[i]))
            min_result = atoi(datas[i]);
    }
    pthread_exit(0);
}

void *max (void *param) {
    node *nodePointer = (node*)param;

    int cnt = nodePointer->cnt;
    char **datas = nodePointer->datas;
    max_result = INT_MIN;

    for(int i = 1; i < cnt; i++) {
        if(max_result < atoi(datas[i]))
            max_result = atoi(datas[i]);
    }
    pthread_exit(0);
}