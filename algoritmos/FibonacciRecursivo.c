#include <stdio.h>

int fibo1(int n) {
    int i, penultimo, ultimo, atual;
    if (n == 0)
        return 0;
    else
        if (n == 1)
            return 1;
        else {
            penultimo = 0;
            ultimo = 1;
            for (i = 0; i <= n; i++) {
                atual = penultimo + ultimo;
                penultimo = ultimo;
                ultimo = atual;
            }
            return atual;
        }
}

int fibo2(int n) {
    if (n == 0)
        return 0;
    else
        if (n == 1)
            return 1;
    else
        return fibo2(n-1)+fibo2(n-2);
}

int soma1(int n) {
    if (n == 0)
        return 0;
    else
        return n + soma1(n-1);
}

int soma2(int n) {
    int i, soma = 0;
    for (i = 0; i <= n; i++) {
        soma += i;
    }
    return soma;
}

int main () {
    long int n;
    printf("n = ");
    scanf(" %ld", &n);


    printf("Iterativo 1 %d", soma1(n));
    printf("\nRecursivo %d", soma2(n));
}
