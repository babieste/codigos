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

int LimpaArgumento(char *token){ //Função que retira os colchetes, indicadores e vírgula se tiver no argumento. Retorna se o argumento é de um byte ou dois.
    const char virgula = ',';
    const char colchete_abre = '[';
    const char colchete_fecha = ']';
    const char indicador = 'A';
    int DoisBytes = 0;
    int i;

    if(strstr(*token, virgula)!=NULL){ //Verifica a existência de vírgula, e a remove
        DoisBytes = 1;
        for(i = strstr(*token, virgula); i <= sizeof(*token); i++){
            token[i] = token[i+1];
        }
    }
    if(strstr(*token, colchete_abre)!=NULL){ //Colchetes
        for(i = strstr(token, colchete_abre); i <= sizeof(*token); i++)
            token[i] = token[i+1];
        for(i = strstr(*token, colchete_fecha); i <= sizeof(*token); i++)
            token[i] = token[i+1];
    }
    if(strstr(*token, indicador)!=NULL){//Indicador
        for(i = strstr(*token, indicador); i <= sizeof(*token); i++){
            token[i] = token[i+1];
        }
    }
    return DoisBytes;
}

int LeEQU(char *token, equ equ[], int m){
    int i;
    for(i = 0; i <= m; i++){
        if (strcmp(equ[i].nome, *token)==0);
            return equ[i].valor;
    }
    printf("\Rotulo %s nao encontrado", token);
}


char TransformaEmOpcode(char *token){
    //Precisa saber qual é o fucking argumento
}

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
    int DoisBytes;

    //Variáveis temporárias para salvar no EQU
    char carac;
    int num;

    //Mnemônicos
    char mnemonico[]= "#MOV#ADD#SUB#CMP#JMP#JC#JNC#JZ#JNZ#JBE#JA#CALL";
    char quebra[]=" ,\n\t";

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
                if(strstr(token, mnemonico)==NULL){ //Se não é um comando, é um argumento
                    DoisBytes = LimpaArgumento(token);
                    if (DoisBytes == 1)
                        linha = linha+2; //Pula duas linhas porque são dois argumentos por linha
                    if (isalpha(*token)!=0){ //Se é caracter, então um EQU foi utilizado
                        *token = LeEQU(*token, equ, m);
                        fputs(*token, saida);
                        fputs(quebra, saida);
                        *token = strtok(NULL, " ");  //Nova linha
                    }

                }
            }
        }
    linha++;
    }

    fclose(entrada);
    fclose(saida);
}
