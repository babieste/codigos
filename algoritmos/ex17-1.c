/* 	Árvore AVL
      Inserção, Impressão e Remoção
*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef struct no_arvore{
    int info;
    int balanco;
    struct no_arvore* esquerdo;
	struct no_arvore* direito;
} *def_arvore;


def_arvore inicializa(void){
    return NULL;
}

void cria_arvore(def_arvore* arvore){
    def_arvore p;
    char ok;
	int filho;

	printf("\n\nO no %d tem filhos? (S/N)", (*arvore)->info);
    ok = getche();
    if(ok == 'S' || ok == 's'){
		printf("\nLeitura dos filhos de : %d\n", (*arvore)->info);
     	printf("Entre com o filho da esquerda (-1 para nulo): ");
     	scanf("%d", &filho);
     	if(filho != -1){
        	p = (def_arvore)malloc(sizeof(struct no_arvore));
            p->info = filho;
            p->esquerdo = NULL;
            p->direito = NULL;
            (*arvore)->esquerdo = p;
		}
 		printf("Entre com o filho da direita (-1 para nulo): ");
 		scanf("%d", &filho);
 		if(filho != -1){
        	p = (def_arvore)malloc(sizeof(struct no_arvore));
        	p->info = filho;
        	p->esquerdo = NULL;
        	p->direito = NULL;
          (*arvore)->direito = p;
		}
     	if((*arvore)->esquerdo != NULL)
	 		cria_arvore(&((*arvore)->esquerdo));
     	if((*arvore)->direito != NULL)
	 		cria_arvore(&((*arvore)->direito));
	}
}

void mostra_arvore(def_arvore arvore, int *nivel){ 
	int i, nivel1;

	if (arvore == NULL) return;
    for(i = 0; i <= (*nivel)*2; i++) 
		printf("  ");
    printf("%d(%d)\n", arvore->info, arvore->balanco);
    nivel1 = (*nivel)+1;
    
    if(arvore->direito != NULL)
        mostra_arvore(arvore->direito, &nivel1);
    if(arvore->esquerdo != NULL)
        mostra_arvore(arvore->esquerdo, &nivel1);
}

void le_arvore (def_arvore* arvore){
	  int dado;

     printf("\nEntre com a raiz = "); scanf("%d", &dado);
     (*arvore) = (def_arvore)malloc(sizeof(struct no_arvore));
     
     (*arvore)->info = dado;
     (*arvore)->esquerdo = NULL;
     (*arvore)->direito = NULL;
     cria_arvore(arvore);
}

//==================================
//Funções de verificação
//==================================
	
int verifica_direita(def_arvore arvore, int pai){
	if (arvore != NULL){
		if(arvore->info < pai) return 1;
		return (verifica_direita(arvore->esquerdo, pai) || verifica_direita(arvore->direito, pai)); //Disjunção Lógica: 0 || 0 = 0, outras condições [...] = 1
	}
	return 0;
}

int verifica_esquerda(def_arvore arvore, int pai){
	if(arvore != NULL){
		if(arvore->info > pai) return 1;
		return (verifica_esquerda(arvore->esquerdo, pai) || verifica_esquerda(arvore->direito, pai));
	}
	return 0;
}

int verifica_arvore(def_arvore arvore){
	if (arvore != NULL){
		if(verifica_direita(arvore->direito, arvore->info) || verifica_esquerda(arvore->esquerdo, arvore->info))
			return 1;
		return (verifica_arvore(arvore->direito) || verifica_arvore(arvore->esquerdo)); 
	}
}

int balanceamento(def_arvore arvore, int nivel){
	if (arvore != NULL){
		nivel++;
		if(balanceamento(arvore->esquerdo, nivel) >= balanceamento(arvore->direito, nivel))
			return balanceamento(arvore->esquerdo, nivel);
		return balanceamento(arvore->direito, nivel);
	}
	return nivel;
}

int main(void){
	def_arvore arvore;
	int numero, nivel = 0;

    arvore = inicializa();
	le_arvore(&arvore);
	mostra_arvore(arvore, &nivel);
	if(verifica_arvore(arvore))
		printf("\nNao eh arvore de busca.\n");
	else
		printf("\nEh arvore de busca.\n");
	if(abs(balanceamento(arvore->direito, 0) - balanceamento(arvore->esquerdo, 0)) > 1)
		printf("\nNao eh balanceada.");
	else
		printf("\nEh balanceada.");

    printf("\n\n\aTecle algo para encerrar ...");
	getch();
}



