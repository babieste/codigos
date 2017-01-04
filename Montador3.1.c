//Bárbara Este Fernandez
//RA: 161025901

//Trabalho completo

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#include <locale.h>

//Inicialização dos arquivos:
FILE *entrada;
FILE *saida;

typedef struct { //EQUs
    char nome[101];
    int valor;
} equ;


void LimpaArgumento(char *token){ //Função que retira os colchetes, indicadores e vírgula se tiver no argumento. Retorna se o argumento é de um byte ou dois.
	printf("\n\tEntrou na função LimpaArgumento:");
    int DoisBytes = 0;
    int i, j;
    
    if(strchr(token, ",")!=NULL){
    	printf("\nA função possui dois bytes!");
    	DoisBytes = 1;
	}
    	
	
	for(i = 0; i < strlen(token); i++){
		if(token[i] == ',' || token[i] == '[' || token[i] == ']' || token[i] == 'A'){
			for(j = i; j < strlen(token); j++){
				token[j] = token[j+1];
			}
			i--;
		}	
	}
}

int LeEQU(char *token, equ equ[], int m){
	printf("\n\tEntrou na função LeEQU:");
    int i;
    
    for(i = 0; i < m; i++){
        if (strcmp(equ[i].nome, token)==0) {
        	printf("\n\tValor do EQU %s = %d", token, equ[i].valor);
            return equ[i].valor;
		} 	
    }
    printf("\n\tEQU %s não encontrado", token);
    getch();
    exit(1);
}


char TransformaEmOpcode(char *token, char comando[], char *opcode){ //Transforma o mnemônico em opcode
	printf("\n\tEntrou na função TransformaEmOpcode:");
    if(strcmp(comando, "MOV")==0){
        if(token[0]=='A' && (strchr(token, "[")!=NULL))
            strcpy(opcode, "a0h");
        else if (token[0] == 'A')
            strcpy(opcode,  "b0h");
        else
            strcpy(opcode,  "a2h");
    }
    else if(strcmp(comando, "ADD")==0){
        if(strchr(token, "[")!=NULL)
        	strcpy(opcode,  "02h");
        else
        	strcpy(opcode, "04h");      
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
    printf("\n\tOPCODE de %s = %s", comando, opcode);
    return opcode;
}

//-----------------------------------------FUNÇÃO PRINCIPAL-----------------------------------------------------------
int main () {
	
	setlocale(LC_ALL,"portuguese");
    //Variáveis
    equ equ[101];
    char aux[101]; /*Armazena a linha de código a ser lida*/
    char *token;
    char comando[3];
    char opcode[3];
    char argumento[101];
    int DoisBytes;
    char carac[101];
    int valor, i, retorno;
    int linha = 1;
    int m = 0 /*Contador de EQUs*/;

    //Mnemônicos
    char mnemonico[]= "MOV/ADD/SUB/CMP";

    //Verificação dos arquivos
    if((entrada = fopen("entrada.txt", "rt")) == NULL){
        printf("\nErro na inicializacao do arquivo de mnemonicos."); getch(); exit(1);
    }
    if((saida = fopen("saida.txt", "wt")) == NULL){
        printf("\nErro na abertura do arquivo de opcodes."); getch(); exit(1);
    }
    
    rewind(entrada);

    while(fgets(aux, 100, entrada)!= NULL){ //Enquanto não é o final do arquivo
        printf("\nFrase auxiliar: %s", aux);

        token = strtok(aux, " ");

        while (token != NULL){
        	printf("\nToken: %s", token);
            if(aux[0]!=' '){ //Se o primeiro indice da linha não é um espaço em branco, é um EQU (PARTE 1)
            	printf("\nEntrou para a condição de ser EQU:");
                if (atoi(token)!=0) { //Se é diferente de zero é porque é o valor de um EQU
                	equ[m].valor = atoi(token);
                	
                	printf("\nÉ um valor de EQU: %d", equ[m].valor);
				}    
                else { 	//É o nome da EQU
                    strcpy(carac, token);
                    if (strcmp(token,"EQU")!=0) { //Se é uma palavra mas não é EQU, é o nome da EQU
                        strcpy(equ[m].nome, carac);
                        printf("\nÉ o nome da EQU: %s", equ[m].nome);
                    }
                }
            }
            
            
            else { //Se não é EQU, então é um comando ou argumento de comando (PARTE 2)
            	printf("\nEntrou na condição de ser comando ou argumento:");
                if(strstr(mnemonico, token)==NULL){ //Se não é um comando, é um argumento
                	printf("\nArgumento sujo: %s", token);
                	
                    LimpaArgumento(token);
                    TransformaEmOpcode(token, comando, opcode);
                    
                    printf("\nArgumento limpo: %s", token);
                    if (isalpha(*token)!=0){ //Se é caracter, então um EQU foi utilizado
                    	printf("\nUm EQU foi utilizado! (%s)", token);
                        valor = LeEQU(token, equ, m);
                        printf("\nValor: %d", valor);
                    }
                    else {
                    	valor = atoi(token);
                    	printf("\nValor direto: %d", valor);
					}
                    
                    printf("\nSalvando arquivos...");
					fseek(saida, 0, SEEK_END);
                    fputs(opcode, saida);
                    printf("\nSalvou o opcode...");
                    fputc('\n', saida);
                    //-------------------------------------------------------------------------------------------------------------
                    fputs(valor, saida);
                    printf("\nSalvou o valor...");
                    fputc('\n',saida);
                    
                    printf("\nArquivos salvos!");
                }
                
                else{ //Guarda o comando para ser usado na leitura do argumento
                	printf("\nComando: %s", token);
                	strcpy(comando, token);
                }
            }
        token = strtok(NULL, " "); //Nova linha
        } /*while (token != NULL)*/
        printf("\n\nNOVA LINHA\n");
        m++;
    } /*while(fgets(aux, 100, entrada) != EOF)*/
    printf("\nEQUs:");
    for(i = 0; i < m; i++)
    	if (equ[i].valor != 0)
    		printf("\n%s EQU %d", equ[i].nome, equ[i].valor);
    fclose(entrada);
    fclose(saida);
}
