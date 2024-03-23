#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Listapaciente* lista_cria_paciente() {
    return NULL;
}

Listapaciente* addPaciente(struct Paciente *paciente, struct Listapaciente *lista)
{
    struct Listapaciente *novo = (struct Listapaciente *)malloc(sizeof(struct Listapaciente));
    if (novo == NULL)
    {
        printf("Memoria insuficiente \n");
        exit(1);
    }
    novo->paciente = paciente;
    novo->proximo = lista;
    return novo; 
}

struct Paciente *coletar_Dados(void)
{
    struct Paciente *novo_paciente = (struct Paciente*)malloc(sizeof(struct Paciente));
    if (novo_paciente == NULL)
    {
        printf("Memoria insuficiente \n");
        exit(1);
    }
    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", novo_paciente->nome);
    printf("Digite a idade do paciente: ");
    scanf(" %d", &novo_paciente->idade);
    printf("Digite a doenca do paciente: ");
    scanf(" %[^\n]", novo_paciente->situacao_saude);
    return novo_paciente;
}

void liberar_paciente(struct Paciente* paciente) {
    free(paciente);
    paciente = NULL; 
}

void remover_paciente(struct Listapaciente *lista_geral) {
    if (lista_geral == NULL) {
        printf("Lista Vazia:\n");
        return;
    }

    struct Listapaciente *lista_atual = lista_geral;
    lista_geral = (lista_geral)->proximo;

    struct Listapaciente *proximo;
    while (lista_atual != NULL) {
        proximo = lista_atual->proximo;
        free(lista_atual);
        lista_atual = proximo;
    }
    printf("Todos os pacientes foram removidos.\n");
}

void editar_paciente(struct Listapaciente *lista) {
    char nome[500];
    int idade;
    char situacao_saude[500];

    printf("Digite o nome do paciente que deseja editar:\n");
    scanf(" %[^\n]", nome);

    struct Listapaciente *atual = lista;
    while (atual != NULL && strcmp(atual->paciente->nome, nome) != 0) {
        atual = atual->proximo;
    }

    if (atual != NULL) {
        printf("Digite o novo nome do paciente:\n");
        scanf(" %[^\n]", nome);

        printf("Digite a nova idade:\n");
        scanf("%d", &idade);

        printf("Digite a nova situacao de saude:\n");
        scanf(" %[^\n]", situacao_saude);

        strcpy(atual->paciente->nome, nome);
        atual->paciente->idade = idade;
        strcpy(atual->paciente->situacao_saude, situacao_saude);

        printf("Paciente atualizado com sucesso!\n");
    }
}

  

