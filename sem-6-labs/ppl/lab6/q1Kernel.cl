__kernel void strmul(__global char *s,__global char *res, int len)
{
	int i = get_global_id(0);
    res[i] = s[i % len];	
}