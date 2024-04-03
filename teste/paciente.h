#ifndef PACIENTE_H
#define PACIENTE_H

#include"consultorio.h"

struct Consultorio;

typedef struct Paciente {
    char nome[100];
    int idade;
    char situacao_saude[100];
    int digito_unico;
    struct Consultorio* consultorio;
    struct Paciente* proximo;

    
} Paciente;

typedef struct Lista_atendidos {
    struct Lista_atendidos* proximo;
    Paciente* paciente_atendido;
} Lista_Atendidos;


typedef struct Lista_geral {
    struct Lista_geral* proximo;
    Paciente* paciente_geral;
} Lista_geral;

extern struct Lista_geral* lista_geral;
void inserirPaciente(struct Consultorio *consultorio, Paciente *novoPaciente);
void coletar_dados_paciente(Paciente* paciente, struct Consultorio* lista);
Paciente* cria_paciente(char* nome, int idade, char* situacao_saude, int dg);
Paciente* adicionar_paciente_ordenado(Paciente* lista, Paciente* novo_paciente);
void adicionar_paciente_por_id(struct Consultorio* lista_consultorios,  Lista_geral** lista_geral);
Lista_geral* adicionar_paciente_geral(Lista_geral* lista_geral, Paciente* paciente);
void remover_paciente_por_fila(Lista_geral **lista, Lista_Atendidos **lista_atendidos);
void tratamento_de_numero(char *variavel_num);
void tratamento_de_palavras(char *palavra_var);
void string_maiuscula_minuscula(char *palavra_var);
void imprimir_atendidos(Lista_Atendidos*lista);
void imprimir_gerais(Lista_geral* lista);
void arquivo_atendidos(Lista_Atendidos*lista);
 Paciente* buscar_paciente_por_nome(struct Consultorio* lista_consultorios, char* nome, int digitoUnico);
 void editar_paciente(struct Consultorio* lista, char* nome_editar, int dg_procurar);
#endif /* PACIENTE_H */
