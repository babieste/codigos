#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <omp.h>

#define LENGTH 1000000

void inplaceMerge(int arr[LENGTH], int p, int q, int r) {
    int *w;
    w = malloc ((r-p) * sizeof(int));
    int i = p, j = q;
    int k = 0;

    while (i < q && j < r) {
        if (arr[i] <= arr[j]) w[k++] = arr[i++];
        else  w[k++] = arr[j++];
    } 

    while (i < q) w[k++] = arr[i++];
    while (j < r) w[k++] = arr[j++];
    for (i = p; i < r; ++i) arr[i] = w[i-p];
    free(w);   
}

void mergeSortRecursive(int arr[LENGTH], int left, int right) {
    if (left < right) {
        int mid = (left+right)/2;

        #pragma omp taskgroup
        {
            #pragma omp task shared(arr) untied if(right-left >= (1 << 14))
            mergeSortRecursive(arr, left, mid);
            #pragma omp task shared(arr) untied if(right-left >= (1 << 14))
            mergeSortRecursive(arr, mid+1, right);
            #pragma omp taskyield
        }
        inplaceMerge(arr, left, mid+1, right+1);
    }
}

void mergeSort(int len, int arr[len]) {
    #pragma omp parallel
    #pragma omp single
    mergeSortRecursive(arr, 0, len-1);
}

void printArray(int len, int arr[len]) {
    int i;
    printf("[");
    for (i = 0; i < len; i++) {
        printf(" %d", arr[i]);
    }
    printf(" ]\n");
}

void generateRandomArr(int len, int arr[len]) {
    int i;
    for (i = 0; i < len; i++) {
        arr[i] = rand();
    }
}

int main () {
    struct timeval tv;
    double start_t, end_t, time_delta;

    int arr[LENGTH];
    int length = LENGTH;

    generateRandomArr(length, arr);

    gettimeofday(&tv, NULL);
    start_t = (double) (tv.tv_sec*1000.0) + (double) (tv.tv_usec / 1000.0); // start time in miliseconds
    
    mergeSort(length, arr);

    gettimeofday(&tv,NULL); 
    end_t = (double) (tv.tv_sec*1000.0) + (double) (tv.tv_usec / 1000.0); // end time in miliseconds

    time_delta = end_t - start_t;

    printf("Execution time: %f ms\n", time_delta);
}