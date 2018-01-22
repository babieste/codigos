#include <stdio.h>
#include <conio.h>
#include <math.h>
// 1 grau = 0.0174533 radianos
#define RAD 0.0174533;

int main () {
	int op;
	float ang, sec, cosec, cotg, aux;
	char opcao, resp = 'S';
	
	do {
		printf("Digite a operacao desejada:");
		printf("\n 1. Seno\n 2. Cosseno\n 3. Tangente\n 4. Cotangente\n 5. Secante\n 6. Cossecante\n");
		printf(" Escolha: ");
		scanf(" %d", &op);
		
		while (op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6) {
			printf("\nOpcao invalida! Tente novamente: ");
			scanf(" %d", &op);
		} 
		
		printf("Voce selecionou: %d\n", op);
			
			
		printf("Voce usara radianos ou graus? \"r\" para radianos e \"g\" para graus ");
		scanf("%c", &opcao);
		
		while (opcao != 'g' && opcao != 'r') {
			printf("Opcao invalida!\n\n");
			printf("Voce usara radianos ou graus? ");
			scanf("%s", &opcao);
		}
	 	
	 	if (opcao == 'r') {
	 		printf("Diga um angulo em radianos: ");
			scanf("%f", &ang);
			while (ang > 2*M_PI) {
				ang = ang - (2*M_PI);
			}
		 } 
		 else if (opcao == 'g') {
		 	printf("Diga um angulo em graus: ");
			scanf("%f", &ang);
			aux = ang;
			while (ang > 360) {
				ang = ang - 360;
			}
			//Transformação do ângulo de graus para radianos:
			ang = ang*RAD;
			printf("\nO angulo %f equivale a %f em radianos.\n\n", aux, ang);
			
		}
			//Fórmulas:
			sec = 1/cos(ang);
			cosec = 1/sin(ang);
			cotg = 1/tan(ang);
		
		switch (op) {
			case 1: printf("\n Seno: %f\n", sin(ang));
					printf("\n\n O arco seno do angulo de seno %f eh: %f\n", sin(ang), ang);
					break;
			case 2: printf("\n Cosseno: %f\n", cos(ang));
					printf("\n\n O arco cosseno do angulo de cosseno %f eh: %f\n", cos(ang), ang);
					break;
			case 3: if (aux == 90 || aux == 270) {
					printf("\n Nao existe tangente.");
					} 
					else  {
						printf("\n Tangente: %f", tan(ang));
						printf("\n\n O arco tangente do angulo de seno %f eh: %f", tan(ang), ang);
					}
					break;
			case 4: if (aux == 180 || aux == 0 || aux == 360) {
					printf("\n Nao existe cotangente.");
					}
					else {
						printf("\n Cotangente: %f", cotg);	
					}
					break;
			case 5: if (aux == 90 || aux == 270) {
					printf("\n Nao existe secante.");
					} 
					else {
						printf("\n Secante: %f", sec);	
					}
					break;
			case 6: if (aux == 180 || aux == 0 || aux == 360) {
					printf("\n Nao existe cossecante.");
					}
					else {
						printf("\n Cossecante: %f", cosec);
					}
					break;
		}
		
		
		do {
			printf("\n\nIr novamente? S/N \n\n");
			scanf("%c", &resp);
		} while (resp != 'N' && resp != 'S');
	} while (resp == 'S');
	
	getch();
}
