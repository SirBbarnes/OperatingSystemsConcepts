#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *FibSeq(void *ptr);
void *FibPrint(void *ptr);
int num, i, a[100];

int main() {
    printf("Enter length of Fibonacci Sequence: ");
    scanf("%d", &num);

    if(num < 2) {
        printf("Number must be >= 2");
        return 1;
    }


    pthread_t child_t, parent_t;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&child_t,&attr, FibSeq, NULL);
    pthread_join(child_t, NULL);

    pthread_create(&parent_t,&attr, FibPrint, NULL);
    pthread_join(parent_t, NULL);


    exit(EXIT_SUCCESS);
}

void *FibSeq(void *ptr) {
    a[0] = 0; a[1] = 1;
    for (i = 2; i < num; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }

    pthread_exit(0);
}

void *FibPrint(void *ptr) {
    for(i = 0; i < num; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    pthread_exit(0);
}
