//Bárbara Este Fernandez
//RA: 161025901

//Trabalho completo

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
    printf("\nRotulo %s nao encontrado", token);
}


char TransformaEmOpcode(char *token, char argumento[]){ //Transforma o mnemônico em opcode
    if(strcmp(*token, "MOV")==0){
        if(argumento[0]=='A' && (strstr(argumento,'[')!=NULL))
            return "a0h";
        else if (argumento[0] == 'A')
            return "b0h";
        else
            return "a2h";
    }
    else if(strcmp(*token, "ADD")==0){
        if(strstr(argumento, '[')!=NULL)
            return "02h";
        else
            return "04h";
    }
    else if(strcmp(*token, "SUB")==0){
        if(strstr(argumento, '[')!=NULL)
            return "2ah";
        else
            return "2ch";
    }
    else if(strcmp(*token, "CMP")==0){
        if(strstr(argumento, '[')!=NULL)
            return "3ah";
        else
            return "3ch";
    }
    else if(strcmp(*token, "JMP")==0)
        return "ebh";
    else if(strcmp(*token, "JC")==0)
        return "72h";
    else if(strcmp(*token, "JNC")==0)
        return "73h";
    else if(strcmp(*token, "JZ")==0)
        return "74h";
    else if(strcmp(*token, "JNZ")==0)
        return "75h";
    else if(strcmp(*token, "JBE")==0)
        return "76h";
    else if(strcmp(*token, "JA")==0)
        return "77h";
    else
        printf("\nO comando %s eh invalido", token);
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
    char opcode[3];
    int DoisBytes;

    //Variáveis temporárias para salvar no EQU
    char carac;
    char argumento;
    int num;

    //Mnemônicos
    char mnemonico[]= "#MOV#ADD#SUB#CMP#JMP#JC#JNC#JZ#JNZ#JBE#JA#CALL";
    char quebra[]="\n";

    int n = 0 /*Índice do rótulo*/, m = 0/*Contador de EQUs*/, linha = 1;

    while (fgets(aux, sizeof(aux), entrada) != NULL) {
        if (aux[0]!=" "){ //Se o primeiro índice da linha não é nulo, é porque é um rótulo ou um EQU (PARTE 1)
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
                    strcpy(argumento, *token);
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
                else{ //Coloca o comando no arquivo de saida
                    strcpy(opcode, TransformaEmOpcode(*token, argumento));
                    fputs(argumento, saida);
                    fputs(quebra, saida);
                    linha++;
                    *token = strtok(NULL, " ");
                }
            }
        }
    }
    fclose(entrada);
    fclose(saida);
}
