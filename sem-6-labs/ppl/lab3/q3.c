#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	int rank, size, res, l;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	char string[100], *str;
	if (rank == 0){
		printf("Enter string: ");
		scanf("%s", string);
		l = strlen(string);
		l /= size;
	}

	MPI_Bcast(&l, 1, MPI_INT, 0, MPI_COMM_WORLD);
	str = (char *)calloc(l, sizeof(char));
	MPI_Scatter(string, l, MPI_CHAR, str, l, MPI_CHAR, 0, MPI_COMM_WORLD);
	int c = 0;
	for (int i = 0; i < l; i++){
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
			c++;
	}
	c = l - c;
	printf("Process %d has %d non-vowels\n",rank,c);
	MPI_Reduce(&c, &res, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank == 0)
		printf("The total non-vowels are : %d\n", res);

	free(str);
	MPI_Finalize();
	return 0;
}