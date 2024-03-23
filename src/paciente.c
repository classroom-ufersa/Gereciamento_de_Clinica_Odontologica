#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "paciente.h"

Listapaciente* lista_cria_paciente() {
    return NULL;
}

void verificar_lista_vazia(struct Listapaciente* lista_paciente_var){
    if (lista_paciente_var==NULL){
        printf("Lista vazia\n");
    }
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
    novo->proximo = NULL;
    struct Listapaciente *atual = lista;
    while (atual->proximo != NULL && strcmp(paciente->nome, atual->proximo->paciente->nome) > 0)
    {
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;

    return lista;
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
void remover_paciente(Listapaciente *lista_geral, Listaatendidos *lista_atendidos) {
    if (lista_geral == NULL) {
        printf("Lista Vazia\n");
        return;
    }

    Listapaciente *paciente_removido = lista_geral;
    lista_geral = paciente_removido->proximo;

    
    paciente_removido->proximo = lista_atendidos->primeiro;
     printf("Paciente removido: %s %d %s\n", paciente_removido->paciente->nome, paciente_removido->paciente->idade,paciente_removido->paciente->situacao_saude);

    lista_atendidos->primeiro = paciente_removido;
   
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

struct Paciente* buscarpornome(struct Listapaciente* listapaciente) {
    char nomeprocurar[80];
    printf("Digite o nome que deseja buscar:\n");
    scanf(" %[^\n]", nomeprocurar);

    struct Listapaciente* variaveltemp = listapaciente;
    while (variaveltemp != NULL) {
        if (strcmp(variaveltemp->paciente->nome, nomeprocurar) == 0) {
            return &variaveltemp->paciente;
        }
        variaveltemp = variaveltemp->proximo;
    }
    printf("Desculpe, nao conseguimos encontrar esse nome.\n");
}

void lista_atendidos(){

}

