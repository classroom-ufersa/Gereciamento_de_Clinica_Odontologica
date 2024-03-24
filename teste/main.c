
#include<stdio.h>
#include<stdlib.h>
#include "paciente.c"
#include"consultorio.c"
           
  
int main() {
    ListaPaciente* lista_pacientes = NULL;
    ListaConsultorio* lista_consultorios = NULL;

    lista_pacientes = lista_cria_paciente();
    lista_consultorios = lista_cria_consultorios();

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Adicionar paciente\n");
        printf("2. Adicionar consultorio\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                
                break;
            }
            case 2: {
                
            }
            case 3: {
                
               
                return 0;
            }
            default: {
                printf("Opcao invalida. Tente novamente.\n");
                break;
            }
        }
    } while (opcao != 3);

    return 0;
}

           