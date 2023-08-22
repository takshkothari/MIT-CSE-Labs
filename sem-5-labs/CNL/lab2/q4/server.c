//Program by Taksh Kothari, 210905338, CSE A, Sem 5
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#define PORTNO 10200

int main(){
	int socket_id = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in serveraddress;
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	serveraddress.sin_port = htons(PORTNO);
	
	bind(socket_id, (struct sockaddr*)&serveraddress, sizeof(serveraddress));
	listen(socket_id, 5);
	
	while(1){
		struct sockaddr_in clientaddress;
		int client = sizeof(clientaddress);
		int new_socket_id = accept(socket_id, (struct sockaddr*)&clientaddress, &client);
		
		int parent_id = fork();
		
		if(parent_id == 0){
			char time_str[50];
			time_t current_time;  // time_t is a data type that represents calendar time
			struct tm *time_info; // holds components of the calendar time like day, month, year. Used to convert time_t into readable format
			time(&current_time);
			time_info = localtime(&current_time);
			
			strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info); // Converts time into a string
			
			int process_id = getpid();
			send(new_socket_id, time_str, sizeof(time_str), 0);
			send(new_socket_id, &process_id, sizeof(process_id), 0);
			
			close(new_socket_id);
			exit(0);					
		}
		
		else{
			wait(NULL);
		}
	}
	close(socket_id);
}