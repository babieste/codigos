#include <stdio.h>
#define MAX 10

void getPrecos(int vetor[]) {
	int i;
	for(i = 0; i < MAX; i++) {
		printf("\n preco[%d] = ", i);
		scanf(" %d", &vetor[i]);
	}
}

void showPrecos(int precos[]) {
	int i;
	printf("\n precos = [");
	for(i = 0; i < MAX; i++) {
		printf(" %d", precos[i]);
	}
	printf(" ]\n");
}

int rodCuttingNaive(int n, int p[]) {
	int i; int max = -1;
	if(n == 0) return 0;
	for(i = 0; i < n; i++) {
		int temp = p[i] + rodCuttingNaive(n-1, p);
		if(temp > max) max = temp;
	}
	return max;
}

int main() {
	int precos[MAX], n;
	
	getPrecos(precos);
	showPrecos(precos);
	
	printf("\n n = ");
	scanf(" %d", &n);
	
	printf("\n maximum revenue = %d", rodCuttingNaive(n, precos));
}
