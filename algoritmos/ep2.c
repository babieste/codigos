//Barbara Este Fernandez - 31937039
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 100

typedef struct node {
	char character;
	int counter;
	struct node* next;
} node;

void printProgResult(node* node) {
	printf("\n");
	while(node != NULL) {
		if(node->next == NULL) printf("%c%d", node->character, node->counter);
		else printf("%c%d-", node->character, node->counter);
		node = node->next;
	}
}

void printDesprogResult(node* node) {
	printf("\n");
	while(node != NULL) {
		if(node->counter == -1) printf("%c", node->character);
		else printf("%c%d-", node->character, node->counter);
		node = node->next;
	}
}

void prog(char *buffer, char* prog_result) {
	int count = 0, i = 0, j = 0, input_size = strlen(buffer);
	node* char_list = malloc(sizeof(node));
	node* head = malloc(sizeof(node));
	
	char_list->next = NULL;
	
	//salva em head ponteiro para o inicio da lista
	head = char_list;
	
	for(i; i < input_size; i++) {
		char_list->character = buffer[i];
		char_list->counter = ++count;
		if((buffer[i] != buffer[i+1]) && (buffer[i+1] != '\0')) {
			//se nao for igual, entao temos uma outra letra
			//para contar repeticoes. Adiciona-se entao outro
			//no a lista
			char_list->next = malloc(sizeof(node));
			char_list = char_list->next;
			char_list->next = NULL;
			
			//reiniciamos o contador
			count = 0;
		}
	}
	
	//escrevemos em prog_result o resultado de prog no formato: aX-bY-cZ
	while(head != NULL) {
		if(head->next != NULL) {
			prog_result[j] = head->character; j++;
			prog_result[j] = head->counter + '0'; j++;
			prog_result[j] = '-'; j++;
		} else {
			prog_result[j] = head->character; j++;
			prog_result[j] = head->counter + '0'; j++;
		}
		head = head->next;
	}
}

void desprog(char* buffer, char* desprog_result) {
	int i = 0, k = 0, counter = 0, input_size = strlen(buffer);
	node* char_string = malloc(sizeof(node));
	node* head = malloc(sizeof(node));
	node* head_aux = malloc(sizeof(node));
	char aux[BUFFER_SIZE], counter_conversion[BUFFER_SIZE], buffer_conversion[BUFFER_SIZE];
	
	char_string->next = NULL;
	head = char_string;
	head_aux = char_string;
	
	for(i; i < input_size; i++) {
		if(buffer[i] != '-') {
			if(isdigit(buffer[i]) > 0) {
				//se buffer[i] e um numero, entao eh a quantidade
				//de vezes que a string devera ser repetida
				
				//para obter a contagem correta, eh necessario
				//transformar o contador em char para concatenar
				//com o proximo digito (se houver)
				if(counter == 0) {
					counter += buffer[i] - '0';
				} else {
					//counter_conversion tem a versao string de counter
					itoa(counter, counter_conversion, 10);
					
					//transformar pointer para char em string
					memcpy(buffer_conversion, &buffer[i], 1);
					buffer_conversion[1] = '\0';
					
					//concatena a versao string de buffer em counter_conversion
					strcat(counter_conversion, buffer_conversion);
					
					//transforma counter_conversion novamente em inteiro
					counter = atoi(counter_conversion);
				}
				
				//se chegamos ao final da string ou se o proximo caracter a
				//ser lido nao e um numero (vulgo '-') entao salvamos o contador
				//para aquela char_string
				if((i == input_size-1) || ((buffer[i+1]) == '-')) {
					char_string->counter = counter;
					
					if(buffer[i+1] == '-') {
						char_string->next = malloc(sizeof(node));
						char_string = char_string->next;
						char_string->next = NULL;
					}
				}
			} else {
				//se buffer[i] nao for um numero e nao e '-', entao
				//e o caracter a ser repetido
				char_string->character = buffer[i];
				
				//se o proximo caracter a ser lido tbm nao for um
				//numero, entao e continuacao da string que sera
				//repetida, portanto, para o caracter atual
				//sinalizamos que seu contador e -1 para indicar
				//que a string nao terminou
				if(isdigit(buffer[i+1]) == 0) {
					char_string->counter = -1;
					
					char_string->next = malloc(sizeof(node));
					char_string = char_string->next;
					char_string->next = NULL;
				}
			}
		} else {
			//quando o buffer chega em '-' ou no seu fim reiniciamos o
			//contador para a proxima sequencia de palavras
			counter = 0;
		}
	}
	memset(desprog_result, 0, sizeof(desprog_result));
	//transformamos entao a lista em string
	while(head_aux != NULL) {
		aux[k] = head_aux->character; k++;
		if(head_aux->counter != -1) {
			for(k = 0; k < head_aux->counter; k++) {
				strcat(desprog_result, aux);
			}
			k = 0;
		}
		head_aux = head_aux->next;
	}
}


int main() {
	char buffer[BUFFER_SIZE], prog_result[BUFFER_SIZE], desprog_result[BUFFER_SIZE];
	node* char_list = malloc(sizeof(node));
	
	printf("Entrada para prog = ");
	gets(buffer);
 
	prog(buffer, prog_result);
	printf("\nprog \"%s\"", prog_result);
	
	printf("\nEntrada para desprog = ");
	gets(buffer);

	desprog(buffer, desprog_result);
	printf("\ndesprog \"%s\"", desprog_result);
	
}
