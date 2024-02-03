__kernel void b2d(__global int *A, __global int *B) {
    int i = get_global_id(0);
    B[i] = 0;
    int t = A[i], rem, j = 1;
    while(t)  
    {  
        rem = t % 10;  
        t = t / 10; 
        B[i] = B[i] + rem * j;  
        j *= 2; 
    }
}