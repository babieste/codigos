#include <stdio.h>
#include <string.h>
#include <ctype.h>

int quick_sort(int inicio, int fim, FILE *arq){
	printf("\nEntrou no sort!");
	int i, j, pivo;
	int tam_palavra_pivo, tam_palavra_menor, tam_palavra_maior;
	char palavra_pivo[30], palavra_menor[30], palavra_maior[30], aux[30];
	
	i = inicio;
	if((fseek(arq, i, SEEK_SET)) == 0) {
		if((fgets(palavra_menor, sizeof(palavra_menor), arq)) != NULL)
			tam_palavra_menor = strlen(palavra_menor);
		else {
			printf("\nNao foi possivel ler a linha.");
			return;
		}
	} else {
		printf("\nErro ao encontrar indice.");
		return;
	}
		
	j = fim;
	if((fseek(arq, j, SEEK_SET)) == 0) {
		if((fgets(palavra_maior, sizeof(palavra_maior), arq)) != NULL)
			tam_palavra_maior = strlen(palavra_maior);
		else {
			printf("\nNao foi possivel ler a linha.");
			return;
		}	
	} else {
		printf("\nErro ao encontrar indice.");
		return;
	}
	
	pivo = (i+j)/2;
	if((fseek(arq, pivo, SEEK_SET)) == 0) {
		if((fgets(palavra_pivo, sizeof(palavra_pivo), arq)) != NULL)
			tam_palavra_pivo = strlen(palavra_pivo);
		else {
			printf("\nNao foi possivel ler a linha.");
			return;
		}	
	} else {
		printf("\nErro ao encontrar indice.");
		return;
	}
	
	while (i < j){
		while(tam_palavra_menor < tam_palavra_pivo)
			i++;
		while (tam_palavra_maior > tam_palavra_pivo)
			j--;
		if (i <= j){
			strcpy(aux, palavra_menor); //aux = v[i];
			
			if((fseek(arq, i, SEEK_SET)) == 0){
				//v[i] = v[j];
				if((fputs(palavra_maior, arq)) == EOF){
					printf("\nNao foi possivel escrever palavra");
					return;
				} 
			} else {
				printf("\nErro ao encontrar indice.");
				return;
			}
				
			if((fseek(arq, j, SEEK_SET)) == 0) {
				//v[j] = aux;
				if((fputs(aux, arq)) == EOF) {
					printf("\nNao foi possivel escrever palavra.");
					return;
				}
			} else {
				printf("\nErro ao encontrar indice.");
				return;
			}
				
			i++;
			j++;
		}		
	}
	if (j > inicio)
		quick_sort(inicio, j, arq);
	if (i < fim)
		quick_sort(i, fim, arq);
}

int main() {
	FILE *dicionario, *resposta;
	char palavra[30];
	int tam_palavra;
	
	int posicao_primeira_linha, posicao_ultima_linha;
	
	//Abrir o arquivo "dicionario.txt" para leitura
	if((dicionario = fopen("dicionario.txt", "r+")) == NULL) 
		printf("Erro na abertura do arquivo 'dicionario.txt'");
	else {
		if((resposta = fopen("resposta.txt", "w")) == NULL)
			printf("\nErro ao abrir o arquivo de gravacao");
		else {
			
			//Índice da primeira e da última palavra
			fseek(dicionario, 0, SEEK_SET);
			if((posicao_primeira_linha = ftell(dicionario)) == -1) {
				printf("\nErro ao pesquisar o arquivo.");
				return;
			}
			fseek(dicionario, -6, SEEK_END);
			if ((posicao_ultima_linha = ftell(dicionario)) == -1) {
				printf("\nErro ao pesquisar o arquivo.");
				return;
			}
			
//			Próximo passo: otimizar o quick_sort
			printf("Comecando o sort...");
			quick_sort(posicao_primeira_linha, posicao_ultima_linha, dicionario);
			printf("\nTermino do sort!");				
						
//			//Lê a palavra						
//			if(fgets(palavra, 30, dicionario)) 
//				printf(" %s", palavra);		
		}				
	} 
	fclose(resposta);
	fclose(dicionario);
}
