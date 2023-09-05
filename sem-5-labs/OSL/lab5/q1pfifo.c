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
#define TEN_MEG (1024 * 1024 * 10)

int main() {
    int pipe_fd;
    int res,i;
    int open_mode = O_WRONLY;
    int bytes_sent = 0;
    int buffer[BUFFER_SIZE + 1];
    if(access(FIFO_NAME,F_OK)== -1){
        res = mkfifo(FIFO_NAME,0777);
        if(res!=0){
            fprintf(stderr,"could not create fifo %s\n",FIFO_NAME);
            exit(EXIT_FAILURE);
        }
    }
    printf("Process %d opening FIFO O_WRONGLY\n",getpid());
    pipe_fd = open(FIFO_NAME,open_mode);
    printf("Process %d result %d\n",getpid(),pipe_fd);
    if(pipe_fd != -1){
        printf("enter the numbers ");
        for(i=0;i<5;i++){
            scanf("%d",&buffer[i]);
            res = write(pipe_fd,&buffer[i],sizeof(buffer[0]));
        }
    }
    else{
        exit(EXIT_FAILURE);
    }
    printf("Process %d finished \n",getpid());
    exit(EXIT_SUCCESS);
}