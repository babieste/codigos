#include <stdio.h>
#define MAX 5

FILE *dicionario;

int main() {
	FILE *dicionario;
	char *palavra;
	char letras[MAX];
	int n;
	
	//Abrir o arquivo "dicionario.txt" para leitura
	if((dicionario = fopen("dicionario.txt", "r")) == NULL) {
		printf("Erro na abertura do arquivo");
	} 
	else {
		//Pega a palavra no arquivo
		fgets(palavra, 30, dicionario);
		
		printf("\n %c", palavra);
	
		
//		printf("Quantas letras quer procurar?\nR: ");
//		scanf(" %d", &n);
//		if(n > MAX) {
//			printf("\nO numero maximo permitido e %d!\nR: ", MAX);
//			do {
//				scanf("\n %d", n);
//			} while (n > MAX);
//		}
//		
//		for(int i = 0; i < n; i++) {
//			printf("\n%da letra: ", i+1);
//			scanf(" %c", letra[i]);
//		}	
		
		
	}
	fclose(dicionario);
}
