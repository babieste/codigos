#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
monteCarloPi(n)
|   acertos ← 0
|   para i ← 0 até n
|   |   x ← sorteie um número real entre 0 e 1
|   |   y ← sorteie um número real entre 0 e 1
|   |   se(x * x + y * y < 1)
|   |   |   acertos ← acertos + 1
|   |   fim_se
|   fim_para
|   retorne 4 * acertos / n
fim_monteCarloPi
*/

int main() {
    srand(time(NULL));
    int comm_sz; /* number of processes */
    int proc_rank; /* process rank */

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &proc_rank);

    int n = 100000; /* number of sorts */
    int local_n = n / comm_sz;/* number of sorts within each process */
    int hits; /* number of hists of points inside circle area */
    int local_hits = 0; /* number of local hits from each process */

    /* broadcast to all processes how many sorts we want */
    if (proc_rank == 0) {
        printf("\nBroadicasting %d sorts to each process from process %d...\n", local_n, proc_rank);
        /* MPI_Bcast(void* data, int count, MPI_Datatype datatype, int root, MPI_Comm communicator) */
        MPI_Bcast(&local_n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }
    
    printf("\nProcess %d received %d sorts to make.\n", proc_rank, local_n);
    int i;

    /* calculate local number of hits */
    for (i = 0; i < local_n; i++) {
        /* generate random x and y between 1 and 0 */
        double x = rand() / (double) RAND_MAX;
        double y = rand() / (double) RAND_MAX;

        /* if (x, y) is inside circle, it's a hit */
        if (((x*x) + (y*y)) < 1) {
            local_hits++;
        }
    }

    printf("\nProcess %d made %d hits!\n", proc_rank, local_hits);

    /* sum all local_hits to global hits count */
    if (comm_sz == 1) {
        hits = local_hits;
    } else {
        printf("\nReducing %d local hits from process %d...\n", local_hits, proc_rank);
        /* MPI_Reduce(void* send_data, void* recv_data, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm communicator) */
        MPI_Reduce(&local_hits, &hits, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    }

    if (proc_rank == 0) {
        printf("\nProcess %d received %d as the total number of hits. Calculating PI...\n", proc_rank, hits);
        double pi = (4.0 * (double) hits) / (double) n;
        printf("\nPI = %.10f\n", pi);
    }

    MPI_Finalize();

    return 0;
}
