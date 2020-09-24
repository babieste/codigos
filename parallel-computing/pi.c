#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count = 2, n = 100000000;
double sum = 0.0;

void *thread_sum(void* rank) {
    long my_rank = (long) rank;
    double factor;
    

    long long i;
    long long my_n = n/thread_count;
    long long my_first_i = my_n*my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0) /* my_first_i is even */
        factor = 1.0;
    else
        factor = -1.0;

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        sum += factor/(2*i + 1);
    }

    return NULL;
}

int main() {
    long thread;
    double pi;
    pthread_t *thread_handles;

    thread_handles = malloc(thread_count*sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++)
        pthread_create(&thread_handles[thread], NULL, thread_sum, (void *) thread);

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    // double factor = 1.0, pi;
    // int i;

    // for (i = 0; i < n; i++, factor = -factor) {
    //     sum += factor/(2*i + 1);
    // }

    pi = 4.0 * sum;

    printf("\n Value of pi: %lf", pi);

    free(thread_handles);
    return 0;
}