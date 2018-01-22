#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 31

void clear()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;

    CONSOLE_SCREEN_BUFFER_INFO tela;
    GetConsoleScreenBufferInfo(hStdOut, &tela);

    FillConsoleOutputCharacter(hStdOut, ' ', tela.dwSize.X * tela.dwSize.Y, coord, &count);

    SetConsoleCursorPosition(hStdOut, coord);
}
int main () {
	char usadas[MAX];
    char palavras[20][30] = {"aviao", "paralelepipedo", "computacao", "governo", "interesse", "trabalho", "auditorio", "retrato", "eletronica", "exame", "empecilho", "habilidade", "lepec"};
	char resposta[MAX], palavra[MAX], usada[MAX], letra, opcao, modo;

    do{
        int u = 0, i = 0, tent=0, ver, pontos;

        clear();

        printf("\n\t\t\tBEM VINDO A FORCA!\n");
        printf("\nEscolha o modo de jogo:\n1. Singleplayer\n2. Multiplayer.\nOpcao: ");
        scanf("%d", &modo);

        clear();
        if(modo == 2)
        {
            printf("\n\nsDigite uma palavra: ");
            scanf("%s", palavra);
        }
        else
        {
            srand(time(NULL));
            i = rand()%13;
            strcpy(palavra, palavras[i]);
        }


		fflush(stdin);

		for (i = 0; i < strlen(palavra); i++) {
                 palavra[i] = toupper(palavra[i]);
            }

		for (i = 0; i < strlen(palavra); i++) {
                resposta[i] = '_';
            }

		//Início do jogo
		while(1)
        {
            ver = 0, pontos = 0;
            tent++;
            clear();

            printf("\n\n\t\t");

            for (i = 0; i < strlen(palavra); i++)
            {
                printf(" %c ", resposta[i]);
            }

            for (i = 0; i < strlen(palavra); i++)
            {
                if(palavra[i] == resposta[i])
                    pontos++;
            }
            if(pontos == strlen(palavra))
                break;

            printf("\n\nA palavra contem a letra:");
            letra = toupper(getch());
            
            //Letras que já foram usadas
            for(u = 0; u < MAX; u++) {
            	usadas[u] = letra;
			}

			printf("\n\nUsadas: ");
				printf(" %c", usadas[u]);
			

            fflush(stdin);

            for (i = 0; i < strlen(palavra); i++)
            {
                if(letra == palavra[i])
                {
                    resposta[i] = letra;
                }
                else
                    ver++;
            }
            if(ver == strlen(palavra))
            {
                printf("\nNao ha esta letra na palavra.");
                Sleep(1500);
            }
		}

            printf("\n\n\nVOCE ACERTOU EM %d TENTATIVAS!", tent);


		do {
			printf("\n\nJogar novamente ?(S/N)");
			opcao = toupper(getch());
		} while (opcao != 'S' && opcao != 'N');
    }while(opcao == 'S');
}
