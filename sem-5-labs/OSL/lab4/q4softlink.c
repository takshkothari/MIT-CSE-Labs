#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
void main() {
    char oldPath[100], newPath[100];
    printf("Old path: ");
    scanf("%s", oldPath);
    printf("New path: "); 
    scanf("%s", newPath);
    int res = symlink(oldPath, newPath);
    if (res == 0) {
        printf("Soft link created\n");
        res = unlink(oldPath);
        if (res == 0)
            printf("Unlinked Successfully\n");
        else
            printf("Error unlinking\n");
    }
    else
        printf("Error linking\n");
}