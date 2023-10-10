#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg_st {
    long int my_msg_type;
    int num;
};
int main() {
    int running = 1;
    int msgid;
    struct my_msg_st some_data;
    long int msg_to_receive = 0;
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid == -1) {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    while(running) {
        if (msgrcv(msgid, (void *)&some_data, BUFSIZ, msg_to_receive, 0) == -1) {
            fprintf(stderr, "msgrcv failed with error: %d\n", errno);
            exit(EXIT_FAILURE);
        }
        
        printf("You wrote: %d\n", some_data.num);
        int t = some_data.num;
        int rev = 0, r;
        while (t > 0) {
            r = t % 10;
            rev = rev * 10 + r;
            t = t / 10;
        }
        if (rev == some_data.num)
            printf("Palindrome\n");
        else
            printf("Not Palindrome\n");

        if (some_data.num == -1) {
            running = 0;
        }

    }
    if (msgctl(msgid, IPC_RMID, 0) == -1) {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}