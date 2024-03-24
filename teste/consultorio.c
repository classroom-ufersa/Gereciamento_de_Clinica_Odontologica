#include <stdio.h>
#include <stdlib.h>
#include "consultorio.h"
#include"paciente.h"

 ListaConsultorio* adicionar_consultorio(struct ListaConsultorio* lista_consultorios) {
    struct ListaConsultorio* novo_consultorio = (struct ListaConsultorio*)malloc(sizeof(struct ListaConsultorio));
    if (novo_consultorio == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    novo_consultorio->consultorio = (struct Consultorio*)malloc(sizeof(struct Consultorio));
    if (novo_consultorio->consultorio == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    printf("Digite o ID do consultorio: ");
    scanf("%d", &novo_consultorio->consultorio->id);
    getchar();
    printf("Digite a especialidade desse consultorio: ");
    scanf("%[^\n]", novo_consultorio->consultorio->especialidade);
    getchar();
    printf("Digite os equipamentos que estao disponiveis nesse consultorio:\n");
    scanf("%[^\n]", novo_consultorio->consultorio->equipamentos_disponiveis);
    getchar();

    novo_consultorio->proximo = NULL;

    if (lista_consultorios == NULL || novo_consultorio->consultorio->id < lista_consultorios->consultorio->id) {
        novo_consultorio->proximo = lista_consultorios;
        return novo_consultorio;
    }

    struct ListaConsultorio* anterior = lista_consultorios;
    struct ListaConsultorio* atual = lista_consultorios->proximo;

    while (atual != NULL && novo_consultorio->consultorio->id > atual->consultorio->id) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = novo_consultorio;
    novo_consultorio->proximo = atual;

    return lista_consultorios;
}

void remover_consultorio(struct ListaConsultorio*lista){}
