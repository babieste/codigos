#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Escreva um programa que leia um arquivo texto com o nome, a idade e a altura de um conjunto de pessoa.
// Coloque os dados em um vetor de Structs e ordene o vetor por altura. No final, gere um novo arquivo com os dados ordenados.
// Para ordenar o vetor de structs, utiliza a função qsort da biblioteca cstdlib.

typedef struct {
    char nome[100];
    int idade;
    float altura;
} Pessoa;

int leDados(FILE *arquivo, Pessoa pessoas[100]) {
    char str[100];
    int index = 0;

    fseek(arquivo, 0, SEEK_SET);
    while(feof(arquivo) == 0) {
        fgets(str, 100, arquivo);
        strcpy(pessoas[index].nome, str);

        fgets(str, 100, arquivo);
        pessoas[index].idade = (int) atoi(str);

        fgets(str, 100, arquivo);
        pessoas[index].altura = (float) atof(str);

        printf("Nome: %sIdade: %d\nAltura: %f\n\n", pessoas[index].nome, pessoas[index].idade, pessoas[index].altura);
        index++;
    }

    return index;
}

int comparaDados(const void *a, const void *b) {
    float alturaA = ((Pessoa *)a)->altura;
    float alturaB = ((Pessoa *)b)->altura;

    if (alturaA < alturaB) return -1;
    if (alturaA > alturaB) return 1;
    return 0;
}

void imprimePessoas(Pessoa pessoas[100], int index) {
    int i = 0;

    for (i = 0; i < index; i++) {
        printf("Nome: %sIdade: %d\nAltura: %f\n\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].altura);
    }
}

int main() {
    FILE *arquivo;
    Pessoa pessoas[100], p;
    int quantidadePessoas = 0;

    if ((arquivo = fopen("atividade_04_09_2020.txt", "r")) == NULL) {
        printf("Erro ao abrir arquivo para leitura!");
        return 1;
    }

    quantidadePessoas = leDados(arquivo, pessoas);

    qsort(pessoas, quantidadePessoas, sizeof(p), comparaDados);

    printf("Pessoas ordenadas por altura:\n");
    imprimePessoas(pessoas, quantidadePessoas);

    fclose(arquivo);
    return 0;
}