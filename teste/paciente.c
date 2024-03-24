#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

struct Paciente* coletar_dados_paciente() {
    struct Paciente* novo_paciente = (struct Paciente*)malloc(sizeof(struct Paciente));
    if (novo_paciente == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", novo_paciente->nome);

    printf("Digite a idade do paciente: ");
    scanf("%d", &novo_paciente->idade);
    getchar();

    printf("Qual a situacao da saude do paciente?\n");
    scanf(" %[^\n]", novo_paciente->situacao_saude);

    novo_paciente->proximo = NULL;

    return novo_paciente;
}
struct ListaPaciente* inserir_paciente_ordenado(struct ListaPaciente* lista_pacientes, struct Paciente* novo_paciente) {
    struct ListaPaciente* novo_no = (struct ListaPaciente*)malloc(sizeof(struct ListaPaciente));
    if (novo_no== NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    novo_no->paciente = novo_paciente;

    if (lista_pacientes == NULL || strcmp(novo_paciente->nome, lista_pacientes->paciente->nome) < 0) {
        novo_no->proximo = lista_pacientes;
        return novo_no;
    }

    struct ListaPaciente* anterior = lista_pacientes;
    struct ListaPaciente* atual = lista_pacientes->proximo;

    while (atual != NULL && strcmp(novo_paciente->nome, atual->paciente->nome) > 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    novo_no->proximo = atual;
    anterior->proximo = novo_no;

    return lista_pacientes;
}
void buscar_por_nome_paciente(struct ListaPaciente* lista) {
    char nome_buscado[50];
    printf("Digite o nome que deseja buscar:\n");
    scanf(" %[^\n]", nome_buscado);

    struct ListaPaciente* lista_busca = lista;
    while (lista_busca != NULL && strcmp(lista_busca->paciente->nome, nome_buscado) != 0) {
        lista_busca = lista_busca->proximo;
    }

    if (lista_busca != NULL) {
        printf("Paciente encontrado:\n");
        printf("Nome: %s\n", lista_busca->paciente->nome);
        printf("Idade: %d\n", lista_busca->paciente->idade);
        printf("Situacao de Saude: %s\n", lista_busca->paciente->situacao_saude);
    } else {
        printf("Paciente nao encontrado.\n");
    }
}


      

