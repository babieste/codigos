#include <stdio.h>

FILE *dicionario;

int main() {
	FILE *dicionario;
	char *palavra;

	//Abrir o arquivo "dicionario.txt" para leitura
	if((dicionario = fopen("dicionario.txt", "r")) == NULL) {
		printf("Erro na abertura do arquivo");
	} 
	else {
		//Pega a palavra no arquivo
		fgets(palavra, 30, dicionario);
		
		//Hash nas palavras
		
	}
	fclose(dicionario);
}
