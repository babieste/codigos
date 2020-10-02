#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

FILE *file;

int vector_length = 65536;
int vetor[65537];

int posicao = -1;

void thread_busca(int num) {
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
    int local_i, local_f;
    int i;

    local_i = (vector_length/thread_count)*my_rank;
    local_f = ((vector_length/thread_count)*(my_rank+1))-1;

    // printf("[Thread %d] Vector length: %d, i: %d, f: %d\n", my_rank, vector_length, local_i, local_f);

    for (i = local_i; i <= local_f; i++) {
        if (vetor[i] == num) {
            posicao = i;
        }
    }
}

int main(int argc, char *argv[]) {
    int thread_count = strtol(argv[1], NULL, 10);
    int num = strtol(argv[2], NULL, 10);
    int i = 0;
    char *numRead;

    if ((file = fopen("vetor1.txt", "r")) == NULL) {
        printf("Couldn\'t read from file.\n");
        return 1;
    }

    while(!feof(file)) {
        fscanf(file, "%d", &vetor[i]);
        i++;
    }

    #pragma omp parallel num_threads(thread_count)
    thread_busca(num);

    if (posicao == -1) {
        printf("Couldn\'t find number on array.\n");
    } else {
        printf("%d was found at index %d.\n", num, posicao);
    }

    return 0;
}
