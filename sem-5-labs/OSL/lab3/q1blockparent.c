#include "include.h"
void main() {
    int status;
    pid_t pid;
    pid = fork();
    if(pid == -1)
        printf("\nERROR child not created");
    else if (pid == 0) /* child process */ {
        printf("\nI'm the child!");
        exit(0);
    }
    else /* parent process */ {
        wait(&status);
        printf("\nI'm the parent!");
        printf("\nChild returned: %d\n", status);
    }
}