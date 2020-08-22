// Barbara Este Fernandez - 31937039
#include <stdio.h>
#define MAX 10

int getRowWithSmallestNumber(int n, int matrix[n][n]) {
    int i = 0, j = 0;
    int smallestNumber = 99, row = -1;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] < smallestNumber) {
                smallestNumber = matrix[i][j];
                row = i;
            }
        }
    }
    
    return row;
}

#include <stdio.h>
int main() {
    int row = -1;
    int matrix[4][4]={
        {10, 24, 35, 9},
        {8, 42, 6, 12},
        {9, 1, 89, 7},
        {67, 33, 5, 8}
    };
    
    row = getRowWithSmallestNumber(4, matrix);
    printf("Row index with smallest number is: %d", row);
    return 0;
}