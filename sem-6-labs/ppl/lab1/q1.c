#include<mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int x = atoi(argv[1]), rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int val = 1;
    for (int i = 0; i < rank; i++)
        val *= x;
    printf("Power of %d , %d is %d\n", x, rank, val);
    MPI_Finalize();
    return 0;
}