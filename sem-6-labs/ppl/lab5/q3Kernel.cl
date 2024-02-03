__kernel void adjswap(__global int *A) {
    int i = get_global_id(0);
    if(i % 2 == 0) {
        int t = A[i];
        A[i] = A[i+1];
        A[i+1] = t;
    }
}