#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
sem_t semaphore;
void *func1( void * param ) {
    printf( "Thread 1\n" );
    sem_post( &semaphore );
}
void *func2( void * param ) {
    sem_wait( &semaphore );
    printf( "Thread 2\n" );
}
int main() {
    pthread_t threads[2];
    sem_init( &semaphore, 0, 1 );
    pthread_create( &threads[0], 0, func1, 0 );
    pthread_create( &threads[1], 0, func2, 0 );
    pthread_join( threads[0], 0 );
    pthread_join( threads[1], 0 );
    sem_destroy( &semaphore );
}