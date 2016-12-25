//Bárbara Este Fernandez
//RA: 161025901

//Trabalho parcial - Montador

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

//Inicialização e verificação dos arquivos:
FILE *entrada;
FILE *saida;

typedef struct { //Rótulos
    char nome[101];
    int valor;
} rotulos;

typedef struct { //EQUs
    char nome[101];
    int valor;
} equ;

//-----------------------------------------FUNÇÃO PRINCIPAL-----------------------------------------------------------
int main () {
    if((entrada = fopen("entrada.txt", "rt")) == NULL){
        printf("\nErro na inicializacao do arquivo de mnemonicos.");
        getch();
        exit(1);
    }
    if((entrada = fopen("saida.txt", "wt")) == NULL){
        printf("\nErro na abertura do arquivo de opcodes.");
        getch();
        exit(1);
    }

    //Variáveis
    rotulos rotulo[101];
    equ equ[101];
    char aux[101]; /*Armazena a linha de código a ser lida*/
    char *token;

    //Variáveis temporárias para salvar no EQU
    char carac;
    int num;

    char quebra[]=" ,\n\t";
    char mnemonicos[]="/MOV/ADD/SUB/CMP/JMP/JC/JNC/JZ/JNZ/JBE/JA/CALL/RET/HLT/INC/DEC/";
    char doisBytes[]="/MOV/ADD/SUB/CMP/JMP/JC/JNC/JZ/JNZ/JBE/JA/CALL/";
    char umByte[]="/INC/DEC/RET/HLT/";

    int n = 0 /*Índice do rótulo*/, m = 0/*Contador de EQUs*/, linha = 1;

    while (fgets(aux, sizeof(aux), entrada) != NULL) {
        if (!aux[0]){ //Se o primeiro índice da linha não é nulo, é porque é um rótulo ou um EQU (PARTE 1)
            *token = strtok(aux, " "); //Separa o rótulo da frase inteira
            *token = toupper(*token);

            while(token){
                if (isalpha(token[0])== 0) //Se é zero é porque é número
                    num = *token;
                else if (isalpha(token[0])!=0 && stricmp(token,"EQU")!=0) //Se é uma palavra mas não é EQU
                    strcpy(carac, *token);

                if (strcmp(token, "EQU")==0){ //Se é EQU, então guarda na struct os valores nas variáveis temporárias
                    strcpy(equ[m].nome,carac);
                    equ[m].valor = num;
                    m++;
                }
                else if (!(isalpha(*token))){ //Se é rótulo, salva
                    strcpy(rotulo[n].nome, carac);
                    rotulo[n].valor = num;
                    n++;
                }
            }
        }
        else { //Se não é RÓTULO nem EQU, então é um comando ou argumento de comando(PARTE 2)
            token = strtok(aux," ");
            while (token) {

            }
        }
    linha++;
    }

    fclose(entrada);
    fclose(saida);
}


