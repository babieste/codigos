#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

typedef struct {
	int numero, salario, departamento;
} info;

typedef struct reg *no;
struct reg {
	int numero;
	int salario;
	int departamento;
	struct reg *prox;
};

//Mostra os elementos da lista
void mostra_lista(no lista){
	no p = lista;
	
	while (p){
		printf("\nN�mero: %d\tN�vel Salarial: %d\tDepartamento: %d", p->numero, p->salario, p->departamento);
		p = p->prox;
	}
	
}

void novo_funcionario(no *lista, info info) {
	no p = (no) malloc(sizeof(struct reg));
	
	p->numero = info.numero;
	p->salario = info.salario;
	p->departamento = info.departamento;
	p->prox = NULL;
	
	if (*lista == NULL)
		*lista = p;
	else {
		no q = *lista;
		while (q->prox)
			q = q->prox;
		q->prox = p;
	}
};

int mudar_departamento(no *lista, info info, int num) {
	int novo_departamento;
	printf("\nIndique o novo departamento: ");
	scanf(" %d", &novo_departamento);
	
	no p = *lista;
		
	while(p){
		if(p->numero == num) {
			p->departamento = novo_departamento;
		}
		p = p->prox;
	}
}

//N�o funfa
int demitir_funcionario(no *lista, int num){
	no p = *lista;
	
	while(p->prox != num){
		p = p->prox;
	}
	no q = p;
	q->prox = *lista;
	*lista = aaa;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	char reproc; /*resposta do reprocessamento*/
	int op, num /*n�mero do funcion�rio a ser mudado ou demitido*/;
	info info;
	no lista = NULL;
		
	do {
		printf("MENU INCIAL\n\n1- Admiss�o de funcion�rio novo\n2- Demiss�o de funcion�rio\n3- Mudan�a de departamento por parte do funcion�rio\n4- Rela��o dos funcion�rios de um departamento\n\nOp��o: ");
		scanf(" %d", &op);
		switch (op){
			case 1:
				printf("\nN�mero, n�vel salarial, departamento: ");
				scanf(" %d %d %d", &info.numero, &info.salario, &info.departamento);
				novo_funcionario(&lista, info);
				mostra_lista(lista);
				break;
			case 2:
				printf("\nN�mero do funcion�rio a ser demitido: ");
				scanf(" %d", &num);
				demitir_funcionario(&lista, num);
				break;
			case 3:
				printf("\nN�mero do funcion�rio a ser mudado: ");
				scanf(" %d", &num);
				mudar_departamento(&lista, info, num);
				mostra_lista(lista);
				break;
			case 4:
				//do...
				break;
			default:
				printf("\nOp��o inv�lida.");
				break;
		}
		do {
			printf("\n\nIr novamente? S/N");
			reproc = toupper(getch());
			system("cls");
		} while (reproc != 'S' && reproc != 'N');
	} while (reproc == 'S');
}