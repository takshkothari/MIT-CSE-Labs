#include <stdio.h>

__global__ void spmv_kernel(int* row_ptr, int* col_ind, int* values, int* x, int* y, int num_rows) {
    int row = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < num_rows) {
        int sum = 0;
        int row_start = row_ptr[row];
        int row_end = row_ptr[row + 1];

        for (int j = row_start; j < row_end; j++) {
            sum += values[j] * x[col_ind[j]];
        }

        y[row] = sum;
    }
}

int main() {
    int num_rows = 3;
    int num_cols = 3;
    int num_nonzeros = 6;

    int row_ptr[] = {0, 2, 5, 6};
    int col_ind[] = {0, 2, 0, 1, 2, 1};
    int values[] = {1, 2, 3, 4, 5, 6};

    int x[] = {1, 1, 1};
    int y[num_rows];

    int* d_row_ptr, * d_col_ind;
    int* d_values, * d_x, * d_y;

    cudaMalloc((void**)&d_row_ptr, (num_rows + 1) * sizeof(int));
    cudaMalloc((void**)&d_col_ind, num_nonzeros * sizeof(int));
    cudaMalloc((void**)&d_values, num_nonzeros * sizeof(int));
    cudaMalloc((void**)&d_x, num_cols * sizeof(int));
    cudaMalloc((void**)&d_y, num_rows * sizeof(int));

    cudaMemcpy(d_row_ptr, row_ptr, (num_rows + 1) * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_col_ind, col_ind, num_nonzeros * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_values, values, num_nonzeros * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_x, x, num_cols * sizeof(int), cudaMemcpyHostToDevice);

    int block_size = 256;
    int num_blocks = (num_rows + block_size - 1) / block_size;

    spmv_kernel<<<num_blocks, block_size>>>(d_row_ptr, d_col_ind, d_values, d_x, d_y, num_rows);

    cudaMemcpy(y, d_y, num_rows * sizeof(int), cudaMemcpyDeviceToHost);

    printf("Result:\n");
    for (int i = 0; i < num_rows; i++) 
        printf("%d\n", y[i]);

    cudaFree(d_row_ptr);
    cudaFree(d_col_ind);
    cudaFree(d_values);
    cudaFree(d_x);
    cudaFree(d_y);

    return 0;
}
