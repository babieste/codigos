#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <ctype.h>

int tab[5][5];

void ola();
int resolve();
void inic();
void impr();
int mover();
int vit();
void clear();

int d;

int main()
{
    int peca;
    char resp;

    do
    {
        clear();
        ola();
        inic();

        while(1)
        {

            clear();

            impr();

            if(vit())
            {
                printf("\n\n\t\t\t\tVOCE VENCEU!\n\n");
                break;
            }
                printf("\n\n\tPeca a mover: ");
                scanf("%d", &peca);

            if(!mover(peca))
            {
                printf("\n\tMovimento impossivel!");
                Sleep(1000);
            }

        }
        do
        {
            printf("\t\tDeseja jogar novamente?(S/N)");
            resp = toupper(getch());
        }while(resp != 'S' && resp != 'N');
    }while(resp == 'S');

}

int resolve(int peca[])
{
    int inv = 0;
    int i, j;
    for (i = 0; i <d*d-1; i++)
    {
        for (j = i + 1; j <d*d-1; j++)
        {
            if (peca[i] > peca[j])
            {
                inv++;
            }
        }
    }
    return (inv % 2 == 0);
}

void ola()
{
    int dif;
    system("color F");
    do
    {
    printf("\n\t\t\tBEM VINDO AO JOGO DO QUINZE.");
    printf("\n\n\tSelecione a dificuldade:\n1. Facil\n2. Medio\n3. Dificil\nOpcao: ");
    scanf("%d", &dif);

    if(dif != 1 && dif != 2 && dif != 3)
    {
        printf("\nOpcao invalida!\n");
        Sleep(1000);
        clear();
    }

    }while(dif != 1 && dif != 2 && dif != 3);

    switch(dif)
    {
    case 1:
        d = 3;
        break;
    case 2:
        d = 4;
        break;
    case 3:
        d = 5;
        break;
    }
}

void inic()
{

    int i, j, v[d*d], cont = 0, ver, inv = 0, aux;

    srand(time(NULL));

    v[d*d-1] = 0;

    do
    {
        v[0] = rand()%(d*d-1) + 1;
        for(i = 1; i<d*d-1; i++)
        {
            v[i] = rand()%(d*d-1) + 1;
            do
            {
                ver = 0;
                for(j = 0; j<i; j++)
                {
                    if(v[i] == v[j])
                        ver = 1;
                }
                if(ver)
                    v[i] = rand()%(d*d-1) + 1;
            }while(ver);
        }
    }while(!resolve(v));


    for (i = 0; i<d; i++)
    {
        for(j = 0; j<d; j++)
        {
            tab[i][j] = v[cont];
            cont++;
        }
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

void impr()
{
    int i, j, k;
    printf("\n\n");
    printf("\t");
    for(i = 0; i<d; i++)
        printf("--------");
    printf("\n");

    for (i = 0; i<d; i++)
    {
        for(j = 0; j<d; j++)
        {
            if(tab[i][j] == 0)
                printf("\t|   _");
            else
                printf("\t|   %d", tab[i][j]);
            if (j == d-1)
                printf("\t|");
        }
        if (i != d-1)
        {
            printf("\n");
            for(k = 0; k<d; k++)
                printf("\t|______");
            printf("\t|\n");
            for(k = 0; k<d+1; k++)
                printf("\t|");
            printf("\n");
        }
        //printf("\n\t|______\t|______\t|______\t|______\t|\n\t|\t|\t|\t|\t|\n");
    }
    printf("\n\t");
    for(i = 0; i<d; i++)
        printf("--------");
    printf("\n");
}

int mover(int peca)
{
    int i, j;
    for (i = 0; i<d; i++)
    {
        for (j = 0; j<d; j++)
        {
            if(tab[i][j] == peca)
            {
                if (i > 0)
                {
                    if(tab[i-1][j] == 0)
                    {
                        tab[i-1][j] = peca;
                        tab[i][j] = 0;
                        return 1;
                    }
                }
                if (j > 0)
                {
                    if(tab[i][j-1] == 0)
                    {
                        tab[i][j-1] = peca;
                        tab [i][j] = 0;
                        return 1;
                    }
                }
                if (i < d-1)
                {
                    if(tab[i+1][j] == 0)
                    {
                        tab[i+1][j] = peca;
                        tab [i][j] = 0;
                        return 1;
                    }
                }
                if (j < d-1)
                    if(tab[i][j+1] == 0)
                    {
                        tab[i][j+1] = peca;
                        tab[i][j] = 0;
                        return 1;
                    }
            }
        }
    }
    return 0;
}

int vit()
{
    int cont = 1, i, j, ponto = 0;
    for (i = 0; i<d; i++)
    {
        for(j = 0; j<d; j++, cont++)
        {
             if(tab[i][j] == cont)
                ponto++;
        }
    }
    if(ponto == d*d-1)
        return 1;
    else
        return 0;
}
