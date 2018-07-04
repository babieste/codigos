#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5

int main() {
	FILE *dicionario, *resposta;
	char palavra[30], letras[MAX], aux[MAX];
	int i, j, k, num_letras = 0;
//	int tam_palavra, contador = 0;
	
	//Abrir o arquivo "dicionario.txt" para leitura
	if((dicionario = fopen("dicionario.txt", "r")) == NULL) {
		printf("Erro na abertura do arquivo 'dicionario.txt'");
	} 
	else {
		if((resposta = fopen("resposta.txt", "w")) == NULL) {
			printf("\nErro ao abrir o arquivo de gravacao");
		}
		else {
			do {
				system("cls");
				printf("\nQuantas letras quer procurar? (MAX = %d)\nR: ", MAX);
				scanf(" %d", &num_letras);
			} while (num_letras <= 0 || num_letras > 5);
		
			for(i = 0; i < num_letras; i++) {
				printf("\nletra[%d] = ", i+1);
				scanf(" %c", &letras[i]);
			}
			
			//Pega a palavra no arquivo
			if(fgets(palavra, 30, dicionario)) {
				printf(" %s", palavra);
//				tam_palavra = strlen(palavra);
			}
					
			//Verifica anagrama
			for(i = 0; i < num_letras; i++) {
				for(j = 0; j < strlen(palavra); j++) {

					if(toupper(letras[i]) == toupper(palavra[j])) { //Letra contida na palavra
						for(k = 0; k < num_letras; k++) { //Verifica se é uma letra já lida anteriormente
							if(palavra[j] != aux[k])
								aux[k] = palavra[j];
						}
					}
				}	
			}
			if (strlen(aux) == num_letras)
				fputs(palavra, resposta); //Grava o anagrama no arquivo
		
			//Hash nas palavras
			//[...]
		}
	} 
	fclose(resposta);
	fclose(dicionario);
}
