#include <stdio.h>
#include <string.h>
#include<stdlib.h>


void main() {
    char m[20], n[20];
    int i, j, opc = 0, x = 0;
    printf("enter string ");
    scanf("%s", m);
    printf("enter smaller string ");
    scanf("%s", n);
    for (i=0; i < strlen(m); i++){
        while(j < strlen(n)){
            opc++;
            if(m[i+j] == n[j]){
                j++;
                if(j == strlen(n)){
                    x = 1;
                }
            }
            else
                break;
        }
        if(x == 1)
            break;
    }
    printf("%d", x);
    printf("\nopcount is %d", opc);
}