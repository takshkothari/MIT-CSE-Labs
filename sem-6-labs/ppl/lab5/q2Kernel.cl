__kernel void b1comp(__global int *A, __global int *B) {
    int i = get_global_id(0);
    B[i] = 0;
    int t = A[i], rem = 0, place = 1;
    while(t)  
    {  
        rem = t % 10;  
        B[i] = B[i] + !rem * place;  
        t = t / 10;  
        place = place * 10;  
    }
    if(A[i] == 0)
        B[i] = 1;
}