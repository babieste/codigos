#include <stdio.h>
#include <time.h>

//É possível perceber que o Fibonacci com memoization retorna 
//a resposta quase que imediatamente (dependendo do tamanho da
//entrada). O Fibonacci ingênuo começa a demorar para retornar
//a resposta a partir de f > 40.

int fibonacciNaive(int f) {
	if(f == 0) return 0;
	if(f == 1) return 1;
	return (fibonacciNaive(f-1) + fibonacciNaive(f-2));
}

int fibonacciMemoizedAux(int f, int aux[]) {
	if(aux[f] > 0) return aux[f];
	else {
		if(f == 0) return 0;
		if(f == 1) return 1;
		aux[f] = fibonacciMemoizedAux(f-1, aux) + fibonacciMemoizedAux(f-2, aux);
		return aux[f];
	}
}

int fibonacciMemoized(int f) {
	int aux[100] = {0};
	return fibonacciMemoizedAux(f, aux);
}

int main () {
	int f, resultado;
	
	printf("\n f = ");
	scanf(" %d", &f);

	printf("\n %d", fibonacciMemoized(f));
	printf("\n %d", fibonacciNaive(f));
}
