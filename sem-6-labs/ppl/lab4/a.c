#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <time.h>
 
int main(int argc, char* argv[]){
int i,id, np,N;
double x, y,double_N,eTime,sTime,pTime;
int lhit;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &id);
MPI_Comm_size(MPI_COMM_WORLD, &np);
 
if( argc !=2){
if (id==0){
fprintf(stderr,"Incorrect NARGIN\n");
fflush(stderr);
}
MPI_Abort(MPI_COMM_WORLD,1);
}
 
sscanf(argv[1], "%lf", &double_N);
N = lround(double_N);
MPI_Barrier(MPI_COMM_WORLD);
sTime = MPI_Wtime();
lhit = 0;
srand((unsigned)(time(0)));
int lN = N/np;
 
for(i = 0; i<lN;i++){
x = ((double)rand())/((double)RAND_MAX);
y = ((double)rand())/((double)RAND_MAX);
if (((x*x) + (y*y)) <= 1) lhit++;
}
 
int hit=0;
MPI_Allreduce(&lhit,&hit,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
double est;
est = (hit*4)/((double)N);
MPI_Barrier(MPI_COMM_WORLD);
 
eTime = MPI_Wtime();
pTime = fabs(eTime - sTime);
 
if (id == 0) {
printf("Number of Points Used:      %d\n",N);
printf("Estimate of Pi:         %24.16f\n",est);
printf("Elapsed Wall time:      %5.3e\n",pTime);
}
 
MPI_Finalize();
return 0;
}