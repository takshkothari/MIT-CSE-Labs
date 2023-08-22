#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORTNO 10202

int sock, addrlen, client_fd, valread;
struct sockaddr_in address;
int num[3] = {0};
char result[100] = {0};

void CreateClientSocket() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(PORTNO);
    addrlen = sizeof(address);
}

void PerformClientTask() {
    client_fd = connect(sock, (struct sockaddr *)&address, addrlen);
    if (client_fd == -1) {
        perror("\nCLIENT ERROR");
        exit(1);
    }
    printf("Enter first operand: ");
    scanf("%d", &(num[0]));
    printf("1: +\n2: -\n3. *\n4. /\nEnter choice: ");
    scanf("%d", &(num[1]));
    printf("Enter second operand: ");
    scanf("%d", &(num[2]));
    send(sock, num, sizeof(num), 0);
    printf("Opeartors and Operands sent.\n");
    valread = read(sock, &result, sizeof(result));
    printf("%s\n", result);
}

int main() {
    CreateClientSocket();
    PerformClientTask();
    close(client_fd);
    return 0;
}