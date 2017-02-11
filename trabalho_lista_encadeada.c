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
	info info;
	struct reg *prox;
};

//Mostra os elementos da lista
void mostra_lista(no lista){
	no p = lista;
	
	while (p){
		printf("\nNúmero: %d\tNível Salarial: %d\tDepartamento: %d", p->info.numero, p->info.salario, p->info.departamento);
		p = p->prox;
	}
	
}

void novo_funcionario(no *lista, info info) {
	no p = (no) malloc(sizeof(struct reg));
	
	p->info.numero = info.numero;
	p->info.salario = info.salario;
	p->info.departamento = info.departamento;
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

void mudar_departamento(no *lista, info info, int num) {
	no q = (no) malloc(sizeof(struct reg));
	no p = *lista;
	
	int novo_departamento;
	
	//Não muda o valor
	while(p){
		if(p->info.numero == num) {
			q->info.numero = p->info.numero;
			q->info.salario = p->info.salario;
			printf("\nIndique o novo departamento: ");
			scanf(" %d", &novo_departamento);
			q->info.departamento = novo_departamento;
			
			q->prox = *lista;
			no q = *lista;
			
			free(p);
		}
		p = p->prox;
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	char reproc; /*resposta do reprocessamento*/
	int op, num /*número do funcionário a ser mudado*/;
	info info;
	no lista = NULL;
		
	do {
		printf("MENU INCIAL\n\n1- Admissão de funcionário novo\n2- Demissão de funcionário\n3- Mudança de departamento por parte do funcionário\n4- Relação dos funcionários de um departamento\n\nOpção: ");
		scanf(" %d", &op);
		switch (op){
			case 1:
				printf("\nNúmero, nível salarial, departamento: ");
				scanf(" %d %d %d", &info.numero, &info.salario, &info.departamento);
				novo_funcionario(&lista, info);
				mostra_lista(lista);
				break;
			case 2:
				//do...
				break;
			case 3:
				printf("\nNúmero do funcionário a ser mudado: ");
				scanf(" %d", &num);
				mudar_departamento(&lista, info, num);
				mostra_lista(lista);
				break;
			case 4:
				//do...
				break;
			default:
				printf("\nOpção inválida.");
				break;
		}
		do {
			printf("\n\nIr novamente? S/N");
			reproc = toupper(getch());
			system("cls");
		} while (reproc != 'S' && reproc != 'N');
	} while (reproc == 'S');
}
