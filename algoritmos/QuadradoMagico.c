#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MAX 101

int main () {
	int x, n, i, j;
	int matriz[MAX][MAX];
	char resposta;
	
	do {
		do {
			printf("\nDigite um numero n impar: ");
			scanf(" %d", &n);
		} while (n%2 == 0);
		
		//Preenchimento da matriz
				i = n/2;
				j = n - 1;
				for (x = 1; x <= n*n; x++) {
					matriz[i][j] = x;
					if (x%n == 0)
						j--;
					else {
						i++;
						j++;
						if (j == n)
							j = 0;
						if (i == n)
							i = 0;
					}	
				}
		
		//Impressão da matriz
		for (i = 0; i < n; i++) {
    		for (j = 0; j < n; j++)
      			printf ("%3d ",matriz[i][j]);
    			printf ("\n");
  		}


		do {
			printf("\n\nIr novamente? S/N");
			resposta = toupper(getch());
		} while (resposta != 'S' && resposta != 'N');
	} while (resposta == 'S');
	getch();
}
