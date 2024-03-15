#include <stdio.h>
#include <stdlib.h>
#include "paciente.c"

int main() {
    Paciente *pacientes = NULL;
    int quantidade_pacientes = 0;

    pacientes = (Paciente*)malloc(sizeof(Paciente));

    if (pacientes == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

Paciente *pacientes = NULL;
    int quantidade_pacientes = 0;
    char escolha;

    do {
        printf("\nMenu:\n");
        printf("1 - Adicionar paciente\n");
        printf("2 - Listar pacientes\n");
        printf("3 - Remover paciente\n");
        printf("4 - Editar paciente\n");
        printf("5 - Buscar paciente\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &escolha);

        switch (escolha) {
            case '1':
                pacientes = coletar_dados_paciente(pacientes, &quantidade_pacientes);
                break;
            case '2':
             
                break;
            case '3':
             
                break;
            case '4':
               
                break;
            case '5':
                
                break;
            case '6':
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (escolha != '6');
    free(pacientes);

    return 0;
}
