#include <stdio.h>
#include <stdlib.h>

long n1 = 268435456;
long *vetor1_ptr;

void buildArray(long n, long arr[n]) {
    long i;
    for (i = 0; i < n; i++) {
        arr[i] = i;
    }
}

int main(int argc, char *argv[]) {
    long i;
    vetor1_ptr = (long *) malloc(n1 * sizeof(long));

    printf("Building array...\n");
    buildArray(n1, vetor1_ptr);
    printf("Done!\n");

    printf("First 5 elements of array...\n");
    for (i = 0; i < 5; i++) {
        printf("%ld", vetor1_ptr[i]);
    }
    return 0;
}
