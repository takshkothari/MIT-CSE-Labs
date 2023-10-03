#include <pthread.h>
#include <stdio.h>
pthread_mutex_t mutex;
volatile int counter = 0;
void * count( void * param) {
    for (int i=0; i<100; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        printf("Count = %i\n", counter);
        pthread_mutex_unlock(&mutex);
    }
}
int main() {
    pthread_t thread1, thread2;
    pthread_mutex_init( &mutex, 0 );
    pthread_create( &thread1, 0, count, 0 );
    pthread_create( &thread2, 0, count, 0 );
    pthread_join( thread1, 0 );
    pthread_join( thread2, 0 );
    pthread_mutex_destroy( &mutex );
    return 0;
}