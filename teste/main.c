#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "consultorio.h"
#include "paciente.h"

int main() {
    Consultorio* lista_consultorios =NULL; 
    Lista_Atendidos* lista_atendidos = NULL;
    Paciente*lista_paciente=NULL;
    Lista_geral*lista_geral=NULL;
    char opcao;

    ler_arquivo_e_inserir_lista(&lista_consultorios,&lista_paciente);

    
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
        printf("9- Adicionar pacientes geral\n");
        printf("0- Sair\n");

        scanf(" %c", &opcao);
    
        switch (opcao) {
            case '1': {
                lista_consultorios = adicionar_consultorio(lista_consultorios);
                salvar_consultorios_e_pacientes_em_arquivo(lista_consultorios);
                break;
            }
            case '2': {
                lista_consultorios= remover_consultorio_por_id(lista_consultorios);
                
                break; 
            }
            case '3': {
                adicionar_paciente_por_id(lista_consultorios,&lista_geral);
                salvar_consultorios_e_pacientes_em_arquivo(lista_consultorios);
                break;
            }
            case '4': {
                remover_paciente_por_fila(&lista_geral,&lista_atendidos);
                break;
            }
            case '5': {
                char nome_editar[500];
                char dg_string[100];
                int digito_unico;
                printf("Digite o nome do paciente que deseja editar:\n");
                scanf(" %[^\n]", nome_editar);
                tratamento_de_palavras(nome_editar);
                string_maiuscula_minuscula(nome_editar);
                printf("Agora insira o digito unico desse paciente:\n");
                scanf(" %[^\n]", dg_string);
                tratamento_de_numero(dg_string);
                digito_unico=atoi(dg_string);

                editar_paciente(lista_consultorios, nome_editar,digito_unico);
                break;
            }
                case '6': {
                char nome_buscar[500];
                char dg_string[100];
                int digito_unico;
                printf("Digite o nome do paciente que deseja buscar:\n");
                scanf(" %[^\n]", nome_buscar);
                tratamento_de_palavras(nome_buscar);
                string_maiuscula_minuscula(nome_buscar);
                printf("Agora insira o digito unico desse paciente:\n");
                scanf(" %[^\n]", dg_string);
                tratamento_de_numero(dg_string);
                digito_unico=atoi(dg_string);
                lista_paciente = buscar_paciente_por_nome(lista_consultorios, nome_buscar, digito_unico);
                }
            case '7': {
                imprimir_consultorios_Disponiveis(lista_consultorios);
                break;
            }
            case '8': {
                imprimir_gerais(lista_geral);
                imprimir_atendidos(lista_atendidos);
                arquivo_atendidos(lista_atendidos);
                break;
            }
            case '9': {
                printf("Saindo....\n");
                break;
            }
        
            default: {
                printf("Opção invalida. Tente novamente. \n");
                break;
            }
        }

    } while (opcao != '9');
  
  
    free(lista_consultorios);
    free(lista_atendidos);
    free(lista_paciente);
    free(lista_geral);
    return 0;
}