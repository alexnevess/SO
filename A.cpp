/*Código da questão 'A' foi compilado em Linux usando o compilador online https://www.onlinegdb.com/online_c_compiler. Devido à sua natureza, 
o código se tornaria muito complexo para ser convertido para Windows.
*/

#include <sys/types.h>   // Inclui definições de tipos de dados do sistema
#include <stdio.h>       // Inclui funções de entrada e saída
#include <unistd.h>      // Inclui a API do sistema operacional POSIX, que contém a função fork()
#include <sys/wait.h>    // Inclui a função wait() para espera de processos filhos

int value = 5;           // Declara uma variável global e inicializa com o valor 5

int main() {
    pid_t pid;          // Declara uma variável do tipo pid_t para armazenar o identificador do processo

    pid = fork();       // Cria um novo processo (processo filho); retorna 0 para o filho e o PID do filho para o pai

    if (pid == 0) 
    {     // Verifica se estamos no processo filho
        value += 15;    // O processo filho incrementa o valor de 'value' em 15
        return 0;       // O processo filho termina
    } else if (pid > 0) 
    { // Verifica se estamos no processo pai
        wait(NULL);     // O processo pai espera até que o filho termine
        printf("PARENT: value = %d\n", value); // O pai imprime o valor de 'value' (ainda 5)
        return 0;       // O processo pai termina
    } else {            // Verifica se houve falha na criação do processo
        fprintf(stderr, "Fork falhou.\n"); // Imprime uma mensagem de erro se fork() falhar
        return 1;       // Retorna 1 para indicar erro
    }
}
