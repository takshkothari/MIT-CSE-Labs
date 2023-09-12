#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int n, pr[100];

void* child_thread(void * param) {
    int x = (int)param;
    for(int i = 2; i < x; i++) {
        if(x % i == 0)
            return 0;
    }
    pr[n++] = x;
    return 0;
}
int main() {
    pthread_t thread[100];
    int return_value[100];
    n = 0;
    int l, u;
    printf("Enter lower limit ");
    scanf("%d", &l);
    printf("Enter upper limit ");
    scanf("%d", &u);
    for (int i = l; i < u; i++) {
        pthread_create(&thread[i], 0, &child_thread, (void*)i);
        pthread_join(thread[i], (void**)&return_value[i]);
    }
    printf("Prime Numbers in the range: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", pr[i]);
}