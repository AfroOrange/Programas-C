#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    int contador = 0;
    printf("Comienza la ejecución\n");

    pid_t idHijo;
    pid_t idPadre;
    idPadre = getpid();  // Get the current process ID of the parent
    
    printf("Antes de bifurcar\n");
    idHijo = fork();
    contador ++;

    if (idHijo == 0) {  // Child process
        printf("Id hijo: %d Id padre: %d Contador: %d\n", getpid(), idPadre, contador);
    } else {  // Parent process
        printf("Id padre: %d Id hijo: %d Contador: %d\n", getpid(), idHijo, contador);
    }

    return 0;
}