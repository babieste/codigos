// Barbara Este Fernandez - 31937039
#include <stdio.h>

char averageFormula(float n1, float n2, float n3, float ex) {
    float average = (n1 + n2*2 + n3*3 + ex)/7;

    if (average >= 9) {
        return 'A';
    } else if (average >= 7.5 && average < 9) {
        return 'B';
    } else if (average >= 6 && average < 7.5) {
        return 'C';
    } else if (average >= 4 && average < 6) {
        return 'D';
    } else {
        return 'E';
    }
}

int main() {
    float nota1 = 7.5, nota2 = 6.3, nota3 = 9.8, ex = 0.5;
    char result;

    result = averageFormula(nota1, nota2, nota3, ex);
    printf("Nota do aluno: %c", result);
    return 0;
}