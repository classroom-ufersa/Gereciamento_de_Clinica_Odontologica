#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "consultorio.h"


void coletar_dados_paciente(Paciente* paciente) {
    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", paciente->nome);
    

    printf("Digite a idade do paciente: ");
    scanf("%d", &paciente->idade);
  

    printf("Digite a situacao da saude do paciente: ");
    scanf(" %[^\n]", paciente->situacao_saude);
    
}
Paciente* cria_paciente(char* nome, int idade, char* situacao_saude) {
    Paciente* novo_paciente = (Paciente*)malloc(sizeof(Paciente));
    if (novo_paciente == NULL) {
        printf("Erro na alocacao, tente novamente;");
        exit(1);
    }

    strcpy(novo_paciente->nome, nome);
    novo_paciente->idade = idade;
    strcpy(novo_paciente->situacao_saude, situacao_saude);
    novo_paciente->proximo = NULL;
    return novo_paciente;
}


Paciente* adicionar_paciente_ordenado(Paciente* lista, Paciente* novo_paciente) {
    if (lista == NULL || novo_paciente == NULL || strcmp(novo_paciente->nome, lista->nome) < 0) {
        novo_paciente->proximo = lista;
        return novo_paciente;
    }

    Paciente* anterior = lista;
    Paciente* atual = lista->proximo;

    while (atual != NULL && strcmp(novo_paciente->nome, atual->nome) > 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = novo_paciente;
    novo_paciente->proximo = atual;

    return lista;
}

void editar_dados_paciente(Paciente*lista_pacientes){
    char nome_buscar[500];
    printf("Digite o nome do paciente que deseja editar:|n");
    scanf("%[^\n]", nome_buscar);
      if (lista_pacientes==NULL)
      {
     printf("Lista de pacientes esta vazia\n");
      }
      Paciente*lista_atual=lista_pacientes;
      while (lista_pacientes!=NULL)
      {
        if(strcmp(lista_atual->nome, nome_buscar)==0){
            printf("Digite o novo nome do paciente:\n");
            scanf("%[^\n]", lista_atual->nome);
            printf("Digite a nova idade do paciente:\n");
            scanf("%d", lista_atual->idade);
            printf("Digite a alteracao para a situacao de saude do paciente");
            scanf("%[^\n]", lista_atual->situacao_saude);

        }
        lista_atual=lista_atual->proximo;
        
      }}