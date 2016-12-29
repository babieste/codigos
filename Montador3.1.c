//Bárbara Este Fernandez
//RA: 161025901

//Trabalho completo

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

//Inicialização dos arquivos:
FILE *entrada;
FILE *saida;

typedef struct { //Rótulos
    char nome[101];
    int valor;
} rotulos;

typedef struct { //EQUs
    char nome[101];
    char *valor;
} equ;


//CONSERTAR A FUNÇÃO------------------------------------------------------------
int LimpaArgumento(char *token){ //Função que retira os colchetes, indicadores e vírgula se tiver no argumento. Retorna se o argumento é de um byte ou dois.
    int DoisBytes = 0;
    int i;

    if(strchr(token, ",")!=NULL){ //Verifica a existência de vírgula, e a remove
        DoisBytes = 1;
        for(i = *strchr(token, ","); i <= sizeof(token); i++)
            token[i] = token[i+1];
    }
    if(strchr(token, "[")!=NULL){ //Colchetes
        for(i = *strchr(token, "["); i <= sizeof(token); i++)
            token[i] = token[i+1];
        for(i = *strchr(token, "]"); i <= sizeof(token); i++)
            token[i] = token[i+1];
    }
    if(strchr(token, "A")!=NULL){ //Indicador
        for(i = *strchr(token, "A"); i <= sizeof(token); i++)
            token[i] = token[i+1];
    }
    return DoisBytes;
}

int LeEQU(char *token, equ equ[], int m){
    int i;
    for(i = 0; i <= m; i++){
        if (strcmp(equ[i].nome, token)==0);
            return equ[i].valor;
    }
    printf("\nRotulo %s nao encontrado", token);
}


char TransformaEmOpcode(char *token, char comando[], char *opcode){ //Transforma o mnemônico em opcode
	printf("\nentrou na funcao TransformaEmOpcode");
	printf("\ncomando q foi salvo!!!: %s", comando);
    if(strcmp(comando, "MOV")==0){
        if(token[0]=='A' && (strchr(token, "[")!=NULL))
            strcpy(opcode, "a0h");
        else if (token[0] == 'A')
            strcpy(opcode,  "b0h");
        else
            strcpy(opcode,  "a2h");
    }
    else if(strcmp(comando, "ADD")==0){
    	printf("\nENTROU NO COMANDO ADD!!!");
        if(strchr(token, "[")!=NULL){
        	printf("\nopcode: 02h");
        	strcpy(opcode,  "02h");
		}
        else {
        	printf("\nopcode: 04h");
        	strcpy(opcode, "04h");
		}
            
    }
    else if(strcmp(comando, "SUB")==0){
        if(strchr(token, "[")!=NULL) 
        	strcpy(opcode, "2ah");
        else 
        	strcpy(opcode, "2ch");   
    }
    else if(strcmp(comando, "CMP")==0){
        if(strchr(token, "[")!=NULL)
            strcpy(opcode, "3ah");
        else
            strcpy(opcode, "3ch");
    }
    printf("\nse chegou ate aqui ta bom");
    printf("\nOPCODE COPIADO DO STRCPY: %s", opcode);
    return opcode;
}

//-----------------------------------------FUNÇÃO PRINCIPAL-----------------------------------------------------------
int main () {
    //Variáveis
    rotulos rotulo[101];
    equ equ[101];
    char aux[101]; /*Armazena a linha de código a ser lida*/
    char *token;
    char comando[3];
    char opcode[3];
    char argumento[101];
    int DoisBytes;
    char carac[101];
    int num;
    int linha = 1;
    int m = 0 /*Contador de EQUs*/;

    //Mnemônicos
    char mnemonico[]= "MOV/ADD/SUB/CMP";

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

    printf("ESSA PORRA TA FUNCINANDO");
    rewind(entrada);

    while(fgets(aux, 100, entrada)!= NULL){ //Enquanto não é o final do arquivo
        printf("\nentrou no primeiro while");
        printf("\nFrase auxiliar: %s", aux);

        token = strtok(aux, " ");
        printf("\nToken: %s", token);

        while (token != NULL){
            printf("\nentrou no segundo while");

            if(aux[0]!=' '){ //Se o primeiro indice da linha não é um espaço em branco, é um EQU (PARTE 1)
            	printf("\nentrou na primeira condicao: aux[0] = %c", aux[0]);
                printf("\ntoken[0] = %c", token[0]);

                if (isalpha(token[0])==0) { //Se é zero é porque é o valor de um EQU
                	printf("\n%s eh o valor da EQU!", token);
                	equ[m].valor = token;
                	printf("\nequ[m].valor = %s", equ[m].valor);
				}    
                else { //É o nome da EQU
                	printf("\n%s pode ser o nome da EQU!!! OU NAO!!", token);
                    strcpy(carac, token);
                    printf("\ncaractere: %s", carac);
                    if (strcmp(token,"EQU")!=0) { //Se é uma palavra mas não é EQU, é o nome da EQU
                        printf("\n%s eh o nome da EQU!", token);
                        strcpy(equ[m].nome, carac);
                    }
                }
            }
            else { //Se não é EQU, então é um comando ou argumento de comando (PARTE 2)
            	printf("\nentrou na segunda condicao");
                if(strstr(mnemonico, token)==NULL){ //Se não é um comando, é um argumento
                	printf("\neh um argumento!");
                    TransformaEmOpcode(token, comando, opcode);
                    printf("\nSAIU DA FUNCAO, opcde: %s", opcode);
                    printf("\nTOKEN SUJO: %s", token);
                    DoisBytes = LimpaArgumento(token); //Limpa o argumento, para ficar só com o seu valor
                    printf("\nargumento LIMPO: %s", token);
                    if (DoisBytes == 1)
                        linha = linha+2; //Pula duas linhas porque são dois argumentos por linha
                    if (isalpha(*token)!=0){ //Se é caracter, então um EQU foi utilizado
                        *token = LeEQU(token, equ, m);
                        fseek(saida, 0, SEEK_END);
                        fputs(opcode, saida);
                        fputc('\n', saida);
                        fputs(token, saida);
                        fputc('\n',saida);
                    }

                }
                else{ //Guarda o comando para ser usado na leitura do argumento
                	printf("\neh um comando!");
                	strcpy(comando, token);
                    printf("\ncomando: %s!!!", comando);
                }
            }
            printf("\nTERMINOU UM TOKEN\n\n\n");
        token = strtok(NULL, " "); //Nova linha
        } /*while (token != NULL)*/  
    m++;
    } /*while(fgets(aux, 100, entrada) != EOF)*/
    fclose(entrada);
    fclose(saida);
}
