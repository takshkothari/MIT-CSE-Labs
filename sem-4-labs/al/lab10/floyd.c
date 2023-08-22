#include <stdio.h>
#include <stdlib.h>

void floyd(int ** mat, int n) {
    int i, j, k, flag;
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++)
                mat[i][j] = (mat[i][j] < (mat[i][k] + mat[k][j])) ? mat[i][j] : (mat[i][k] + mat[k][j]);
        }
    }
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
    floyd(adjMat, n);
    printf("all pairs shortest path is:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%d ", adjMat[i][j]);
        printf("\n");
    }

}