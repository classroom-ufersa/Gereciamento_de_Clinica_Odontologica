#include <stdio.h>
#include <stdlib.h>
#include "consultorio.h"
#include"paciente.h"


void ler_dados(){}
void salvar_consultorios_em_arquivo(Consultorio* lista_consultorios) {
    FILE* arquivo;
    Consultorio* atual = lista_consultorios;

    arquivo = fopen("consultorios.txt", "a"); 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (atual != NULL) {
        fprintf(arquivo, "ID: %d\n", atual->identificacao);
        fprintf(arquivo, "Especialidade: %s\n", atual->especialidade);
        fprintf(arquivo, "Equipamentos disponiveis: %s\n", atual->equipamentos_disponiveis);

    
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



Consultorio* adicionar_consultorio(Consultorio* lista_consultorios) {
    Consultorio* novo_consultorio = (Consultorio*)malloc(sizeof(Consultorio));
    if (novo_consultorio == NULL) {
        printf("Erro ao alocar memoria para o novo consultorio\n");
        exit(1);
    }

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



   void remover_consultorio_por_id(Consultorio* lista_consultorios) {
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
    Consultorio* imprimir_lista = lista;
    printf("Lista de consultorios:\n");
    while (imprimir_lista != NULL) {
        printf("Identificacao do consultorio: %d\n", imprimir_lista->identificacao);
        printf("Especialidade: %s\n", imprimir_lista->especialidade);
        printf("Equipamentos disponiveis: %s\n", imprimir_lista->equipamentos_disponiveis);
        imprimir_lista = imprimir_lista->proximo;
    }
}
