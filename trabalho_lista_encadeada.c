#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

typedef struct reg *no;
struct reg {
	int info;
	struct reg *prox;
};

int main(){
	setlocale(LC_ALL, "Portuguese");
	char reproc; /*resposta do reprocessamento*/
	int op;
	no lista = NULL;
	
	do {
		printf("MENU INCIAL\n\n1- Admissão de funcionário novo\n2- Demissão de funcionário\n3- Mudança de departamento por parte do funcionário\n4- Relação dos funcionários de um departamento\n\nOpção: ");
		scanf(" %d", &op);
		switch (op){
			case 1:
				//do...
				break;
			case 2:
				//do...
				break;
			case 3:
				//do...
				break;
			case 4:
				//do...
				break;
			default:
				printf("\nOpção inválida.");
				break;
		}
		do {
			printf("\nIr novamente? S/N");
			reproc = toupper(getch());
			system("cls");
		} while (reproc != 'S' && reproc != 'N');
	} while (reproc == 'S');
}
