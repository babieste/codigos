#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>

//protótipos
int perso(int modo, int i);
int chance(int h, int d);
int jogo(int modo, int jogador[2], int vida[2]);
void clear();

int main () {
	char resposta;
	int modo, jogador[2], i, ver;

	do {
        int vida[] = {10, 10};

		printf("\t _    _                       _         _____             _        \n\t| |  | |                     | |       |  __ \\           | |       \n\t| |__| | ___  _ __ __ _    __| | ___   | |  | |_   _  ___| | ___  \n\t|  __  |/ _ \\| '__/ _` |  / _` |/ _ \\  | |  | | | | |/ _ \\ |/ _ \\ \n\t| |  | | (_) | | | (_| | | (_| | (_) | | |__| | |_| |  __/ | (_) |\n\t|_|  |_|\\___/|_|  \\__,_|  \\__,_|\\___/  |_____/ \\__,_|\\___|_|\\___/ ");


		do {
			printf("\n\n\n\n\t\t\t1. Multiplayer\n\n\t\t\t\t2. Singleplayer\n\n\t\t\t\t\t3. Instrucoes\n\n\t\t\t\t\t\t0. Sair\n\n\t\t\tOpcao: ");
			scanf(" %d", &modo);
			clear();
		} while (modo < 1 && modo > 3);

		switch(modo)
		{
        case 1:
            for(i = 0;i<2; i++)
                jogador[i] = perso(modo, i);
            break;
        case 2:
            srand(time(NULL));
            jogador[0] = perso(modo, i);
            jogador[1] = rand()%3 + 1;
            break;
        case 3:
            printf("\nINSTRUCOES:\n\n\tAs habilidades de numeros 1, 2, 3 causam respectivamente 1, 2 e 3\n de dano e possuem respectivamente 80%%, 60%% e 40%% de chance de acerto, as \n habilidades de numero 4 diminuem pela metade a chande de acerto das \n habilidades inimigas. \n");
            printf("\n\nPressione qualquer tecla para voltar ao menu.");
            getch();
            clear();
            main();
            break;
        case 0:
            printf("\n\n\t\t\tOBRIGADO POR JOGAR!\n\t\tPressione qualquer tecla para fechar.");
            getch();
		}


        if(modo != 0)
        {
        printf("\n\n\n\n\n\n\t\t\tQUE A BATALHA COMECE!");
        Sleep(1500);

        while(1)
        {
            ver = 0;
            jogo(modo, jogador, vida);
            for(i = 0; i<2; i++)
            {
                if(vida[i] <= 0)
                {
                    ver = 1;
                    break;
                }

            }
            if(ver)
                break;
        }

        clear();

        if(vida[0] <= 0 && vida[1] > 0)
            printf("\nO JOGADOR 2 VENCEU!");
        else if(vida[1] <= 0 && vida[0] > 0)
            printf("\nO JOGADOR 1 VENCEU!");
        else if(vida[1] <= 0 && vida[0] <= 0)
            printf("\nEMPATE!");

		do {
			printf("\n\nJogar novamente? S/N");
			resposta = toupper(getch());
			clear();
		} while (resposta != 'S' && resposta != 'N');
        }
	} while (resposta == 'S');
}

int perso(int modo, int i)
{
    if(modo == 1)
    {
        int jogador;
            do {
                printf("\n\t\t\tVoce escolheu Multiplayer!\n\n\n");
                printf("\t\tJogador %d, escolha um personagem:\n\n\t\t1. Cavaleiro\n\t\t2. Mago\n\t\t3. Arqueiro\n\n\t\tOpcao: ", i+1);
                scanf(" %d", &jogador);
                clear();
            } while (jogador < 1 && jogador > 3);

        return jogador;
        clear();
    }

    if(modo == 2)
    {
        int opcao;
        do {
            printf("\n\t\t\tVoce escolheu Singleplayer!\n\n\n");
            printf("\t\tEscolha um personagem:\n\n\t\t1. Cavaleiro\n\t\t2. Mago\n\t\t3. Arqueiro\n\n\t\tOpcao: ");
            scanf(" %d", &opcao);
            clear();
        } while (opcao < 1 && opcao > 3);

        return opcao;
    }
}

int chance(int h, int d)
{
    int p, c;
    srand(time(NULL));
    p = rand()%100 + 1;

    if(h == 1)
        c = 80;
    else if(h == 2)
        c = 60;
    else if(h == 3)
        c = 40;
    else if(h == 1 && d == 4)
        c = 40;
     else if(h == 2 && d == 4)
        c = 30;
    else if(h == 3 && d == 4)
        c = 20;

    if(p <= c)
        return 1;
    else
        return 0;
}

int jogo(int modo, int jogador[2], int vida[2])
{
    int i, hab[2];
    char jog[2][20] = {"JOGADOR", "COMPUTADOR"};

    clear();
    if(modo == 1)
    {
        for(i = 0; i<2; i++)
        {
            switch(jogador[i])
            {
            case 1:
                clear();
                printf("\n\tHABILIDADES %s %d (Cavaleiro):\n\tVIDA: %d\n\n\t1. Ataque Direto.\t2. Corte frontal\n\n\t3. Golpe Perfurante.\t4. Usar Escudo\n\n\tOpcao:",jog[0], i+1, vida[i]);
                scanf("%d", &hab[i]);
                break;
            case 2:
                clear();
                printf("\n\tHABILIDADES %s %d (Mago):\n\tVIDA: %d\n\n\t1. Bola de Fogo.\t2. Ataque Gelido\n\n\t3. Esfera Negra.\t4. Escudo Magico\n\n\tOpcao:",jog[0], i+1, vida[i]);
                scanf("%d", &hab[i]);
                break;
            case 3:
                clear();
                printf("\n\tHABILIDADES %s %d (Arqueiro):\n\tVIDA: %d\n\n\t1. Tiro Certo\t2. Flecha Perfurante\n\n\t3. Rajada de Flechas\t4. Esquiva\n\n\tOpcao:",jog[0], i+1, vida[i]);
                scanf("%d", &hab[i]);
                break;
            }
        }
        if(hab[0] != 4 && hab[0] == 1 && chance(hab[0], hab[1]))
            vida[1] -= 1;
        else if(hab[0] != 4 && hab[0] == 2 && chance(hab[0], hab[1]))
            vida[1] -= 2;
        else if(hab[0] != 4 && hab[0] == 3 && chance(hab[0], hab[1]))
            vida[1] -= 3;
        if(hab[1] != 4 && hab[1] == 1 && chance(hab[1], hab[0]))
            vida[0] -= 1;
        else if(hab[1] != 4 && hab[1] == 2 && chance(hab[1], hab[0]))
            vida[0] -= 2;
        else if(hab[1] != 4 && hab[1] == 3 && chance(hab[1], hab[0]))
            vida[0] -= 3;
    }
    else if(modo == 2)
    {
        srand(time(NULL));

        for(i = 0; i<2; i++)
            switch(jogador[i])
            {
            case 1:
                clear();
                printf("\n\tHABILIDADES %s (Cavaleiro):\n\tVIDA: %d\n\n\t1. Ataque Direto.\t2. Corte frontal\n\n\t3. Golpe Perfurante.\t4. Usar Escudo\n\n\tOpcao:",jog[i], vida[i]);
                if(i == 0)
                    scanf("%d", &hab[i]);
                else
                {
                    printf("\n\n\tEscolhendo.");
                    for(i = 0; i<3; i++)
                    {
                        Sleep(600);
                        printf(".");
                    }
                    hab[1] = rand()%4 + 1;
                }

                break;
            case 2:
                clear();
                printf("\n\tHABILIDADES %s (Mago):\n\tVIDA: %d\n\n\t1. Bola de Fogo.\t2. Ataque Gelido\n\n\t3. Esfera Negra.\t4. Escudo Magico\n\n\tOpcao:",jog[i], vida[i]);
                if(i == 0)
                    scanf("%d", &hab[i]);
                else
                {
                    printf("\n\n\tEscolhendo.");
                    for(i = 0; i<3; i++)
                    {
                        Sleep(600);
                        printf(".");
                    }
                    hab[1] = rand()%4 + 1;
                }
                break;
            case 3:
                clear();
                printf("\n\tHABILIDADES %s (Arqueiro):\n\tVIDA: %d\n\n\t1. Tiro Certo\t2. Flecha Perfurante\n\n\t3. Rajada de Flechas\t4. Esquiva\n\n\tOpcao:",jog[i], vida[i]);
                if(i == 0)
                    scanf("%d", &hab[i]);
                else
                {
                    printf("\n\n\tEscolhendo.");
                    for(i = 0; i<3; i++)
                    {
                        Sleep(600);
                        printf(".");
                    }
                    hab[1] = rand()%4 + 1;
                }
                break;
            }

        if(hab[0] != 4 && hab[0] == 1 && chance(hab[0], hab[1]))
            vida[1] -= 1;
        else if(hab[0] != 4 && hab[0] == 2 && chance(hab[0], hab[1]))
            vida[1] -= 2;
        else if(hab[0] != 4 && hab[0] == 3 && chance(hab[0], hab[1]))
            vida[1] -= 3;
        if(hab[1] != 4 && hab[1] == 1 && chance(hab[1], hab[0]))
            vida[0] -= 1;
        else if(hab[1] != 4 && hab[1] == 2 && chance(hab[1], hab[0]))
            vida[0] -= 2;
        else if(hab[1] != 4 && hab[1] == 3 && chance(hab[1], hab[0]))
            vida[0] -= 3;
    }
}

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
