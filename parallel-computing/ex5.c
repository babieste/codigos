// Barbara Este Fernandez - 31937039
#include <stdio.h>

void readMatrix(int n, int matrix[n][n]) {
    int i = 0, j = 0;

    printf("\nDigite os valores para a matriz %dx%d: ", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0;j < n; j++) {
            printf("\n[%d][%d] = ", i+1, j+1);
            scanf(" %d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int n, int matrix[n][n]) {
    int i = 0, j = 0;
    for (i = 0; i < n; i++) {
        printf("\n[");
        for (j = 0; j < n; j++) {
            printf(" %0d ", matrix[i][j]);
        }
        printf("]");
    }
}

void multiplyMatrix(int factor, int rowIndex, int columnIndex, int n, int matrix[n][n]) {
    int k = 0;

    for (k = 0; k < n; k++) {
        matrix[rowIndex][k] = matrix[rowIndex][k] * factor;
        matrix[k][columnIndex] = matrix[columnIndex][k] * factor;
    }
}

int main() {
    int n, factor, rowIndex, columnIndex,  matrix[100][100];

    printf("\nDigite a dimensao da matriz: ");
    scanf(" %d", &n);

    readMatrix(n, matrix);
    displayMatrix(n, matrix);

    printf("\nDigite o valor pelo qual multitplicar: ");
    scanf(" %d", &factor);

    printf("\nDigite a linha a qual multiplicar (de 0 a %d): ", n-1);
    scanf(" %d", &rowIndex);

    printf("\nDigite a linha a qual multiplicar (de 0 a %d): ", n-1);
    scanf(" %d", &columnIndex);

    multiplyMatrix(factor, rowIndex, columnIndex, n, matrix);
    printf("\nMatriz multiplicada: ");
    displayMatrix(n, matrix);

    return 0;
}