#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int calcularSumatorio(int n) {
    int sumatorio = 0;
    for (int i = 1; i <= n; i++) {
        sumatorio += i;
    }
    return sumatorio;
}

int calcularFactorial(int n) {
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;  // Fix: Multiply by `i`, not `1`
    }
    return factorial;
}

int main() {
    int n;

    printf("Introduce un número entero: ");
    scanf("%d", &n);  // Fix: Change period to comma in scanf

    pid_t pid1 = fork();

    if (pid1 == 0) {  // First child
        int sumatorio = calcularSumatorio(n);
        printf("Hijo 1..... (PID %d): Sumatorio = %d\n", getpid(), sumatorio);
        exit(0);

    } else if (pid1 < 0) {  // Fork failed
        perror("Error al crear primer hijo");
        exit(1);
    }

    pid_t pid2 = fork();

    if (pid2 == 0) {  // Second child
        int factorial = calcularFactorial(n);
        sleep(5);  // Shortened sleep time for demonstration purposes
        printf("Hijo 2....... (PID %d): Factorial = %d\n", getpid(), factorial);
        exit(0);

    } else if (pid2 < 0) {  // Fix: Added condition for second fork failure
        perror("Error al crear el segundo hijo");
        exit(1);
    }

    int status;
    waitpid(pid1, &status, 0);  // Fix: Added missing semicolon
    waitpid(pid2, &status, 0);  // Fix: Added missing semicolon

    printf("Adiós!\n");

    return 0;
}
