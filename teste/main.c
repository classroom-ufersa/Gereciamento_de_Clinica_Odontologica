#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "consultorio.h"
#include "paciente.h"

int main() {
    struct Consultorio* lista_consultorios =NULL;
    struct Lista_geral* lista_geral = NULL;  
    struct Lista_atendidos* lista_atendidos = NULL;
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

        scanf("%c", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                Consultorio* novo_consultorio = (Consultorio*)malloc(sizeof(Consultorio));
                if (novo_consultorio == NULL) {
                    printf("Erro ao alocar memoria para o novo consultorio\n");
                    exit(1);
                }

                printf("Digite o ID do consultorio: ");
                scanf("%d", &novo_consultorio->identificacao);
                getchar();

                printf("Digite a especialidade desse consultorio: ");
                scanf(" %[^\n]", novo_consultorio->especialidade);
                getchar();

                printf("Digite os equipamentos que estao disponiveis nesse consultorio:\n");
                scanf(" %[^\n]", novo_consultorio->equipamentos_disponiveis);
                getchar();

                lista_consultorios = adicionar_consultorio(lista_consultorios);
                 salvar_consultorios_arquivo(lista_consultorios);
                break;
            }
            case 2: {
                remover_consultorio_por_id(lista_consultorios);
                break; 
            }
            case 3: {
                adicionar_paciente_por_id(lista_consultorios);
                break;
            }
            case 4: {
               //adicionar funcao de remover
                break;
            }
            case 5: {
                char nome_paciente[100];
                printf("Digite o nome do paciente que deseja editar: ");
                scanf(" %[^\n]", nome_paciente);

                Paciente* paciente_editado = editar_paciente(lista_consultorios, nome_paciente);
                if (paciente_editado != NULL) {
                    printf("Paciente editado com sucesso:\n");
                    printf("Nome: %s, Idade: %d, Situacao Saude: %s\n", paciente_editado->nome, paciente_editado->idade, paciente_editado->situacao_saude);
                } 
                break;
            }
            case 6: {
                char nome_paciente[500];
                printf("buscar por nome");
                printf("Digite o nome do paciente que deseja buscar: ");
                scanf(" %[^\n]", nome_paciente);

                Paciente* paciente_encontrado = buscar_paciente_por_nome(lista_consultorios, nome_paciente);
                if (paciente_encontrado != NULL) {
                    printf("Paciente encontrado:\n");
                    printf("Nome: %s, Idade: %d, Situacao Saude: %s\n", paciente_encontrado->nome, paciente_encontrado->idade, paciente_encontrado->situacao_saude);
                } else {
                    printf("Paciente nao encontrado no consultorio.\n");
                }
                break;
            }
            case 7: {
               imprimir_consultorios_Disponiveis(lista_consultorios);
                break;
            }
            case 8: {
                // Listar pacientes atendidos 
            
                break;
            }
            case 9: {
                
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
