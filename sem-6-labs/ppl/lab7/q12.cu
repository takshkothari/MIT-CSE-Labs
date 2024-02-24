#include<stdio.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void vectorAdd_q1A(int *A, int *B,int *C) {
	int tid=blockIdx.x;
		C[tid]=A[tid]+B[tid];
}

__global__ void vectorAdd_q1B(int *A, int *B,int *C) {
	int tid=threadIdx.x;
		C[tid]=A[tid]+B[tid];
}

__global__ void vectorAdd_q2(int *A, int *B,int *C,int n) {
	int tid=blockIdx.x*blockDim.x+threadIdx.x;
	if(tid<n)
		C[tid]=A[tid]+B[tid];
}

int main(void) {
	int n;

	printf("Enter number of elements: ");
	scanf("%d",&n);

	int *h_A,*h_B,*h_C;
	int *d_A, *d_B, *d_C;
	
	int size = sizeof(int)*n;

	h_A=(int*)malloc(sizeof(size));
	h_B=(int*)malloc(sizeof(size));
	h_C=(int*)malloc(sizeof(size));

	cudaMalloc((void **)&d_A, size);
	cudaMalloc((void **)&d_B, size);
	cudaMalloc((void **)&d_C, size);

	printf("vector 1: ");
	for(int i=0;i<n;i++)
		scanf("%d",&h_A[i]);

	printf("vector 2: ");
	for(int i=0;i<n;i++)
		scanf("%d",&h_B[i]);


	cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);
	
	dim3 dimGrid_q1A(n,1,1);
	dim3 dimBlock_q1A(1,1,1);

	vectorAdd_q1A<<<dimGrid_q1A,dimBlock_q1A>>>(d_A,d_B,d_C);
	
	cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

	printf("result q1a: ");
	for(int i=0;i<n;i++)
		printf("%d ",h_C[i]);

	printf("\n");

	dim3 dimGrid_q1B(1,1,1);
	dim3 dimBlock_q1B(n,1,1);

	vectorAdd_q1B<<<dimGrid_q1B,dimBlock_q1B>>>(d_A,d_B,d_C);
	
	cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

	printf("result q1b: ");
	for(int i=0;i<n;i++)
		printf("%d ",h_C[i]);

	printf("\n");

	dim3 dimGrid_q2(ceil(n/256.0),1,1);
	dim3 dimBlock_q2(256,1,1);

	vectorAdd_q2<<<dimGrid_q2,dimBlock_q2>>>(d_A,d_B,d_C,n);
	
	cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

	printf("result q2: ");
	for(int i=0;i<n;i++)
		printf("%d ",h_C[i]);

	cudaFree(d_A);
	cudaFree(d_B);
	cudaFree(d_C);
	return 0;
}