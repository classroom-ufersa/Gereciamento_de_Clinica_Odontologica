#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

Paciente* cria_paciente(char nome, int idade, char situacao_saude) {
    Paciente* novo_paciente = (Paciente*)malloc(sizeof(Paciente));
    if (novo_paciente == NULL) {
        printf("Erro na alocacao, tente novamente;");
        exit(1);
    }

    strcpy(novo_paciente->nome,nome);
    novo_paciente->idade = idade;
    strcpy(novo_paciente->situacao_saude, situacao_saude);
    novo_paciente->proximo = NULL;
    return novo_paciente;
}

Paciente* adicionar_paciente_ordenado(Paciente* lista, Paciente* paciente) {
    if (paciente == NULL || lista == NULL || strcmp(paciente->nome, lista->nome) < 0) {
        paciente->proximo = lista;
        return paciente;
    }

    Paciente* anterior = lista;
    Paciente* atual = lista->proximo;

    while (atual != NULL && strcmp(paciente->nome, atual->nome) > 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = paciente;
    paciente->proximo = atual;

    return lista;
}