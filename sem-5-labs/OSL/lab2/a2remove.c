#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

void removeFiles() {
    DIR *dp;
    struct dirent *entry;
    char filename[1024];
    
    if ((dp = opendir(".")) == NULL) {
        perror("cannot open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {
            printf("Do you want to remove '%s'? (y/n): ", entry->d_name);
            char choice;
            scanf(" %c", &choice);

            if (choice == 'y' || choice == 'Y') {
                if (unlink(entry->d_name) == -1) {
                    perror("unlink");
                } else {
                    printf("Removed '%s'\n", entry->d_name);
                }
            }
        }
    }

    closedir(dp);
}

int main() {
    printf("This program will allow you to remove files in the current directory.\n");
    removeFiles();
    return 0;
}