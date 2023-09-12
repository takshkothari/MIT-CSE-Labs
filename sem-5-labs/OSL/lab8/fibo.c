#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int fib[100];

void* child_thread(void * param) {
    int id = (int)param;
    if (id == 0 || id == 1)
        fib[id] = id;
    else {
        fib[id] = fib[id - 1] + fib[id - 2];
    }
    return (void *)id;
}
int main() {
    pthread_t thread[100];
    int return_value[100];
    int n;
    printf("Enter number of Fibo numbers ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pthread_create(&thread[i], 0, &child_thread, (void*)i);
        pthread_join(thread[i], (void**)&return_value[i]);
    }
    printf("Fibo sequence: ");
    for (int i = 0; i < n; i++)
        printf("%d ", fib[i]);
}