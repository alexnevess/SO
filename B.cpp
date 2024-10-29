//Chamada das bibliotecas
#include <stdio.h>
#include <windows.h>
#include <process.h>
//fun��o que imprime o ID do processo e o ID da thread no console
void print_process_info(void* param) {
    printf("Processo criado. PID: %u, PPID: %u\n", GetCurrentProcessId(), GetCurrentThreadId());
}

int main() {
    // Cria tr�s threads para simular os processos-filho chamando a fun��o print_process_info
    _beginthread(print_process_info, 0, NULL);
    _beginthread(print_process_info, 0, NULL);
    _beginthread(print_process_info, 0, NULL);

    // Chama a fun��o principal para o processo principal tamb�m
    print_process_info(NULL);

    // Pausa para garantir que todos os threads finalizem
    Sleep(1000);

����return�0;
}






