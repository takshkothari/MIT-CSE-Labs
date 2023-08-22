#include <stdio.h>
#include <stdlib.h>

int warshall(int ** mat, int n, int c) {
    int i, j, flag;
    if (c == n) {
        for(i = 0; i < n; i++) {
            flag = 1;
            for(j = 0; j < n; j++) {
                if (mat[i][j] == 0)
                    flag = 0;
            }
            if (flag == 1)
                return 1;
        }
        return 0;
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if ((mat[i][j] == 1) || (mat[i][c] == 1 && mat[c][j] == 1))
                mat[i][j] = 1;
        }
    }
    return warshall(mat, n, c+1);
}

void main() {
    int i, j, n;
    printf("enter number of vertices ");
    scanf("%d", &n);
    int ** adjMat = (int **) malloc(n * sizeof(int *));
    for(i = 0; i < n; i++) 
        adjMat[i] = (int *) calloc(n, sizeof(int));
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Enter a[%d][%d] ", i, j);
            scanf("%d", &adjMat[i][j]);
        }
    }
    if (warshall(adjMat, n, 0) == 1) {
        printf("matrix exhibits transitive closure:\n");
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++)
                printf("%d ",adjMat[i][j]);
            printf("\n");
        }
    }
    else
        printf("matrix does not exhibit transitive closure\n");
}