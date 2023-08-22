#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORTNO 10202

int server_fd, new_socket, addrlen, valread, i, j;
struct sockaddr_in address;
int num[3] = {0};
float result = 0;
char msg[100];

void CreateServerSocket() {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = htons(PORTNO);
    addrlen = sizeof(address);
}

void PerformServerTask() {
    bind(server_fd, (struct sockaddr *)&address, addrlen);
    printf("Server Waiting....\n");
    listen(server_fd, 5);
    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (fork() == 0) {
            valread = read(new_socket, num, sizeof(num));
            if (num[1] == 1)
                result = num[0] + num[2];
            else if (num[1] == 2)
                result = num[0] - num[2];
            else if (num[1] == 3)
                result = (num[0]) * (num[2]);
            else if (num[1] == 4)
                result = (num[0]) / (num[2]);

            printf("\nOpeartion performed.\n");
            printf("Result calculated: %0.2f\n", result);
            memset(msg, 0, sizeof(msg));
            sprintf(msg, "The result of the operation is: %0.2f", result);
            send(new_socket, &msg, sizeof(msg), 0);
            close(new_socket);
            exit(0);
        }
        else
            close(new_socket);
    }
}

int main() {
    CreateServerSocket();
    PerformServerTask();
    shutdown(server_fd, SHUT_RDWR);
    return 0;
}