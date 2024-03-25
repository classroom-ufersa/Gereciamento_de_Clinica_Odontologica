#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

void coletar_dados_paciente(Paciente* paciente) {
    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", paciente->nome);
    

    printf("Digite a idade do paciente: ");
    scanf("%d", &paciente->idade);
  

    printf("Digite a situacao da saude do paciente: ");
    scanf(" %[^\n]", paciente->situacao_saude);
    
}
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