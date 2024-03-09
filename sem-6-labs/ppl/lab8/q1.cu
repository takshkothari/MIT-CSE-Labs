#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__global__
void word_count_kernel(char* str, char* key, int* word_indices, int* result)
{
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    // get idx'th word
    int si = word_indices[idx];
    int ei = word_indices[idx+1];
    char word[100];
     int i = 0;
    for (i = 0; i < (ei-si-1); i++)
        word[i] = str[si+1+i];
    word[i] = '\0';

    // compare word and key
    int i1 = 0;
    int i2 = 0;
    int is_equal = 1;

    while (word[i1] != '\0' && key[i2] != '\0')
    {
        if (word[i1] == key[i2])
        {
            i1++;
            i2++;
        }
        else
        {
            is_equal = 0;
            break;
        }
    }
    if (is_equal == 1)
    {
        atomicAdd(result, 1);
    }
}

int main()
{
    // char str[100] = "We are having PCAP Lab today morning";
    // char key[100] = "today";
    
    char str[100], key[20];
    printf("Enter string: ");
    scanf("%[^\n]s", str);
    printf("Enter key: ");
    scanf("%s", key);

    int str_len = strlen(str), key_len = strlen(key);
    int word_count = 0;

    for (int i = 0; i < str_len; i++)
    {
        if (str[i] == ' ')
            word_count++;
    }
    word_count--;
    int* word_indices = (int*) (malloc(word_count * sizeof(int)));
    int wi = -1;

    for (int i = 0; i < str_len; i++)
    {
        if (str[i] == ' ')
            word_indices[++wi] = i;
    }

    int result = 0;

    char* d_str;
    char* d_key;
    int* d_word_indices;
    int* d_result;

    cudaMalloc((void**)&d_str, str_len * sizeof(char));
    cudaMalloc((void**)&d_key, key_len * sizeof(char));
    cudaMalloc((void**)&d_word_indices, (word_count+1) * sizeof(int));
    cudaMalloc((void**)&d_result, sizeof(int));
    
    cudaMemcpy(d_str, str, str_len * sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(d_key, key, key_len * sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(d_word_indices, word_indices, (word_count+1) * sizeof(int),     cudaMemcpyHostToDevice);
    cudaMemcpy(d_result, &result, sizeof(int), cudaMemcpyHostToDevice);

    word_count_kernel<<<1, word_count>>>(d_str, d_key, d_word_indices, d_result);

    cudaMemcpy(&result, d_result, sizeof(int), cudaMemcpyDeviceToHost);

    printf("Input String: %s\n", str);
    printf("Key: %s\n", key);
    printf("Total occurances of %s is %d\n", key, result);

    cudaFree(d_str);
    cudaFree(d_key);
    cudaFree(d_result);

    return 0;
}