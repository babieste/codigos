#include <stdio.h>

#define MAX 10

void inicializaTabuleiro(int qtde_rainhas, int tabuleiro[MAX][MAX]){
	int i, j;
	
	for(i = 0; i < qtde_rainhas; i++){
		for(j = 0; j < qtde_rainhas; j++){
			tabuleiro[i][j] = 0;
		}
	}
}

void imprimeTabuleiro(int qtde_rainhas, int tabuleiro[MAX][MAX]) {
	int i, j;
	
	for(i = 0; i < qtde_rainhas; i++) {
		printf("\n");
		for(j = 0; j < qtde_rainhas; j++){
			printf("%d ", tabuleiro[i][j]);
		}
	}
	printf("\n");
}

//Start in the leftmost columm
//	If all queens are placed, return true
//	for (every possible choice among the rows in this column)
// 		if the queen can be placed safely there,
//			make that choice and then recursively try to place the rest of the queens
//			if recursion successful, return true
//			if !successful, remove queen and try another row in this column
//		if all rows have been tried and nothing worked, return false to trigger backtracking

int ehSeguro(int qtde_rainhas, int tabuleiro[MAX][MAX], int linha_atual, int coluna_atual) {
	int i, j;
	
	// Verifica linha atual
	for(j = 0; j < coluna_atual; j++) {
		if(tabuleiro[linha_atual][j] == 1)
			return 0;
	}
	
	// Verifica diagonal superior
	i = linha_atual;
	j = coluna_atual;
	while(i >= 0 && j >= 0) {
		if(tabuleiro[i][j] == 1)
			return 0;
		i--;
		j--;
	}
	
	// Verifica diagonal inferior
	i = linha_atual;
	j = coluna_atual;
	while(i < qtde_rainhas && j >= 0){
		if(tabuleiro[i][j] == 1)
			return 0;
		i++;
		j--;
	}
	
	return 1;
}

int resolveNRainhas(int qtde_rainhas, int tabuleiro[MAX][MAX], int coluna_atual) {
	int linha_atual = 0;
	
	if (coluna_atual >= qtde_rainhas)
		return 1;
	
	while (linha_atual < qtde_rainhas) {
		if(ehSeguro(qtde_rainhas, tabuleiro, linha_atual, coluna_atual) == 1) {
			tabuleiro[linha_atual][coluna_atual] = 1;
			if (resolveNRainhas(qtde_rainhas, tabuleiro, coluna_atual + 1))
				return 1;
			tabuleiro[linha_atual][coluna_atual] = 0;
		}
		linha_atual++;
	}
	
	return 0;
}

int main () {
	int qtde_rainhas;
	int tabuleiro[MAX][MAX];
	
	do {
		printf("N = ");
		scanf(" %d", &qtde_rainhas);
		
		if(qtde_rainhas <= 0 || qtde_rainhas > MAX) {
			printf("\nN deve ser positivo e menor que %d!\n", MAX);
		}
	} while(qtde_rainhas <= 0 || qtde_rainhas > MAX);
	
	inicializaTabuleiro(qtde_rainhas, tabuleiro);
		
	if(resolveNRainhas(qtde_rainhas, tabuleiro, 0))
		imprimeTabuleiro(qtde_rainhas, tabuleiro);
	else {
		printf("\nNao foi possivel encontrar uma solucao!!!");
	}

}
