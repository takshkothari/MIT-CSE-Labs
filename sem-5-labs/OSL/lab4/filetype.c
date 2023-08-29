#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
int main (int argc, char *argv[]) {
    struct stat sb;
    int ret;
    if (argc < 2) {
        fprintf (stderr, "usage: %s <file>\n", argv[0]);
        return 1;
    }
    ret = stat (argv[1], &sb);
    if (ret) {
        perror ("stat");
        return 1;
    }
    printf ("File type: ");
    switch (sb.st_mode & __S_IFMT) {
        case __S_IFBLK:
            printf("block device node\n");
            break;
        case __S_IFCHR:
            printf("character device node\n");
            break;
        case __S_IFDIR:
            printf("directory\n");
            break;
        case __S_IFIFO:
            printf("FIFO\n");
            break;
        case __S_IFLNK:
            printf("symbolic link\n");
            break;
        case __S_IFREG:
            printf("regular file\n");
            break;
        case __S_IFSOCK:
            printf("socket\n");
            break;
        default:
            printf("unknown\n");
            break;
    }
    return 0;
}