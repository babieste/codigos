#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define IT 1
#define ST 2
#define FLT 3

//=========================================================================
//						STRUCTS
//=========================================================================
typedef union {
	int int_info;
	float float_info;
	char char_info[15];
	char doc_info[4];
} no_info;

struct no {
	int tipo;
	no_info dado;
	struct no* prox;
};
typedef struct no* def_fila;

//=========================================================================
//						FUNÇÕES
//=========================================================================
void enfileira(def_fila *inicio, def_fila* final, int tipo,  no_info dado){
	def_fila q = (def_fila) malloc(sizeof(struct no));
	q->tipo = tipo;
	q->dado = dado;
	q->prox = NULL;
	
	if(*final != NULL) (*final)->prox = q; //*final != NULL significa que há elementos na fila, 
	else *inicio = q; //<-aponta o primeiro	// então é preciso incluir o novo nó depois do último elemento
	*final = q;								// e passar o ponteiro de final para o último elemento.
}

int desenfileira(def_fila* inicio, def_fila* final, int* tipo, no_info* dado){
	def_fila q;
	
	if(*inicio == NULL) return 0; //Se não há elementos na lista, ñ tem o que tirar
	q = *inicio; //Recupera o primeiro elemento
	
	*inicio = (*inicio)->prox; //Aponta para o próximo (segundo elemento)
	if (*inicio == NULL) *final = NULL; //Se início == NULL, o elemento 'retirado' era o último, 
										// então o ponteiro *final também deve apontar para NULL;
	*dado = q->dado;
	*tipo = q->tipo;
	free(q);
	return 1;
}


int mostra(def_fila inicio){
	def_fila q = inicio;
	
	if(q == NULL) return 0;
	while(q){
		switch(q->tipo){
			case IT:
				printf("\n\tProcesso %d.", q->dado.int_info);
				break;
			case ST:
				printf("\n\tProcesso %s", q->dado.char_info);
				break;
			case FLT: 
				printf("\n\tProcesso %.2f", q->dado.float_info);
				break;
		}
		q = q->prox;
	}
	return 1;
}

int menu(){
	int op;
	
	printf("\n\n-------------------------------------------");
	do {
		printf("\n1- Incluir novo processo\n2- Retirar processo mais longo\n3- Imprimir a lista de processos\nOpcao: ");
		scanf(" %d", &op);
	} while (op < 1 && op > 3);
	return op;
}
//=========================================================================
//             						MAIN
//=========================================================================
int main(){
	def_fila inicio = NULL, final = NULL;
	no_info dado;
	int op, tipo;
	
	while(1){
		op = menu();
		switch(op) {
			case 1:
				printf("\nDigite o tipo do processo:\n1- INT\n2- STRING\n3- FLOAT\nOpcao: ");
				do{
					scanf(" %d", &tipo);
				} while (tipo < 1 && tipo > 3);
				
				printf("\nDigite a identificacao do processo: ");
				switch(tipo){
					case IT:
						scanf(" %d", &dado.int_info);
						break;
					case ST:
						scanf(" %s", &dado.char_info);
						break;
					case FLT:
						scanf(" %f", &dado.float_info);
						break;
				}
				
				enfileira(&inicio, &final, tipo, dado);
				//printf("aaa");
				break;
			case 2:
				if(!desenfileira(&inicio, &final, &tipo, &dado)) printf("Nao ha processos para serem retirados");
				else {
					switch(tipo){
						case IT:
							printf("\n\tProcesso %d foi executado.", dado.int_info);
							break;
						case ST:
							printf("\n\tProcesso %s foi executado.", dado.char_info);
							break;
						case FLT: 
							printf("\n\tProcesso %.2f foi executado. ", dado.float_info);
							break;
					}
					printf("\nProcessos restantes: ");
					if(!mostra(inicio)) printf("\nNao ha processos.");
				}
				break;
			case 3:
				if(!mostra(inicio)) printf("\nNao ha processos.");
				break;
		}
	}
}

