#include <stdio.h>        // Importa a biblioteca padr�o de entrada e sa�da
#include <windows.h>      // Importa a biblioteca para fun��es do Windows

void create_processes(int n); // Declara a fun��o que cria processos

int main() {                // Fun��o principal do programa
    int n = 4;             // Define quantos processos queremos criar
    create_processes(n);   // Chama a fun��o para criar os processos
    return 0;              // Retorna 0, indicando que o programa terminou bem
}

// Fun��o que cria processos
void create_processes(int n) {
    for (int i = 0; i < n; i++) { // Um loop que se repete n vezes
        PROCESS_INFORMATION processInfo; // Estrutura para guardar informa��es do processo criado
        STARTUPINFO startupInfo;         // Estrutura para informa��es sobre como iniciar o processo

        // Limpa as estruturas para evitar dados antigos
        ZeroMemory(&startupInfo, sizeof(startupInfo));
        startupInfo.cb = sizeof(startupInfo); // Diz o tamanho da estrutura
        ZeroMemory(&processInfo, sizeof(processInfo)); // Limpa a estrutura do processo

        // Tenta criar um novo processo
        if (CreateProcess(
                NULL,             // Execut�vel (NULL significa usar um padr�o, mas aqui vamos usar "notepad.exe")
                "notepad.exe",    // O que queremos executar (exemplo: abrir o bloco de notas)
                NULL,             // Atributos de seguran�a do processo
                NULL,             // Atributos de seguran�a do thread
                FALSE,            // N�o herdar handles
                0,                // Flags de cria��o
                NULL,             // Usar o ambiente do processo pai
                NULL,             // Usar o diret�rio do processo pai
                &startupInfo,     // Informa��es sobre como iniciar
                &processInfo)) {  // Informa��es sobre o processo criado
            
            // Se o processo foi criado com sucesso, imprime o PID
            printf("Processo criado. PID: %d\n", processInfo.dwProcessId);
            
            // Fecha os handles do processo e do thread para evitar vazamentos
            CloseHandle(processInfo.hProcess);
            CloseHandle(processInfo.hThread);
        } else {
            // Se n�o conseguiu criar o processo, imprime um erro
            printf("Erro ao criar o processo: %d\n", GetLastError());
        }
    }
}


