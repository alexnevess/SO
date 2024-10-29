#include <stdio.h>        // Importa a biblioteca padrão de entrada e saída
#include <windows.h>      // Importa a biblioteca para funções do Windows

void create_processes(int n); // Declara a função que cria processos

int main() {                // Função principal do programa
    int n = 4;             // Define quantos processos queremos criar
    create_processes(n);   // Chama a função para criar os processos
    return 0;              // Retorna 0, indicando que o programa terminou bem
}

// Função que cria processos
void create_processes(int n) {
    for (int i = 0; i < n; i++) { // Um loop que se repete n vezes
        PROCESS_INFORMATION processInfo; // Estrutura para guardar informações do processo criado
        STARTUPINFO startupInfo;         // Estrutura para informações sobre como iniciar o processo

        // Limpa as estruturas para evitar dados antigos
        ZeroMemory(&startupInfo, sizeof(startupInfo));
        startupInfo.cb = sizeof(startupInfo); // Diz o tamanho da estrutura
        ZeroMemory(&processInfo, sizeof(processInfo)); // Limpa a estrutura do processo

        // Tenta criar um novo processo
        if (CreateProcess(
                NULL,             // Executável (NULL significa usar um padrão, mas aqui vamos usar "notepad.exe")
                "notepad.exe",    // O que queremos executar (exemplo: abrir o bloco de notas)
                NULL,             // Atributos de segurança do processo
                NULL,             // Atributos de segurança do thread
                FALSE,            // Não herdar handles
                0,                // Flags de criação
                NULL,             // Usar o ambiente do processo pai
                NULL,             // Usar o diretório do processo pai
                &startupInfo,     // Informações sobre como iniciar
                &processInfo)) {  // Informações sobre o processo criado
            
            // Se o processo foi criado com sucesso, imprime o PID
            printf("Processo criado. PID: %d\n", processInfo.dwProcessId);
            
            // Fecha os handles do processo e do thread para evitar vazamentos
            CloseHandle(processInfo.hProcess);
            CloseHandle(processInfo.hThread);
        } else {
            // Se não conseguiu criar o processo, imprime um erro
            printf("Erro ao criar o processo: %d\n", GetLastError());
        }
    }
}


