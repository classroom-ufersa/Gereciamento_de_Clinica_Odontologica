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










/*Lista_geral* adicionar_paciente_geral(Lista_geral* lista_geral, Paciente* novo_paciente) {
    Lista_geral* novo_paciente_geral = (Lista_geral*)malloc(sizeof(Lista_geral));
    if (novo_paciente_geral== NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    novo_paciente_geral->paciente_geral = novo_paciente;
    novo_paciente_geral->proximo = lista_geral;
    
    return novo_paciente_geral;
}*/


/*Paciente* editar_paciente(Consultorio* consultorio, char* nome) {
    char novo_nome[500];
    int nova_idade;
    char nova_situacao_saude[200];
    Paciente* paciente_atual = consultorio->paciente;
    while (paciente_atual != NULL) {
        if (strcmp(paciente_atual->nome, nome) == 0) {
           
            printf("Edicao dos dados do paciente:\n");
            printf("Digite o novo nome do paciente:\n");
            scanf(" %[^\n]", novo_nome);  
            printf("Digite a nova idade do paciente:\n");
            scanf("%d", &nova_idade);
            printf("Digite a nova condicao de saude do paciente:\n");
            scanf(" %[^\n]", nova_situacao_saude);  
            
            strcpy(paciente_atual->nome, novo_nome);
            paciente_atual->idade = nova_idade;
            strcpy(paciente_atual->situacao_saude, nova_situacao_saude);
            
            return paciente_atual;  
        }
        paciente_atual = paciente_atual->proximo;
    }
    printf("Paciente nao encontrado\n");
    return NULL;  
    
}*/
 
 