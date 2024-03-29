#include <stdio.h>
#include <stdlib.h>
#include "consultorio.h"
#include"paciente.h"

void salvar_consultorios_em_arquivo(Consultorio* lista_consultorios) {
    FILE* arquivo;
	Consultorio* atual = lista_consultorios;
	arquivo = fopen("consultorios_e_pacientes.txt", "w+"); 
    
    if (arquivo == NULL) {
	    printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
	
	while (atual != NULL) {
        fprintf(arquivo, "===== LISTA DE CONSULTORIOS =====\n");
        fprintf(arquivo, "Identificacao: %d\n", atual->identificacao);
        fprintf(arquivo, "Especialidade: %s\n", atual->especialidade);
        fprintf(arquivo, "Equipamentos disponiveis: %s\n", atual->equipamentos_disponiveis);

	    Paciente* paciente_atual = atual->paciente;
        while (paciente_atual != NULL) {
	        fprintf(arquivo, "===== Pacientes =====: \n");
            fprintf(arquivo, "Nome do paciente: %s\n", paciente_atual->nome);
            fprintf(arquivo, "Idade do paciente: %d\n", paciente_atual->idade);
            fprintf(arquivo, "Situacao de saude do paciente: %s\n", paciente_atual->situacao_saude);
            paciente_atual = paciente_atual->proximo;
        }
        fprintf(arquivo, "=========================\n");
        atual = atual->proximo;
    }

    fclose(arquivo);
    printf("Dados dos consultorios salvos com sucesso! Arquivo consultorios.txt .\n");
}

int verificar_lista(Consultorio* consultorio_aux) {
    if (consultorio_aux == NULL) {
        printf("Lista de consultorios esta vazia\n");
        return 1;
    } else {
        return 0;
    }
}

Consultorio* adicionar_consultorio(Consultorio* lista_consultorios) {
    Consultorio* novo_consultorio = (Consultorio*)malloc(sizeof(Consultorio));
    if (novo_consultorio == NULL) {
        printf("Erro ao alocar memoria para o novo consultorio\n");
        exit(1);
    }
    
    char identificacao[500];
    printf("Digite o ID do consultorio:\n ");
    scanf(" %[^\n]", identificacao);
    tratamento_de_numero(identificacao);
    novo_consultorio->identificacao=atoi(identificacao);

    printf("Digite a especialidade desse consultorio:\n ");
    scanf(" %[^\n]", novo_consultorio->especialidade);
    tratamento_de_palavras(novo_consultorio->especialidade);
    string_maiuscula_minuscula(novo_consultorio->especialidade);

    printf("Digite os equipamentos que estao disponiveis nesse consultorio:\n");
    scanf(" %[^\n]", novo_consultorio->equipamentos_disponiveis);
    tratamento_de_palavras(novo_consultorio->equipamentos_disponiveis);
    string_maiuscula_minuscula(novo_consultorio->equipamentos_disponiveis);

    novo_consultorio->paciente = NULL;
    novo_consultorio->proximo = NULL;

    if (lista_consultorios == NULL || novo_consultorio->identificacao < lista_consultorios->identificacao) {
        novo_consultorio->proximo = lista_consultorios;
        return novo_consultorio;
    }

    Consultorio* anterior = lista_consultorios;
    Consultorio* atual = lista_consultorios->proximo;

    while (atual != NULL && novo_consultorio->identificacao > atual->identificacao) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = novo_consultorio;
    novo_consultorio->proximo = atual;

    return lista_consultorios;
}
