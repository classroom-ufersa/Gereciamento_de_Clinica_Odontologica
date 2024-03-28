#include <stdio.h>
#include <stdlib.h>
#include "consultorio.h"
#include"paciente.h"



void salvar_consultorios_em_arquivo(Consultorio* lista_consultorios) {
    FILE* arquivo;
    Consultorio* atual = lista_consultorios;

    arquivo = fopen("consultorios.txt", "w+"); 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (atual != NULL) {
        fprintf(arquivo, " ----Lista de consultorios da      ----\n");
        fprintf(arquivo, "Identificacao: %d\n", atual->identificacao);
        fprintf(arquivo, "Especialidade: %s\n", atual->especialidade);
        fprintf(arquivo, "Equipamentos disponiveis: %s\n", atual->equipamentos_disponiveis);

    
        Paciente* paciente_atual = atual->paciente;
        while (paciente_atual != NULL) {
            fprintf(arquivo, "   ||Pacientes||:  \n");
            fprintf(arquivo, "Nome do paciente: %s\n", paciente_atual->nome);
            fprintf(arquivo, "Idade do paciente: %d\n", paciente_atual->idade);
            fprintf(arquivo, "Situacao de saude do paciente: %s\n", paciente_atual->situacao_saude);
            paciente_atual = paciente_atual->proximo;
        }
        fprintf(arquivo, "===========\n");

        atual = atual->proximo;
    }

    fclose(arquivo);
    printf("Dados dos consultorios salvos com sucesso no arquivo consultorios.txt\n");
}
int verificar_lista(Consultorio* consultorio_aux) {
    if (consultorio_aux == NULL) {
        printf("Lista de consultorios esta vazia\n");
        return 1;
    } else {
        return 0;
    }
}


Consultorio* adicionar_consultorio(Consultorio* lista_consultorios) {
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

    novo_consultorio->paciente = NULL;
    novo_consultorio->proximo = NULL;

    if (lista_consultorios == NULL || novo_consultorio->identificacao < lista_consultorios->identificacao) {
        novo_consultorio->proximo = lista_consultorios;
        return novo_consultorio;
    }

    Consultorio* anterior = lista_consultorios;
    Consultorio* atual = lista_consultorios->proximo;

    while (atual != NULL && novo_consultorio->identificacao > atual->identificacao) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = novo_consultorio;
    novo_consultorio->proximo = atual;

    return lista_consultorios;
}


Consultorio* remover_consultorio_por_id(Consultorio* lista_consultorios) {

    if (verificar_lista(lista_consultorios)==1)
    {
       printf("Lista de consultorios esta vazia\n");
    }
    
    Consultorio *atual = lista_consultorios;
    Consultorio *anterior = NULL;
    int id_a_remover;
    printf("Digite o id do consultorio que deseja remover:\n");
    scanf("%d", &id_a_remover);
    
    while (atual != NULL && atual->identificacao != id_a_remover) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Consultorio nao encontrado no sistema\n");
        return lista_consultorios;
    }

    if (anterior == NULL) {
        lista_consultorios = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Consultorio removido com sucesso.\n");
    
    return lista_consultorios;
}


void imprimir_consultorios_Disponiveis(Consultorio* lista) {

    if (verificar_lista(lista)==1)
    {
        printf("Lista de consultorios esta vazia, nao ha nada para imprimir\n");
    }
    
    Consultorio* imprimir_lista = lista;
    
    
    printf("Lista de consultorios:\n");
    
    while (imprimir_lista != NULL) {
        printf("Identificacao do consultorio: %d\n", imprimir_lista->identificacao);
        printf("Especialidade: %s\n", imprimir_lista->especialidade);
        printf("Equipamentos disponiveis: %s\n", imprimir_lista->equipamentos_disponiveis);
       
        imprimir_lista = imprimir_lista->proximo;
    }
}
Consultorio* buscar_paciente_por_nome(Consultorio* lista_consultorios, char* nome) {
    Consultorio* consultorio_atual = lista_consultorios;
    while (consultorio_atual != NULL) {
        Paciente* paciente_atual = consultorio_atual->paciente;
        while (paciente_atual != NULL) {
            if (strcmp(paciente_atual->nome, nome) == 0) {
                printf("Paciente encontrado:\n");
                printf("Nome: %s, Idade: %d, Situacao Saude: %s\n", paciente_atual->nome, paciente_atual->idade, paciente_atual->situacao_saude);
                return consultorio_atual; 
            }
            paciente_atual = paciente_atual->proximo;
        }
        consultorio_atual = consultorio_atual->proximo;
    }
    printf("Paciente nao encontrado\n");
    return NULL;
}


  Consultorio* editar_paciente(Consultorio* lista, char *nome_editar) {
    char opcao;
    if (verificar_lista(lista) == 1) {
        printf("Lista de consultorios esta vazia\n");
        return lista;
    }

    Consultorio* consultorio_editar = buscar_paciente_por_nome(lista, nome_editar);
    if (consultorio_editar != NULL) {
        printf("Edicao de dados do paciente:\n");
        printf("Deseja editar apenas um dado ou todos? Digite 1 para todos e 0 para apenas um dado\n ");
        scanf(" %c", &opcao);

        if (opcao == '1') {
            printf("Digite o novo nome do paciente:\n");
            scanf(" %[^\n]", consultorio_editar->paciente->nome);
            printf("Digite a nova idade do paciente:\n ");
            scanf(" %d", &consultorio_editar->paciente->idade);
            printf("Digite a nova situacao de saude:\n");
            scanf(" %[^\n]", consultorio_editar->paciente->situacao_saude);
        } else if (opcao == '0') {
            char dado_editar;
            printf("Digite o dado que voce quer editar: 'I' para idade, 'N' para nome e 'S' para situacao de saude\n");
            scanf(" %c", &dado_editar);

            if (dado_editar == 'N' || dado_editar == 'n') {
                printf("Digite o novo nome do paciente:\n");
                scanf(" %[^\n]", consultorio_editar->paciente->nome);
            } else if (dado_editar == 'I' || dado_editar == 'i') {
                printf("Digite a nova idade do paciente:\n ");
                scanf(" %d", &consultorio_editar->paciente->idade);
            } else if (dado_editar == 'S' || dado_editar == 's') {
                printf("Digite a nova situacao de saude:\n");
                scanf(" %[^\n]", consultorio_editar->paciente->situacao_saude);
            } else {
                printf("Opcao invalida. Digite numeros correspondentes com os pedidos.\n");
            }
        } else {
            printf("Opcao invalida. Digite letras correspondentes com os pedidos.\n");
        }
    }

    return lista;
}


      
   void adicionar_paciente_por_id(Consultorio *lista_consultorios) {
    int id_procurar;
    printf("Digite a identificacao do consultorio que esse paciente vai pertencer: ");
    scanf("%d", &id_procurar);
    if (verificar_lista(lista_consultorios) == 1) {
        printf("Lista de consultorios esta vazia\n");
        return;
    }
     Consultorio *consultorio_atual = lista_consultorios;
    while (consultorio_atual != NULL) {
        if (consultorio_atual->identificacao == id_procurar) {
            Paciente *novo_paciente = (Paciente *)malloc(sizeof(Paciente));
            if (novo_paciente == NULL) {
                printf("Erro na alocacao\n");
                exit(1);
            }

            coletar_dados_paciente(novo_paciente);

            consultorio_atual->paciente = adicionar_paciente_ordenado(consultorio_atual->paciente, novo_paciente);
        

            return;
        }
        consultorio_atual = consultorio_atual->proximo;
    }

    printf("Consultorio nao encontrado\n");
}
