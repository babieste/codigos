// Barbara Este Fernandez - 31937039
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char firstName[MAX], secondName[MAX], aux[MAX];

    printf("Digite o primeiro nome: ");
    fgets(firstName, MAX, stdin);

    printf("\nDigite o segundo nome: ");
    fgets(secondName, MAX, stdin);

    // If strcmp returns > 0, secondName comes first
    if (strcmp(firstName, secondName) > 0) {
        strcpy(aux, firstName);
        strcpy(firstName, secondName);
        strcpy(secondName, aux);
    }

    printf("\nNomes:\n");
    printf("%s\n%s", firstName, secondName);

    return 0;
}