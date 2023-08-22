#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <time.h>
#define PORTNO 10203

int sockfd, newsockfd, portno, clilen, n = 1;
struct sockaddr_in seraddr, cliaddr;
int i, value;
char buf[256];
time_t t;

void createServerSocket() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    seraddr.sin_port = htons(PORTNO);
    bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    listen(sockfd, 5);
}

void performServerTask() {
    while (1) {
        printf("Server Waiting\n");
        clilen = sizeof(clilen);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        if (fork() == 0) {
            n = read(newsockfd, buf, sizeof(buf));
            time(&t);
            printf("Current time and date are: %s", ctime(&t));
            // printf("%s", buf);
            n = write(newsockfd, &t, sizeof(&t));
            // n = read(newsockfd, buf, sizeof(buf));
            int x = getpid();
            printf("Process ID is: %d\n", x);
            n = write(newsockfd, &x, sizeof(&x));
            close(newsockfd);
            exit(0);
        }
        else
            close(newsockfd);
    }
}

int main() {
    createServerSocket();
    performServerTask();
    return 0;
}