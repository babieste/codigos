// Barbara Este Fernandez - 31937039

// Crie um codigo-fonte que utilize fork() e shmget() entre 2 processos (pai e filho). Seu codigo deve garantir que:

// 1. O processo pai e o processo filho compartilhem uma variavel simples (por exemplo, inteiro - valor 1)
// 2. O processo pai imprime o valor inicial dessa variavel; em seguida, cria o processo filho e espera-o
// 3. O processo filho acessa esta variavel, realiza uma operacao (por exemplo, adicao - valor 2, totalizando 3),
//    modificando o valor; em seguida, o processo filho termina
// 4. O processo pai realiza uma outra operacao (por exemplo, multiplicacao - valor 4, totalizando 12),
//    modificando novamente o valor, e imprime novamente a variavel

#include <stdio.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>

void childProcess(int *shm_ptr) {
    printf("child process started\n");
    *shm_ptr = *shm_ptr + 2;
    printf("child process has filled %d in shared memory\n", *shm_ptr);
    printf("child process is about to exit\n\n");
}

int main() {
    int shm_id;
    int *shm_ptr;

    shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shm_id < 0) {
        printf("*** shmget error (server) ***\n");
        return 1;
    }
    printf("server has received a shared memory of a integer\n");

    shm_ptr = (int *) shmat(shm_id, NULL, 0);
    if ((int) shm_ptr == -1) {
        printf("*** shmat error (server) ***\n");
        return 1;
    }
    printf("server has attached the shared memory\n");

    *shm_ptr = 1;
    printf("server has filled %d in shared memory\n", *shm_ptr);

    pid_t pid;
    int status;

    printf("server is about to fork a child process\n\n");
    pid = fork();
    if (pid < 0) {
        printf("*** fork error (server) ***\n");
        return 1;
    } else if (pid == 0) {
        childProcess(shm_ptr);
        return 0;
    }

    wait(&status);
    printf("server has detected the completion of its child...\n");

    *shm_ptr = *shm_ptr * 4;
    printf("server has filled %d in shared memory\n", *shm_ptr);

    shmdt((void *) shm_ptr);
    printf("server has detached its shared memory...\n");

    shmctl(shm_id, IPC_RMID, NULL);
    printf("server has removed its shared memory...\n");

    printf("server exits\n");
    return 0;
}
