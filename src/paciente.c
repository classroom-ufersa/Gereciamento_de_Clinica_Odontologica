#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "paciente.h"

struct Listapaciente* lista_cria() {
    return NULL;
}

void verificar_lista_vazia(struct Listapaciente* lista_paciente_var){
    if (lista_paciente_var==NULL){
        printf("Lista vazia\n");
    }
}

struct Listapaciente* adicionar_paciente(struct Listapaciente* lista_pacientes) {
    struct Listapaciente* novo_paciente = (struct Listapaciente*)malloc(sizeof(struct Listapaciente));
    if (novo_paciente == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", novo_paciente->paciente.nome);

    printf("Digite a idade do paciente: ");
    scanf("%d", &novo_paciente->paciente.idade);
    getchar(); 

    printf("Qual a situacao da saude?\n");
    scanf(" %[^\n]", novo_paciente->situacao_saude);
    
    novo_paciente->proximo = NULL;
    return novo_paciente;
}

struct Paciente* buscarpornome(struct Listapaciente* listapaciente) {
    char nomeprocurar[80];
    printf("Digite o nome que deseja buscar:\n");
    scanf(" %[^\n]", nomeprocurar);

    struct Listapaciente* variaveltemp = listapaciente;
    while (variaveltemp != NULL) {
        if (strcmp(variaveltemp->paciente.nome, nomeprocurar) == 0) {
            return &variaveltemp->paciente;
        }
        variaveltemp = variaveltemp->proximo;
    }
    printf("Desculpe, nao conseguimos encontrar esse nome.\n");


}

void remover_paciente(struct Listapaciente *listapaciente) {
    if (*listapaciente == NULL) {
        printf("Lista Vazia:\n");
        return;
    }
    struct Listapaciente* lista_atual = *listapaciente;
    *listapaciente =(*listapaciente)->proximo;
    free(lista_atual);
}

void editar_paciente(struct Listapaciente* listapaciente) {
    char nome[500];
    int idade;
    char situacao_saude[500];

    printf("Digite o nome do paciente que deseja editar:\n");
    scanf(" %[^\n]", nome);

    struct Listapaciente* atual = listapaciente;
    while (atual != NULL) {
        if (strcmp(atual->paciente.nome, nome) == 0) {
            printf("Digite o novo nome do paciente;\n");
            scanf(" %[^\n]", nome);

            printf("Digite a nova idade:\n");
            scanf("%d", &idade);

            printf("Digite a nova situacao de saude:\n");
            scanf(" %[^\n]", situacao_saude);

            strcpy(atual->paciente.nome, nome);
            atual->paciente.idade = idade;
            strcpy(atual->paciente.situacao_saude, situacao_saude);
            return;
        }
        atual = atual->proximo;
    }
    printf("Paciente nao encontrado.\n");
}
