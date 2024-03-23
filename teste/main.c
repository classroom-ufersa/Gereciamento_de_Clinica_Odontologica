/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.c"
#include "consultorio.c"

int main() {
    struct Listapaciente* lista_pacientes = NULL;
    struct Listaconsultorio* lista_consultorios = lista_cria_consultorios();

  char opcao;
    do {
        
        printf("Bem vindo ao Menu da Clinica!\n");
        printf("Escolha uma das opcoes a seguir:\n");
        printf("1-Adicionar consultorio\n");
        printf("2-Remover consultorio\n");
        printf("3-Adicionar paciente\n");
        printf("4-Remover paciente\n");
        printf("5-Editar informacoes de paciente\n");
        printf("6-Buscar paciente por nome\n");
        printf("7-Listar consultorios e pacientes atendidos\n");
        printf("8-Sair\n");
        scanf("%c", &opcao);

      
        switch (opcao) {
    case 1:
        struct Listaconsultorio* lista_consultorios = lista_cria_consultorios();

    
    struct Consultorio* novo_consultorio = coletar_dados_consultorio();
    lista_consultorios = adicionar_consultorio(novo_consultorio, lista_consultorios);

        break;
    case 2:
        printf("socorro");
        break;
    case 3:
      
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    case 6:
        
        break;
    case 7:
       
        break;
    case 8:
        printf("Saindo...\n");
        break;
    default:
        printf("Opcao invalida. Tente novamente.\n");
        break;
}
} while (opcao!=8);
  return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
#include "paciente.c"
#include"consultorio.c"
           
  
int main() {
    Listapaciente* lista_pacientes = NULL;
    Listaconsultorio* lista_consultorios = NULL;

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
                struct Paciente *novo_paciente = (struct Paciente*)malloc(sizeof(struct Paciente));
                printf("Digite o nome do paciente: ");
                scanf(" %[^\n]", novo_paciente->nome);
                printf("Digite a idade do paciente: ");
                scanf(" %d", &novo_paciente->idade);
                printf("Digite a doenca do paciente: ");
                scanf(" %[^\n]", novo_paciente->situacao_saude);
                lista_pacientes = addPaciente(novo_paciente, lista_pacientes);
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

           