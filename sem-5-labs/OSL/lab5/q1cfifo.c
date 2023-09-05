#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 6

int main() {
    int pipe_fd;
    int res,j;
    int open_mode = O_RDONLY;
    int buffer[BUFFER_SIZE+1];
    int bytes_read = 0;
    //memset(buffer,'\0',sizeof(buffer));
    printf("Process %d opening FIFO O_RDONLY\n",getpid());
    pipe_fd = open(FIFO_NAME,open_mode);
    printf("Process %d result %d\n",getpid(),pipe_fd);
    if(pipe_fd != -1){
        printf("The numbers are\n");
        for(j=0;j<5;j++){
            res = read(pipe_fd,&buffer[j],sizeof(buffer[0]));
            printf("%d\t",buffer[j]);
        }
        bytes_read+=res;
    }
    else{
        exit(EXIT_FAILURE);
    }
    printf("\nProcess %d finished %d bytes read\n",getpid(),bytes_read);
    exit(EXIT_SUCCESS);
}
