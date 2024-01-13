#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	int rank, size, num;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank == 0){
		for(int i = 1; i<size; i++)
			MPI_Send(&i, 1, MPI_INT, i, i, MPI_COMM_WORLD);
	}
	else{
		MPI_Recv(&num, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
		printf("received %d in p%d\n", num, rank);
	}
	MPI_Finalize();
	return 0;
}