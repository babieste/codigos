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
		printf("\nNúmero: %d\tNível Salarial: %d\tDepartamento: %d", p->numero, p->salario, p->departamento);
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

//Não funfa
int demitir_funcionario(no *lista, int num){
	no p = *lista;
	
	if(p->numero == num) {
		*lista = p->prox;
		free(p);
		return 1;
	}
	else{
		no q;
		while(p){
			q = p;
			p = p->prox;
			if(p->numero == num){
				q->prox = p->prox;
				free(p);
				return 1;
			}
			printf("\nNão existe funcionário com esse número.");
			return 0;
		}
	}
		
		
}

void relacao_departamento(no lista, int departamento){
	no p = lista;
	
	while(p){
		if(p->departamento == departamento)
			printf("\nNúmero: %d\tNível Salarial: %d\tDepartamento: %d", p->numero, p->salario, p->departamento);
		p = p->prox;
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	char reproc; /*resposta do reprocessamento*/
	int op, num /*número do funcionário a ser mudado ou demitido*/, departamento /*departamento escolhido*/;
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
				printf("\nNúmero do funcionário a ser demitido: ");
				scanf(" %d", &num);
				demitir_funcionario(&lista, num);
				mostra_lista(lista);
				break;
			case 3:
				printf("\nNúmero do funcionário a ser mudado: ");
				scanf(" %d", &num);
				mudar_departamento(&lista, info, num);
				mostra_lista(lista);
				break;
			case 4:
				do {
					printf("\nDigite o departamento: ");
					scanf(" %d", &departamento);
				} while (departamento < 1 && departamento > 3);
				relacao_departamento(lista, departamento);
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
