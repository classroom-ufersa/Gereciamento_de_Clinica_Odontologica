#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/consultorio.h"
#include "../include/paciente.h"
#include "../include/funcoes.h"

int main() {
    Consultorio* lista_consultorios =NULL; 
    Lista_Atendidos* lista_atendidos = NULL;
    Paciente*lista_paciente=NULL;
    Lista_geral*lista_geral=NULL;
    char opcao;

    ler_arquivo_e_inserir_lista(&lista_consultorios,&lista_paciente);
   do
   {
    do {
        menu();
    printf("Escolha uma opcao acima: ");
    if (scanf(" %c", &opcao) != 1 || (opcao < '1' || opcao > '9')) {
        printf("Opcao invalida. Por favor, escolha uma opcao de 1 a 9.\n");
        limpar_buffer();
        opcao = '0';
    }
} while(opcao < '1' || opcao > '9');

    
        switch (opcao) {
            case '1': {
                lista_consultorios = adicionar_consultorio(lista_consultorios);
                salvar_consultorios_e_pacientes_em_arquivo(lista_consultorios);
                limpar_buffer();
                break;
            }
            case '2': {
                lista_consultorios= remover_consultorio_por_id(lista_consultorios);
                salvar_consultorios_e_pacientes_em_arquivo(lista_consultorios);
                limpar_buffer();
                break; 
            }
            case '3': {
                adicionar_paciente_por_id(lista_consultorios,&lista_geral);
                salvar_consultorios_e_pacientes_em_arquivo(lista_consultorios);
                limpar_buffer();
                break;
            }
            case '4': {
                 char escolha;
                     do {
                    printf("Deseja remover do banco de dados[0] ou da lista geral do dia[1]?\n");
                    scanf(" %c", &escolha);
                     } while (escolha != '0' && escolha != '1');

                    if (escolha == '0') {
                    char nome[200];
                     int dg;
                    printf("Digite o nome do paciente que deseja remover:\n");
                     scanf(" %[^\n]", nome);
                    tratamento_de_palavras(nome);
                    string_maiuscula_minuscula(nome);
                    remover_paciente_para_inserir(lista_consultorios, nome, dg);
                     }   
                    if (escolha == '1') {
                    remover_paciente_por_fila(&lista_geral, &lista_atendidos);
                    arquivo_atendidos(lista_atendidos);
                            }
                  limpar_buffer();
                     break;
                        }

            
            case '5': {
                char nome_editar[500];
                char dg_string[100];
                int digito_unico;
                do
                {

                printf("Digite o nome do paciente que deseja editar:\n");
                scanf(" %[^\n]", nome_editar);
                tratamento_de_palavras(nome_editar);
                string_maiuscula_minuscula(nome_editar);
                }while (nome_editar[0]==0);
            

                do{
                printf("Agora insira o digito unico desse paciente:\n");
                scanf(" %[^\n]", dg_string);
                tratamento_de_numero(dg_string);
                digito_unico=atoi(dg_string);
                }while(digito_unico==0);
                editar_paciente(lista_consultorios, nome_editar,digito_unico);
                salvar_consultorios_e_pacientes_em_arquivo(lista_consultorios);
                limpar_buffer();
                break;
            }
            case '6': {
                char nome_buscar[500];
                char dg_string[100];
                int digito_unico;
                do
                {
                printf("Digite o nome do paciente que deseja buscar:\n");
                scanf(" %[^\n]", nome_buscar);
                tratamento_de_palavras(nome_buscar);
                string_maiuscula_minuscula(nome_buscar);
                }while (nome_buscar[0]==0);
                do{
                printf("Agora insira o digito unico desse paciente:\n");
                scanf(" %[^\n]", dg_string);
                tratamento_de_numero(dg_string);
                digito_unico=atoi(dg_string);
                }while (digito_unico==0);
                lista_paciente = buscar_paciente_por_nome(lista_consultorios, nome_buscar, digito_unico);
                limpar_buffer();
                break;
            }
            case '7': {
                imprimir_consultorios_Disponiveis(lista_consultorios,lista_paciente);
                limpar_buffer();
                break;
            }
            case '8': {
                imprimir_gerais(lista_geral);
                imprimir_atendidos(lista_atendidos);
                arquivo_atendidos(lista_atendidos);
                limpar_buffer();
                break;
            }
            case '9': {
                printf("======....Saindo do sistema....======\n");
                break;
            }
    
            default: {
               printf("Opcao invalida. Tente novamente. \n");
                break;
            
            }
        }
}while(opcao!= '9');
   
    
    //Liberar memoria
    liberar_listas(lista_consultorios);
   liberar_atendidos_lista(lista_atendidos);
   liberar_lista_geral(lista_geral);
    return 0;
}
