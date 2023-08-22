#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

int main(){
	char buff[256];
	int n = 1;

	while(1){
		int socket_id = socket(AF_INET, SOCK_STREAM, 0);
		struct sockaddr_in address;
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = inet_addr("127.0.0.1");
		address.sin_port = htons(10200);
		int result = connect(socket_id, (struct sockaddr*)&address, sizeof(address));
		
	        if(result == -1){
			perror("\nClient Error");
			exit(1);
		}
			
		char str[256];
		printf("\nEnter String: ");
		scanf("%s", str);
		
		if(strcmp(str, "Stop") == 0)
			exit(1);
		
		write(socket_id, str, sizeof(str)); 
		
		read(socket_id, buff, sizeof(buff));
		puts(buff);
		close(socket_id);
	}		
}	