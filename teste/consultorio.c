#include "consultorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Listaconsultorio* lista_cria_consultorios() {
    return NULL;
}

struct Consultorio* adicionar_consultorio(struct Consultorio* lista_consultorios) {
    struct Consultorio* novo_consultorio = (struct Consultorio*)malloc(sizeof(struct Consultorio));
    if (novo_consultorio == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }
    novo_consultorio->lista_paciente = NULL;
    novo_consultorio->proximo = lista_consultorios;

    return novo_consultorio;
}

void coletar_dados_consultorio(struct Consultorio* consultorio) {
    printf("Digite a identificacao do consultorio: ");
    scanf("%d", &consultorio->identificacao);

    printf("Digite a especialidade do consultorio: ");
    scanf(" %[^\n]", consultorio->especialidade);

    printf("Digite os equipamentos disponiveis: ");
    scanf(" %[^\n]", consultorio->equipamentos_disponiveis);
}
