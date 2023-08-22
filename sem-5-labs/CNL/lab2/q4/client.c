//Program by Taksh Kothari, 210905338, CSE A, Sem 5
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORTNO 10200

int main(){
	int socket_id = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(PORTNO);
	
	int result = connect(socket_id, (struct sockaddr*)&address, sizeof(address));
	
	if(result == -1){
		perror("\nClient Error");
		exit(0);
	}
	
	int process_id;
	char time_str[50];
	recv(socket_id, time_str, sizeof(time_str), 0);
	recv(socket_id, &process_id, sizeof(process_id), 0);
	
	printf("\nTime is : %s", time_str);
	printf("\nProcess ID: %d", process_id);
	close(socket_id);
}