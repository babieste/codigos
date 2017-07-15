//14) Escreva um programa para que lida uma cadeia de caracteres e armazenada numa estrutura de
//dados do tipo fila, sejam construídas outras três filas onde uma contém as vogais da cadeia de
//caracteres digitada, a outra as consoantes e na última, os caracteres que não encaixam na definição
//de vogal e consoante.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

#define MAX 100

typedef char def_fila[MAX];

//-----------------------------------------
//Funções
//-----------------------------------------

int cheia(int final){
	return (final == MAX-1);
}

int vazia(int inicio){
	return (inicio == -1);
}

int enfileira(def_fila fila, int *inicio, int *final, char letra){
	if(cheia(*final))
		return 0;
	fila[++(*final)] = letra;
	if((*inicio) == -1) //Inicializa a fila
		(*inicio) = 0;
	return 1;
}

int desenfileira(def_fila fila, int *inicio, int *final, char *letra){
	if(vazia(*final))
		return 0;
	*letra = fila[(*inicio)];
	if(*inicio == *final) //Termina a fila
		*inicio = *final = -1;
	else 
		(*inicio)++;
	return 1;
}

void mostra_fila(def_fila fila, int inicio, int final){
	int i;
	
	for(i = inicio; i <= final; i++){
		printf("%c ", fila[i]);
	}
}


//-----------------------------------------
//Main
//-----------------------------------------
int main(){
	setlocale(LC_ALL, "portuguese");
	def_fila fila, vogal, consoante, caractere;
	int inicio_fila, inicio_vogal, inicio_consoante, inicio_caractere;
	int final_fila, final_vogal, final_consoante, final_caractere;
	char op;
	char letra;
	
	inicio_fila = inicio_vogal = inicio_consoante = inicio_caractere = -1;
	final_fila = final_vogal = final_consoante = final_caractere = -1;
	
	while(1){
		do {
			printf("\nDigite um caractere (z para cancelar): ");
			scanf(" %c", &letra);
			if(!enfileira(fila, &inicio_fila, &final_fila, letra))
				printf("\nNão foi possível adicionar esse caractere.");
		} while (letra != 'z');
		
		do{
			if(!desenfileira(fila, &inicio_fila, &final_fila, &letra)) {
				printf("\nNão foi possível continuar a operação.");
				break;
			}
			if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
				enfileira(vogal, &inicio_vogal, &final_vogal, letra);
			else if((letra >= 33 && letra <= 47) || (letra >= 58 && letra <= 63))
				enfileira(caractere, &inicio_caractere, &final_caractere, letra);
			else
				enfileira(consoante, &inicio_consoante, &final_consoante, letra);
		} while (inicio_fila != final_fila);
		printf("\nVogais, caracteres e consoantes: ");
		printf("\n");
		mostra_fila(vogal, inicio_vogal, final_vogal);
		printf("\n");
		mostra_fila(caractere, inicio_caractere, final_caractere);
		printf("\n");
		mostra_fila(consoante, inicio_consoante, final_consoante);
	}
}

