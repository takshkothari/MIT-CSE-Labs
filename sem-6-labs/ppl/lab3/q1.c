#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int rank, size, N, A[10], B[10], c, i, f;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0) {
		N = size;
		fprintf(stdout, "Enter %d values: \n", N);
		fflush(stdout);
		for(i = 0; i < N; i++)
			scanf("%d", &A[i]);
	}

	MPI_Scatter(A, 1, MPI_INT, &c, 1, MPI_INT, 0, MPI_COMM_WORLD);
	fprintf(stdout, "Received %d in process %d\n", c, rank);
	fflush(stdout);
	f = 1;
    for(i = 2; i <= c; i++)
        f *= i;
	MPI_Gather(&f, 1, MPI_INT, B, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank == 0) {
		// fprintf(stdout, "Result gathered in the root:\n");
		// fflush(stdout);
        int s = 0;
		for(i = 0; i < N; i++) 
            s += B[i];
			// fprintf(stdout, "%d\n", B[i]);
        fprintf(stdout, "Sum of factorials is: %d\n", s);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}