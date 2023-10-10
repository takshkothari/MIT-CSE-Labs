#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
 
/*
Status codes
0 -> nothing written yet by parent process
1 -> alphabet written by parent process
2 -> answer written by child process
-1 -> exit
*/
 
struct shared_str
{
    int status;
    char alphabet;
};
 
int main(int argc, char const *argv[]) {
    int shmid = shmget((key_t)1234,sizeof(struct shared_str),0666|IPC_CREAT);
    pid_t pid = fork();
    
    if(pid < 0)  {
        printf("Error in fork()\n");
        exit(-1);
    }
 
    else if(pid == 0) { //child process
        struct shared_str* shared_mem = shmat(shmid,(void*)0,0);
        
        if(shared_mem == (void*)-1)  {
            printf("shmat() failed\n");
            exit(-1);
        }
        
        printf("Memory attached at %p for child process\n",shared_mem);
        
        while(1) {
            if(shared_mem->status < 0) {
                // printf("Exit code received %d\n",shared_mem->status);
                if(shmdt(shared_mem) == -1) {
                    printf("shmdt failed\n");
                    exit(-1);
                }
                
                break;
            }
            
            if(shared_mem->status == 1) {
                char c = shared_mem->alphabet;
                printf("\n");
                
                if((int)c >= 65 && (int)c <= 90) { //uppercase
                    c = ((c - 'A' + 1)%26) + 'A';
                }
                
                else if((int)c >= 97 && (int)c <= 122) { //lowecase
                    c = ((c - 'a' + 1)%26) + 'a';
                }
                
                else {
                    printf("Non-alphabetic character received\n");
                    //do nothing
                }
                shared_mem->alphabet = c; //write to shared memory
                shared_mem->status = 2;
            }
        }
    }
    
    else { //parent process
        sleep(1);
        struct shared_str* shared_mem = shmat(shmid,(void*)0,0);
        
        if(shared_mem == (void*)-1) {
            printf("shmat() failed\n");
            exit(-1);
        }
        
        printf("Memory attached at %p for parent process\n",shared_mem);
        shared_mem->status = 0;
        
        while(1) {
            if(shared_mem->status == 1) {
                // printf("Waiting for child process\n");
                continue;
            }
            
            if(shared_mem->status == 2) {
                printf("%c\n",shared_mem->alphabet);
            }
            
            shared_mem->status = 0;
            char c,nl;
            printf("Enter an alphabet (0 to exit) : \n");
            scanf("%c",&c);
            scanf("%c",&nl);
            
            if(c == '0') {
                shared_mem->status = -1;
                printf("Bye Bye\n");
                
                if(shmdt(shared_mem) == -1) {
                    printf("shmdt failed\n");
                    exit(-1);
                }
                
                if(shmctl(shmid,IPC_RMID,0) == -1) {
                    printf("shmctl failed\n");
                    exit(-1);
                }
                break;
            }
            
            shared_mem->alphabet = c;
            shared_mem->status = 1;
        }
    }
    return 0;
}