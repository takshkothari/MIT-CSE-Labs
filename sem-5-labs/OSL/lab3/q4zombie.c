// run code
// ctrl z
// bg
// ps

#include "include.h"

int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "no child oops");
        exit(-1);
    }
    else if (pid == 0) {
        printf("\nI'm the child!");
        printf("\npid is %d\nppid is %d", getpid(), getppid());
        exit(0);
    }
    else { 
        sleep(200);
        printf ("Complete\n");
        exit(0);
    }
}