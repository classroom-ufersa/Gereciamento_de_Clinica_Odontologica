#include <stdio.h>
#include <stdlib.h>
#include "consultorio.h"
#include"paciente.h"

/*lembrar  de adicionar as funcoes de tratametto de dados;
talvez criar uma pasta para isso;*/

void salvar_consultorios_em_arquivo(Consultorio* lista_consultorios) {
    FILE* arquivo;
    Consultorio* atual = lista_consultorios;

    arquivo = fopen("consultorios.txt", "w"); // Abre o arquivo para escrita (sobrescreve o conteúdo existente)
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (atual != NULL) {
        fprintf(arquivo, "ID: %d\n", atual->identificacao);
        fprintf(arquivo, "Especialidade: %s\n", atual->especialidade);
        fprintf(arquivo, "Equipamentos disponiveis: %s\n", atual->equipamentos_disponiveis);

        // Salvar informações dos pacientes, se houver
        Paciente* paciente_atual = atual->paciente;
        while (paciente_atual != NULL) {
            fprintf(arquivo, "Nome do paciente: %s\n", paciente_atual->nome);
            fprintf(arquivo, "Idade do paciente: %d\n", paciente_atual->idade);
            fprintf(arquivo, "Situacao de saude do paciente: %s\n", paciente_atual->situacao_saude);
            paciente_atual = paciente_atual->proximo;
        }

        fprintf(arquivo, "------------------------------------\n");

        atual = atual->proximo;
    }

    fclose(arquivo);
    printf("Dados dos consultorios salvos com sucesso no arquivo consultorios.txt\n");
}

Lista_geral* adicionar_paciente_geral(Lista_geral* lista_geral, Paciente* novo_paciente) {
    Lista_geral* novo_item = (Lista_geral*)malloc(sizeof(Lista_geral));
    if (novo_item == NULL) {
        printf("Erro na alocacao, tente novamente;");
        exit(1);
    }

    novo_item->paciente_geral = novo_paciente;
    novo_item->proximo = NULL;

    if (lista_geral == NULL) {
        return novo_item;
    }

    Lista_geral* atual = lista_geral;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = novo_item;
    return lista_geral;
}

/*Funcao que adiciona consultorio a lista, 
  Recebe como parametros um ponteiro para consultorio*/
Consultorio* adicionar_consultorio(Consultorio* lista_consultorios) {
    Consultorio* novo_consultorio = (Consultorio*)malloc(sizeof(Consultorio));
    if (novo_consultorio == NULL) {
        printf("Erro ao alocar memoria para o novo consultorio\n");
        exit(1);
    }

    Consultorio *anterior = NULL;
    Consultorio* var = lista_consultorios;

    printf("Digite a identificacao do consultorio: ");
    scanf("%d", &novo_consultorio->identificacao);

    printf("Deseja adicionar pacientes a esse consultorio (S/N)?\n");
    char escolha;
    scanf(" %c", &escolha);

    if (escolha == 'S' || escolha == 's') {
        do {
            Paciente* novo_paciente = (Paciente*)malloc(sizeof(Paciente));
            if (novo_paciente == NULL) {
                printf("Erro ao alocar memoria para o novo paciente\n");
                exit(1);
            }

            printf("Digite o nome do paciente: ");
            scanf(" %[^\n]", novo_paciente->nome);

            printf("Digite a idade do paciente: ");
            scanf("%d", &novo_paciente->idade);

            printf("Digite a situacao de saude do paciente: ");
            scanf(" %[^\n]", novo_paciente->situacao_saude);

            novo_paciente->proximo = NULL;

            if (novo_consultorio->paciente == NULL) {
                novo_consultorio->paciente = novo_paciente;
            } else {
                Paciente* aux = novo_consultorio->paciente;
                while (aux->proximo != NULL) {
                    aux = aux->proximo;
                }
                aux->proximo = novo_paciente;
            }

            printf("Paciente adicionado com sucesso.\n");

            printf("Deseja adicionar outro paciente? (s/n): ");
            char continuar;
            scanf(" %c", &continuar);
            if (continuar != 's' && continuar != 'S') {
                break;
            }
        } while (1);
    } else {
        novo_consultorio->paciente = NULL;
    }

    while (var != NULL && var->identificacao < novo_consultorio->identificacao) {
        anterior = var;
        var = var->proximo;
    }

    if (anterior == NULL) {
        novo_consultorio->proximo = lista_consultorios;
        return novo_consultorio;
    } else {
        anterior->proximo = novo_consultorio;
        novo_consultorio->proximo = var;
        return lista_consultorios;
    }
}

/*Funcao que remove consultorio pelo id,
  Recebe como parametros um ponteiro de consultorio e o id*/
Consultorio* remover_consultorio_por_id(Consultorio* lista_consultorios, int id) {
    Consultorio *atual = lista_consultorios;
    Consultorio *anterior = NULL;

    while (atual != NULL && atual->identificacao != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Consultorio com o ID %d nao encontrado.\n", id);
        return lista_consultorios;
    }

    if (anterior == NULL) {
        lista_consultorios = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Consultorio com ID %d removido com sucesso.\n", id);
    return lista_consultorios;
}
