#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define MAX 5

//Definindo as teclas especiais
#define ESC 27
#define F1 59
#define ENTER 13
#define DEL 83
#define BAIXO 80
#define CIMA 72
#define HOME 71



void clear();
//Input e output de matrizes
int lerMatriz (int n, int matriz[n][n]) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("\n Matriz[%d][%d] = ", i+1, j+1);
			scanf(" %d", &matriz[i][j]);
		}
	}
}

int imprimirMatriz(int n, int matriz[n][n]) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%2d ", matriz[i][j]);
		}
		printf("\n");
	}
}

//Transposta
int matrizTransposta(int n, int matriz[n][n], int transposta[n][n]) {
	int i, j, aux;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			transposta[j][i] = matriz[i][j];
		}
	}
}

//Funções com duas matrizes
int duasMatrizes(int n, int A[n][n], int B[n][n]) {
	int i, j;
	
	printf("\nDigite os valores para a primeira matriz:");
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("\nA[%d][%d] = ", i+1, j+1);
			scanf(" %d", &A[i][j]);
		}
	}
	
	printf("\nDigite os valores para a segunda matriz:");
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("\nB[%d][%d] = ", i+1, j+1);
			scanf(" %d", &B[i][j]);
		}
	}
}

int somarMatriz(int n, int A[n][n], int B[n][n], int matriz[n][n]) {
	int i, j;
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			matriz[i][j] = A[i][j] + B[i][j];
		}
	}
}

int subtrairMatriz(int n, int A[n][n], int B[n][n], int matriz[n][n]) {
	int i, j;
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			matriz[i][j] = A[i][j] - B[i][j];
		}
	}
}

int multiplicarMatriz(int n, int A[n][n], int B[n][n], int matriz[n][n]) {
	int i, j;
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			matriz[i][j] = A[i][j] * B[i][j];
		}
	}
}

//v = 1 é verdadeiro, v = 0 é falso
int quadradoMagico(int n, int matriz[n][n]) {
	int i, j;
	int linha[n], coluna[n], dp, ds;
	
	dp = 0;
	ds = 0;
	
	//Soma das linhas e diagonais
	for(i = 0; i < n; i++) {
		linha[i] = 0;
		for(j = 0; j < n; j++) {
			//Linhas
			linha[i] += matriz[i][j];
			//Diagonal principal
			if (i == j) 
				dp += matriz[i][j];
			//Diagonal secundária
			if (i == n - 1 - j)
				ds += matriz[i][j];
		}
	}
	
	//Soma das colunas
	for(j = 0; j < n; j++) {
		coluna[j] = 0;
		for (i = 0; i < n; i++) {
			coluna[j] += matriz[i][j];
		}
	}
	
	//Verifica se a somas linhas, colunas, diagonais são iguais
	int v = 1;
	for (i = 0; i < n; i++) {
		if (linha[i] != coluna[i]) {
			v = 0;
		}
		if (linha[i] != dp || linha[i] != ds || coluna[i] != dp || coluna[i] != ds) {
			v = 0;
		}
	}
	
	return v;
}

//v = 0 falso, v = 1 verdadeiro
int matrizSimetrica(int n, int matriz[n][n]) {
	int i, j, v = 1;
	
	for(i = 0; i < n && v == 1; i++) {
		for(j = 0; j < i && v == 1; j++) {
			if (matriz[i][j] != matriz[j][i])
				v = 0;
		}
	}

	return v;
}

//v = 0 falso, v = 1 verdadeiro
int quadradoLatino(int n, int matriz[n][n]) {
	int i, j, x;
    int v, verif[201][101];
    v = 1;

    for (i = 0; i < n*2; i++) {
        for(j = 0; j < n; j++)
            verif[i][j]=0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (x = 1; x <= n; x++) {
                if (matriz[i][j] == x) {
                    verif[i][x] = 1;
                    verif[j+n][x] = 1;
                }
            }
        }
    }
    
    for (i = 0; i < n*2; i++) {
        for(j = 1;j <= n; j++) {
            if(verif[i][j] == 0)
                v = 0;
        }
    }
	
    return v;
}

//v = 0 falso, v = 1 verdadeiro
int permutacao(int n, int matriz[n][n]) {
	int i, j;
    int v, verific[200];
    v = 1;
    
    for (i = 0; i < n*2; i++)
        verific[i]=0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matriz[i][j]!=0) {
                verific[i]++;
                verific[j+n]++;
            }
        }
    }
    
    for (i = 0; i < n*2; i++) {
        if (verific[i] != 1)
            v = 0;
    }

    return v;
}

//Menu Inicial
int menu_inicial() {
	int tecla = CIMA, op = 0, escolha;
	char umaMatriz[] = "Funcoes com uma matriz";
	char duasMatrizes[] = "Funcoes com duas matrizes";
	char ajuda[] = "Pressione F1 para ajuda";
	
	while (tecla != ESC) {
		if(tecla == F1) {
			clear();
			printf("Bem vindo! Pressione ESC para sair do programa,\nou uma das setas (para cima ou para baixo) \npara retornar ao menu inicial!");
			tecla = getch();
		}
		if (tecla == CIMA) {
			clear();
			printf("%s\n\n", ajuda);
			printf("> %s\n", umaMatriz);
			printf("  %s", duasMatrizes);
			op = CIMA;
		}
		if (tecla == BAIXO) {
			clear();
			printf("%s\n\n", ajuda);
			printf("  %s\n", umaMatriz);
			printf("> %s", duasMatrizes);
			op = BAIXO;
		}
		if (tecla == ENTER) {
			if (op == CIMA) {
				clear();
				menu_funcoes(1);
				escolha = menu_funcoes(1);
				return escolha;
			}
			else if (op == BAIXO) {
				clear();
				menu_funcoes(2);
				escolha = menu_funcoes(2);
				return escolha;
			}
				
		}
		tecla = getch(); 
	}
}

int menu_funcoes(int escolha) {
	int tecla = 0, count = 0;
	
	while (tecla != ESC) {
		if (escolha == 1) {
				if (count == 0) {
					clear();
					printf("> Matriz Transposta\n  Quadrado Magico\n  Matriz Simetrica\n  Quadrado Latino\n  Permutacao");
					tecla = getch();
						if (tecla == ENTER) return count;
						else if (tecla == HOME) menu_inicial();
						else if (tecla == CIMA) count = 4;
						else if (tecla == BAIXO) count++;
					}
					if (count == 1) {
						clear();
						printf("  Matriz Transposta\n> Quadrado Magico\n  Matriz Simetrica\n  Quadrado Latino\n  Permutacao");
						tecla = getch();
							if (tecla == ENTER) return count;
							else if (tecla == HOME) menu_inicial();
							else if (tecla == CIMA) count--;
							else if (tecla == BAIXO) count++;
					}
					if (count == 2) {
						clear();
						printf("  Matriz Transposta\n  Quadrado Magico\n> Matriz Simetrica\n  Quadrado Latino\n  Permutacao");
						tecla = getch();
							if (tecla == ENTER) return count;
							else if (tecla == HOME) menu_inicial();
							else if (tecla == CIMA) count--;
							else if (tecla == BAIXO) count++;
					}
					if (count == 3) {
						clear();
						printf("  Matriz Transposta\n  Quadrado Magico\n  Matriz Simetrica\n> Quadrado Latino\n  Permutacao");
						tecla = getch();
							if (tecla == ENTER) return count;
							else if (tecla == HOME) menu_inicial();
							else if (tecla == CIMA) count--;
							else if (tecla == BAIXO) count++;
					}
					if (count == 4) {
						clear();
						printf("  Matriz Transposta\n  Quadrado Magico\n  Matriz Simetrica\n  Quadrado Latino\n> Permutacao");
						tecla = getch();
							if (tecla == ENTER) return count;
							else if (tecla == HOME) menu_inicial();
							else if (tecla == CIMA) count--;
							else if (tecla == BAIXO) count = 0;
					}
		}
		else if (escolha == 2) {
				if (count == 0) {
					clear();
					printf("> Somar Matrizes\n  Subtrair Matrizes\n  Multiplicar Matrizes");
					tecla = getch();
						if (tecla == ENTER) return count;
						else if (tecla == HOME) menu_inicial();
						else if (tecla == CIMA) count = 2;
						else if (tecla == BAIXO) count++;
					}
					if (count == 1) {
						clear();
						printf("  Somar Matrizes\n> Subtrair Matrizes\n  Multiplicar Matrizes");
						tecla = getch();
							if (tecla == ENTER) return count;
							else if (tecla == HOME) menu_inicial();
							else if (tecla == CIMA) count--;
							else if (tecla == BAIXO) count++;
					}
					if (count == 2) {
						clear();
						printf("  Somar Matrizes\n  Subtrair Matrizes\n> Multiplicar Matrizes");
						tecla = getch();
							if (tecla == ENTER) return count;
							else if (tecla == HOME) menu_inicial();
							else if (tecla == CIMA) count--;
							else if (tecla == BAIXO) count = 0;
					}
		}
	}
}


//ONDE EU PAREI: AS funções 01 e 02 retornam na menu_inicial, mas tá precisando apertar ENTER várias vezes pra conseguir retorná-las, ARRUMAR.
//O retorno das funções de duas matrizes não estão funcionando direito!

int main () {
	int tecla, n = 0, matriz[MAX][MAX], transposta[MAX][MAX], A[MAX][MAX], B[MAX][MAX];
		
		do {
			menu_inicial();
			printf("\n\nvalor resultante = %d", menu_inicial());
			//Retornos das funções de uma matriz:
			if (menu_funcoes(1) == 0) {
				do {
					printf("\n\n\nEscolha a ordem da matriz: ");
					scanf(" %d", &n);
					clear();	
				} while (n > 5);
				printf("\nVoce escolheu matriz transposta!\n");
				lerMatriz(n, matriz);
				matrizTransposta(n, matriz, transposta);
				printf("\n\nA matriz transposta eh: \n");
				imprimirMatriz(n, transposta);
			}
			else if (menu_funcoes(1) == 1) {
				do {
					printf("\n\n\nEscolha a ordem da matriz: ");
					scanf(" %d", &n);
					clear();	
				} while (n > 5);
				printf("\nVoce escolheu Quadrado Magico!\n");
				lerMatriz(n, matriz);
				quadradoMagico(n, matriz);
				if (quadradoMagico(n, matriz) == 1)
					printf("\n\n\nA matriz eh um quadrado magico!");
				else
					printf("\n\n\nA matriz nao eh um quadrado magico!");
			}
			else if (menu_funcoes(1) == 2) {
				do {
					printf("\n\n\nEscolha a ordem da matriz: ");
					scanf(" %d", &n);
					clear();	
				} while (n > 5);
				printf("\nVoce escolheu matriz simetrica!\n");
				lerMatriz(n, matriz);
				matrizSimetrica(n, matriz);
				if (matrizSimetrica(n, matriz) == 1)
					printf("\n\n\nA matriz eh simetrica!");
				else
					printf("\n\n\nA matriz nao eh simetrica!");
			}
			else if (menu_funcoes(1) == 3) {
				do {
					printf("\n\n\nEscolha a ordem da matriz: ");
					scanf(" %d", &n);
					clear();	
				} while (n > 5);
				printf("\nVoce escolheu Quadrado Latino!\n");
				lerMatriz(n, matriz);
				quadradoLatino(n, matriz);
				if (quadradoLatino(n, matriz) == 1)
					printf("\n\n\nA matriz eh um quadrado latino!");
				else
					printf("\n\n\nA matriz nao eh um quadrado latino!");
			}
			else if (menu_funcoes(1) == 4) {
				do {
					printf("\n\n\nEscolha a ordem da matriz: ");
					scanf(" %d", &n);
					clear();	
				} while (n > 5);
				printf("\nVoce escolheu Permutacao!\n");
				lerMatriz(n, matriz);
				permutacao(n, matriz);
				if (permutacao(n, matriz) == 1)
					printf("\n\n\nA matriz eh uma permutacao!");
				else
					printf("\n\n\nA matriz nao eh uma permutacao!");
			}
			
			//Retorno das funções de duas matrizes:
			else if (menu_funcoes(2) == 0) {
				printf("\nVoce escolheu somar matrizes!\n");
				duasMatrizes(n, A, B);
				somarMatriz(n, A, B, matriz);
				printf("\n\n\nA matriz resultante eh:\n");
				imprimirMatriz(n, matriz);
			}
			else if (menu_funcoes(2) == 1) {
				printf("\nVoce escolheu subtrair matrizes!\n");
				duasMatrizes(n, A, B);
				subtrairMatriz(n, A, B, matriz);
				printf("\n\n\nA matriz resultante eh:\n");
				imprimirMatriz(n, matriz);
			}
			else if (menu_funcoes(2) == 2) {
				printf("\nVoce escolheu multiplicar matrizes!\n");
				duasMatrizes(n, A, B);
				multiplicarMatriz(n, A, B, matriz);
				printf("\n\n\nA matriz resultante eh:\n");
				imprimirMatriz(n, matriz);
			}
			
			//Reprocessamento final:
			do {
				printf("\n\nIr novamente? S/N\n");
				tecla = toupper(getch());
			} while (tecla != 'S' && tecla != 'N');
		} while (tecla == 'S');
}

//Limpa a tela
void clear() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;

    CONSOLE_SCREEN_BUFFER_INFO tela;
    GetConsoleScreenBufferInfo(hStdOut, &tela);

    FillConsoleOutputCharacter(hStdOut, ' ', tela.dwSize.X * tela.dwSize.Y, coord, &count);

    SetConsoleCursorPosition(hStdOut, coord);
}
