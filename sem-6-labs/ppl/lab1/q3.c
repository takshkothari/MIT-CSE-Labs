#include<mpi.h>
#include<stdio.h>
int main(int argc, char* argv[]) {
    int a = atoi(argv[1]), b = atoi(argv[2]), x, rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(rank == 0)
        x = a + b;
    else if(rank == 1)
        x = a-b;
    else if(rank == 2)
        x = a*b;
    else
        x = a/b;
    printf("Output : %d\n", x);
    MPI_Finalize();
    return 0;
}