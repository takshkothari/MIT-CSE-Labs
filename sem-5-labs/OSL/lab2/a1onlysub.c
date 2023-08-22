#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void listSubdirectories(char *dir) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    
    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr, "cannot open directory: %s\n", dir);
        return;
    }

    int count = 0;
    while((entry = readdir(dp)) != NULL) {
        char filepath[1024];
        sprintf(filepath, "%s/%s", dir, entry->d_name);

        if(stat(filepath, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if(S_ISDIR(statbuf.st_mode) &&
            strcmp(".", entry->d_name) != 0 &&
            strcmp("..", entry->d_name) != 0) {
            count++;
        }
    }
    closedir(dp);

    char **subdirs = (char **)malloc(count * sizeof(char *));
    int index = 0;

    dp = opendir(dir);
    while((entry = readdir(dp)) != NULL) {
        char filepath[1024];
        sprintf(filepath, "%s/%s", dir, entry->d_name);

        if (stat(filepath, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if(S_ISDIR(statbuf.st_mode) &&
            strcmp(".", entry->d_name) != 0 &&
            strcmp("..", entry->d_name) != 0) {
            subdirs[index++] = strdup(entry->d_name);
        }
    }
    closedir(dp);

    qsort(subdirs, count, sizeof(char *), compare);

    for(int i = 0; i < count; i++) {
        printf("%s\n", subdirs[i]);
        free(subdirs[i]);
    }
    free(subdirs);
}

int main() {
    listSubdirectories("/home/OS_Student/Desktop/tako");
    return 0;
}