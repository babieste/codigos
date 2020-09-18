#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX 500

void generateMatrix(int n, int matrix[n][n]) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            matrix[i][j] = rand() % 10; // generate random number between 0 and 9
}

void generateEmptyMatrix(int n, int matrix[n][n]) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            matrix[i][j] = 0;
}

void displayMatrix(int n, int matrix[n][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("\n[ ");
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("]");
    }
}

void multiplyMatrix(int n, int matrixA[n][n], int matrixB[n][n], int result[n][n]) {
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                result[i][j] = result[i][j] + matrixA[i][k] * matrixB[k][j];
}

void multiplyMatrixWithCacheOp(int n, int matrixA[n][n], int matrixB[n][n], int result[n][n]) {
    int i, j, k;
    for (i = 0; i < n; i++)
        for (k = 0; k < n; k++)
            for (j = 0; j < n; j++)
                result[i][j] = result[i][j] + matrixA[i][k] * matrixB[k][j];
}

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX], matrix_size = 500;
    struct timeval tv;
    double start_t, end_t, time_delta;

    generateEmptyMatrix(matrix_size, result);

    generateMatrix(matrix_size, matrixA);
    // printf("\nMatrix A:\n");
    // displayMatrix(matrix_size, matrixA);

    generateMatrix(matrix_size, matrixB);
    // printf("\nMatrix B:\n");
    // displayMatrix(matrix_size, matrixB);
          
    gettimeofday(&tv, NULL);
    start_t = (double) (tv.tv_sec*1000.0) + (double) (tv.tv_usec / 1000.0); // start time in microseconds
  
    multiplyMatrix(matrix_size, matrixA, matrixB, result);
    // multiplyMatrixWithCacheOp(matrix_size, matrixA, matrixB, result)

    gettimeofday(&tv,NULL); 
    end_t = (double) (tv.tv_sec*1000.0) + (double) (tv.tv_usec / 1000.0); // end time in microseconds
    time_delta = end_t - start_t;
    printf("\nProgram execution time: %f ms\n", time_delta);

    return 0;
}
