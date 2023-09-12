#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int s;

void* child_thread(void * param) {
    int x = (int)param;
    if (x > 0)
        s = s + x;
    return 0;
}
int main(int argc, char*argv) {
    pthread_t thread[100];
    int return_value[100];
    int n, x;
    printf("Enter number of numbers ");
    scanf("%d", &n);
    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        pthread_create(&thread[i], 0, &child_thread, (void*)x);
        pthread_join(thread[i], (void**)&return_value[i]);
    }
    printf("Sum of non negative numbers is %d\n", s);
}