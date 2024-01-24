#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argv, char *argc[]){
	int rank, size, *n, *arr, res, m;

	MPI_Init(&argv, &argc);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	if (rank == 0){
		printf("Enter M: ");
		scanf("%d", &m);
		n = (int *)calloc(size * m, sizeof(int));
		printf("Enter %d numbers: ", size * m);
		for (int i = 0; i < size * m; i++)
			scanf("%d", &n[i]);
	}

	MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
	arr = (int *)calloc(m, sizeof(int));
	MPI_Scatter(n, m, MPI_INT, arr, m, MPI_INT, 0, MPI_COMM_WORLD);
	
	int s = 0;
	for (int i = 0; i < m; i++)
		s += arr[i];

	s /= m;
	MPI_Reduce(&s, &res, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	
	if (rank == 0){
		printf("The average is %d\n", res / size);
		free(n);
	}
	free(arr);
	MPI_Finalize();
	return 0;
}