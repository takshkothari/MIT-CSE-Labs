#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0){
        int arr[size-1];
        printf("enter %d elements: ", size-1);
        for(int i = 0; i<size-1; i++)
            scanf("%d", &arr[i]);
        int buffer_size = MPI_BSEND_OVERHEAD + sizeof(int)*size-1;
        char *buffer = (char*)malloc(buffer_size);
        MPI_Buffer_attach(buffer, buffer_size);
        for(int i = 0; i<size-1; i++)
            MPI_Bsend(&arr[i], 1, MPI_INT, i+1, i+1, MPI_COMM_WORLD);
        MPI_Buffer_detach(&buffer, &buffer_size);
    }
    else{
        int n;
        MPI_Recv(&n, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        if (rank % 2 == 1)
            printf("p%d: %d\n", rank, n * n * n);
        else
            printf("p%d: %d\n", rank, n * n);
    }
    MPI_Finalize();
    return 0;
}