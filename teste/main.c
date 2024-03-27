#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "consultorio.h"
#include "paciente.h"

int main() {
    struct Consultorio* lista_consultorios =NULL;
    struct Lista_geral* lista_geral = NULL;  
    struct Lista_atendidos* lista_atendidos = NULL;
    struct Paciente*lista_paciente=NULL;
    char opcao;

    do {
        printf("Bem vindo ao Menu da Clinica!\n");
        printf("Escolha uma das opcoes a seguir:\n");
        printf("1-Adicionar consultorio\n");
        printf("2-Remover consultorio \n");
        printf("3-Adicionar paciente\n");
        printf("4-Remover paciente\n");
        printf("5-Editar informacoes de paciente\n");
        printf("6-Buscar paciente por nome\n");
        printf("7-Listar consultorios \n");
        printf("8-Listar pacientes atendidos\n");
        printf("9- Sair\n ");

        scanf(" %c", &opcao);
      

        switch (opcao) {
            case '1': {
                lista_consultorios = adicionar_consultorio(lista_consultorios);
                 salvar_consultorios_em_arquivo(lista_consultorios);
                break;
            }
            case '2': {
                remover_consultorio_por_id(&lista_consultorios);
                break; 
            }
            case '3': {
           
                 adicionar_paciente_por_id(lista_consultorios);
                   salvar_consultorios_em_arquivo(lista_consultorios);


                break;
            }
            case '4': {
               //adicionar funcao de remover
                break;
            }
            case 5: {
                //funcao de editar
            }
            case '6': {
                char nome_paciente_buscar[500];
                 printf("Digite o nome do paciente que deseja buscar: ");
                  scanf(" %[^\n]", nome_paciente_buscar);

               Consultorio* paciente_encontrado = buscar_paciente_por_nome(lista_consultorios, nome_paciente_buscar);
                
                }
            case '7': {
               imprimir_consultorios_Disponiveis(lista_consultorios);
                break;
            }
            case '8': {
                // Listar pacientes atendidos 
            
                break;
            }
            case '9': {
                //add pacientes  a lista gerap
                break;
            }
            default: {
                printf("Opção invalida. Tente novamente. \n");
                break;
            }
        }

    } while (opcao != 9);

    return 0;
}
