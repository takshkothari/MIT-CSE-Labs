#include<mpi.h>
#include<stdio.h>
#include<string.h>

void toggle(int n, char* word){
	for(int i = 0; i<n; i++){
		if(word[i]>='a' && word[i]<='z'){
			word[i] -= 32;
		}
		else if(word[i]>='A' && word[i]<='Z'){
			word[i] += 32;
		}
	}
}

int main(int argc, char* argv[]) {
    int rank, size, l;
    char w[100];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;
    if(rank == 0) {
        printf("enter word: ");
        scanf("%s", w);
        l = strlen(w);
        MPI_Ssend(&l, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Ssend(w, l, MPI_CHAR, 1, 1, MPI_COMM_WORLD);
        fprintf(stdout, "sending %s from p1 \n", w);
        MPI_Recv(w, l, MPI_CHAR, 1, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        fprintf(stdout, "received %s from p2\n", w);
        fflush(stdout);
    }
    else {
        MPI_Recv(&l, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(w, l, MPI_CHAR, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        // fprintf(stdout, "received %s from p1\n", w);
        toggle(l, w);
        MPI_Ssend(w, l, MPI_CHAR, 0, 2, MPI_COMM_WORLD);
        // fprintf(stdout, "sending %s from p2 \n", w);
        fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}