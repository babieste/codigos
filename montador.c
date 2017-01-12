//Bárbara Este Fernandez
//RA: 161025901

//Trabalho completo

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#include <locale.h>

//Inicialização dos arquivos:
FILE *entrada;
FILE *saida;

typedef struct { //EQUs e rótulos
    char nome[101];
    int valor;
} rotulos;

void calcula_mem(char aux[], int *mem){
	char *token;
	
	
	if(aux[0] == ' ') { /*Não é rótulo, é mnemônico*/
		token = strtok(aux, " ");
		/*Se tiver mnemônico, aumenta o valor de MEM*/
	} 
	else { /*Possui um rótulo na frente*/ ESSA MERDA DESSE ELSE AINDA NÃO FUNCIONA -- ISSO É QUANDO TEM ROTULO COM MNEMONICO NA FRENTE, BEIJÃO ATÉ MAIS
		token = strtok(aux, " "); /*Ignora o rótulo*/
		token = strtok(NULL, " "); /*Lê o mnemônico na segunda palavra*/
		if(token == NULL) return; /*Só tem rótulo na linha*/
	}
	
	printf(" x%sx\n", token);
	
	if (token[strlen(token)-1] == '\n') /*Retira o ENTER*/
		token[strlen(token)-1] = '\0';
	
	
	
	if( strstr("RET#HLT", token) != NULL){
    	*mem = *mem + 1;
	}
    else if( strstr("MOV#ADD#SUB#CMP#JMP#JC#JNC#JZ#JNZ#JBE#JA#CALL", token) != NULL){
    	*mem = *mem + 2;
	}
}

void remove_comentario(char aux[]){
	int i;
	for(i = 0; i < strlen(aux); i++){
		if(aux[i] == ';')
			aux[i] = '\0';
	}
}

void le_rotulo(rotulos rot[], char aux[], int *nr, int mem){
	char *token;
	
	token = strtok(aux, " "); /*Lê o nome do rótulo*/
	if (token[strlen(token)-1] == '\n') /*Retira o ENTER*/
		token[strlen(token)-1] = '\0';
	strcpy(rot[*nr].nome, token); /*Coloca na struct o nome do rótulo*/
	//printf("x%sx ", rot[*nr].nome);
	 
	token = strtok(NULL, " "); /*Lê a segunda palavra*/
	if(token != NULL){
		if(strcmp(token, "EQU") == 0) { /*Verifica se é 'EQU'*/
			token = strtok(NULL, " "); /*Lê a terceira palavra*/
			rot[*nr].valor = atoi(token);
		}
		else { /*Se não é 'EQU' então é rótulo com mnemônico na frente*/
			rot[*nr].valor = mem;
		}
	}
	else { /*Se token é nulo então é rótulo sem mnemônico na frente*/
		rot[*nr].valor = mem;
	}
	
	//	printf("[%d] x%sx", rot[*nr].valor, rot[*nr].nome);
	
	*nr = *nr + 1;
}

int procura_rotulo(rotulos rot[], char nome, int nr, int linha){
	int i;
	for(i = 0; i < nr; i++){
		if(strcmp(rot[i].nome, nome) == 0){
			return rot[i].valor;
		}
	}
	printf("\nERRO: [Linha %d] Rotulo %s nao encontrado!", linha, nome);
	return -1;
}

//-----------------------------------------FUNÇÃO PRINCIPAL-----------------------------------------------------------
int main () {
	
	setlocale(LC_ALL,"portuguese");
    //Variáveis
    rotulos rot[101];
	int linha = 0, mem = 0 /*Conta os bytes usandos nos comandos*/, nr = 0 /*Contador de rótulos*/;
    char aux[101]; /*Armazena a linha de código a ser lida*/
	int i; 
	
    //Verificação dos arquivos
    if((entrada = fopen("entrada.txt", "rt")) == NULL){
        printf("\nErro na inicializacao do arquivo de mnemonicos."); 
		getch(); 
		exit(1);
    }
    if((saida = fopen("saida.txt", "wt")) == NULL){
        printf("\nErro na abertura do arquivo de opcodes."); 
		getch(); 
		exit(1);
    }
    
    rewind(entrada);

    while(fgets(aux, 101, entrada)!= NULL){ //Enquanto não é o final do arquivo
        //printf("\nFrase auxiliar: [%d] x%sx", linha, aux);
      	remove_comentario(aux);
      	if (strlen(aux) != 0 && aux[0] != '\n') {
	        if(aux[0] != ' ' && strlen(aux)-1 != 0)
	        	le_rotulo(rot, aux, &nr, mem);
	        calcula_mem(aux, &mem);	
		}
        
		linha++;
	}
	for(i = 0; i < nr; i++){
		printf("[%d] x%sx\n", rot[i].valor, rot[i].nome);
	}
}
