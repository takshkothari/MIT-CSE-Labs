#include "include.h"
int main() {
    pid_t pid;
    /* fork another process */
    pid = fork();
    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed");
        exit(-1);
    }
    else if (pid == 0) /* child process */
        execlp("./q1blockparent", "q1blockparent", NULL); 
    else { /* parent process */
    /* parent will wait for the child to complete */
        wait (NULL);
        printf ("Complete\n");
        exit(0);
    }
}