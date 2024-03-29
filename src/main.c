#include <stdio.h>
#include <stdlib.h>
#include "paciente.c"
#include "consultorio.c"

int main() {
    Consultorio* lista_consultorios =NULL; 
    Lista_Atendidos* lista_atendidos = NULL;
    Paciente*lista_paciente=NULL;
    Lista_geral*lista_geral=NULL;
    
    char opcao;    
    do{
        printf("========= CHAR OF SMILE CLINICA ==========\n");
        printf("Seja bem vindo! Segue o menu da cllinica: \n");
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
        printf("===========================================\n");

        scanf(" %c", &opcao);
         //salvar_consultorios_em_arquivo(lista_consultorios);
        
        switch (opcao) {
            case '1': {
                lista_consultorios = adicionar_consultorio(lista_consultorios);
                salvar_consultorios_em_arquivo(lista_consultorios);
                break;
            }
            case '2': {
                lista_consultorios= remover_consultorio_por_id(lista_consultorios);
                break; 
            }
            case '3': {
                adicionar_paciente_por_id(lista_consultorios);
                salvar_consultorios_em_arquivo(lista_consultorios);
                break;
            }
            case '4': {
                remover_paciente_por_fila(&lista_geral,&lista_atendidos);
                //limpar buffer
                break;
            }
            case '5': {
                char nome_editar[500];
                printf("Digite o nome do paciente que deseja editar:\n");
                scanf(" %[^\n]", nome_editar);
                tratamento_de_palavras(nome_editar);
                string_maiuscula_minuscula(nome_editar);
                lista_consultorios= editar_paciente(lista_consultorios, nome_editar);
                break;
            }
            case '6': {
                char nome_paciente_buscar[500];
                printf("Digite o nome do paciente que deseja buscar:\n");
                scanf(" %[^\n]", nome_paciente_buscar);
                tratamento_de_palavras(nome_paciente_buscar);
                string_maiuscula_minuscula(nome_paciente_buscar);
                lista_consultorios = buscar_paciente_por_nome(lista_consultorios, nome_paciente_buscar);
            }
            case '7': {
                imprimir_consultorios_Disponiveis(lista_consultorios);
                break;
            }
            case '8': {
                imprimir_atendidos(lista_atendidos);
                break;
            }
            case '9': {
                printf("teste 02\n");
                lista_geral=adicionar_paciente_geral(lista_geral);
                printf("teste01\n");
                break;
            }
            case '0':{
                break;
            }
            default: {
                printf("Opção invalida! Tente novamente. \n");
                break;
            }
        }
    } 
    while (opcao != '0');

    /*Liberar memoria*/
    free(lista_consultorios);
    free(lista_atendidos);
    free(lista_paciente);
    free(lista_geral);
    
    salvar_consultorios_em_arquivo(lista_consultorios);
    return 0;
}
