__kernel void selectsort(__global int *A, __global int *B) {
    int pos = 0, tid = get_global_id(0), data = A[tid], n = get_global_size(0);
    for(int i = 0; i < n; i++) {
        if(A[i] < data || (A[i] == data && i < tid))
            pos++;
    }
    B[pos] = data;
}