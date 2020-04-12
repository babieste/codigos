#include <stdio.h>

void preencheVetor(int vetor[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("\n[%d] = ", i);
		scanf(" %d", &vetor[i]);
	}
}

void mostraVetor(int vetor[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf(" %d ", vetor[i]);
	}
}

int knapsackNaive(int p[], int v[], int n, int pesoMax) {
	int a, b;
	if(n == 0) return 0;
	a = knapsackNaive(p, v, n-1, pesoMax);
	if(p[n] > pesoMax) return a;
	b = v[n] + knapsackNaive(p, v, n-1, pesoMax-p[n]);
	if(a > b) return a;
	return b;
}

int main() {
	int pesoMax, n, p[100], v[100];
	
	printf("\nn = ");
	scanf(" %d", &n);
	
	printf("\n\nTabela de precos:");
	preencheVetor(p, n);
	printf("\np = [");
	mostraVetor(p, n);
	printf("]");
	
	printf("\n\nTabela de valores:");
	preencheVetor(v, n);
	printf("\nv = [");
	mostraVetor(v, n);
	printf("]");
	
	printf("\nPeso maximo da mochila = ");
	scanf(" %d", &pesoMax);
	
	printf("\nValor maximo = %d", knapsackNaive(p, v, n, pesoMax));
}
