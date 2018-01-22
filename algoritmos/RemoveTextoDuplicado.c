#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

void preencher_matriz(char palavras[256][256], char str[256], int quantidade[], int *n) {
	int i;
	for(i = 0; i < *n; i++) {
		if (stricmp(str, palavras[i]) == 0) {
			quantidade[i]++;
			return;
		}
	}
	strcpy(palavras[*n], str);
	quantidade[*n] = 1;
	*n= *n + 1;
}

void remove_duplicado(char texto[], int *duplicado) {
    int i, j;
    for(i = 0; i < strlen(texto); i++) {
        if (texto[i] == texto[i+1] && (texto[i] == ' ' || texto[i] == ',' || texto[i] == '.')) {
            *duplicado = *duplicado + 1;
            for(j = i; j < strlen(texto); j++) {
                texto[j] = texto[j+1];
            }
            i--;
        }
    }
    printf("\nFrase: %s\n", texto);
}

void separa_frases(char texto[]) {
	int i, j = 0, k, l=1, n=0;
    char frases[256][256];
    for(i = 0; i < strlen(texto); i++) {
        if(texto[i] != ',' && texto[i] != '.') {
            frases[n][j] = texto[i];
            j++;
            if(i == strlen(texto)-1){
                frases[n][j] = '\0';
                n++;
            }
        }
        else if(j != 0) {
                frases[n][j] = '\0';
                n++;
                j = 0;
            }
    }
    
    for(k = 0; k < n; k++) {
    	if (frases[k][0] == ' ')
    		frases[k][1] = toupper(frases[k][1]);
    	else
    		frases[k][0] = toupper(frases[k][0]);
        printf("\nFrase %d: %s\n", l, frases[k]);
        l++;
    }
}

void separa_palavra(char texto[]) {
    int i, j = 0, k, l, n = 0;
    int quantidade[256];
    char palavras[256][256], aux[256];
    //Coloca na auxiliar
    for(i = 0; i < strlen(texto); i++) {
        if(texto[i] != ' ' && texto[i] != ',' && texto[i] != '.') {
            aux[j] = texto[i];
            j++;
            if(i == strlen(texto)-1){
                aux[j] = '\0';
                preencher_matriz(palavras, aux, quantidade, &n);
            }
        }
        else if(j != 0) {
                aux[j] = '\0';
                preencher_matriz(palavras, aux, quantidade, &n);
                j = 0;
            }
    }
    printf("\n%d", n);
    //Contagem das palavras
    for(k = 0; k < n; k++){
		printf("\nA palavra %s apareceu %d vezes!\n", palavras[k], quantidade[k]);
	}
    
}

int main () {
    char resposta, texto[256];
    int duplicado = 0;
    do {
        do {
            printf("Digite seu texto: ");
            gets(texto);
            printf("\n");
        } while (strlen(texto) > 255);
		
		remove_duplicado(texto, &duplicado);
        printf("Caracteres duplicados: %d\n", duplicado);
        separa_frases(texto);
        separa_palavra(texto);

        do {
            printf("\n\nIr novamente? S/N");
            resposta = toupper(getch());
            system("cls");
        } while (resposta != 'S' && resposta != 'N');
    } while (resposta == 'S');
}
