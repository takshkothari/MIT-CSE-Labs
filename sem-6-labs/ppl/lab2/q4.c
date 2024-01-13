#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int n;
	if(rank == 0){
		printf("enter number: ");
		scanf("%d", &n);
		MPI_Send(&n, 1, MPI_INT, rank+1, rank+1, MPI_COMM_WORLD);
		MPI_Recv(&n, 1, MPI_INT, size-1, rank, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("p%d: %d\n", rank, n);
	}
	else{
		MPI_Recv(&n, 1, MPI_INT, rank-1, rank, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("p%d: %d\n", rank, n++);
		MPI_Send(&n, 1, MPI_INT, (rank+1)%size, (rank+1)%size, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}