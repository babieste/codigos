#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

#define MAX 20
#define GRAU 2

typedef int def_arvore[MAX];

void le_arvore(def_arvore arvore) {
	int i, j, pai = 0, posicao = 1, qtd;
	char c;
	printf("(-1 para nulo) \nDigite a raiz: ");
	scanf("%d", &arvore[pai]);
	
	for(i = 0; i < MAX; i++) {
		if(arvore[pai] != -1) {
			printf("\nDigite o valor do no a esquerda de %d: ", arvore[pai]);
			scanf("%d", &arvore[posicao++]);
			printf("\nDigite o valor do no a direita de %d: ", arvore[pai]);
			scanf("%d", &arvore[posicao++]);
		}
		pai++;
	}
}

int verifica_estrutura(def_arvore arvore) {
	int i, vazio = 0;
	for(i = 0; i < MAX; i++) {
		if(arvore[i] == -1) 
			vazio = 1;
		if(vazio && arvore[i] != -1) 
			return 0;
	}
	return 1;
}

//====================
//Funções de Heap
//====================

int verifica_heap_maxima(def_arvore arvore) {
	int i, filho1, filho2, ok = 1;
	
	for(i = 0; i < MAX; i++) {
		filho1 = i*2+1;
		filho2 = (i+1) * 2;
		
		if(arvore[filho1] == -1) break;
		if(arvore[filho2] == -1)
			if(arvore[filho1] > arvore[i]) return 0;
			else break;
		if(arvore[filho1] > arvore[i] || arvore[filho2] > arvore[i]) return 0;
	}
	return 1;
}

int verifica_heap_minima(def_arvore arvore) {
	int i, filho1, filho2, ok = 1;
	
	for(i = 0; i < MAX; i++) {
		filho1 = i*2+1;
		filho2 = (i+1) * 2;
		
		if(arvore[filho1] == -1) break;
		if(arvore[filho2] == -1) 
			if(arvore[filho1] < arvore[i]) return 0;
			else break;
		if(arvore[filho1] < arvore[i] || arvore[filho2] < arvore[i]) return 0;
	}	
	return 1;
}

int verifica_heap(def_arvore arvore) {
	if(!verifica_estrutura(arvore)) 
		return 0;
	if(verifica_heap_maxima(arvore)) {
		printf("\nÉ uma Heap Máxima.\n");
		return 1;
	}
	if(verifica_heap_minima(arvore)) {
		printf("\nÉ uma Heap Mínima.\n");
		return 1;
	}
	return 0;
}

void inicializa(def_arvore arvore){
	int i;
	
	for(i = 0; i < MAX; i++){
		arvore[i] = -1;
	}
}

//-----------------------------------------
//Main
//-----------------------------------------
int main(){
	setlocale(LC_ALL, "portuguese");
	def_arvore arvore;
	int i;
	
	while(1){
		inicializa(arvore);
		le_arvore(arvore);
	
		if(!verifica_heap(arvore))
			printf("\nNão é uma Heap.\n");
	}	
}

