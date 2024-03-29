#ifndef PACIENTE_H
#define PACIENTE_H

#include"consultorio.h"

struct Consultorio;

typedef struct Paciente {
    char nome[100];
    int idade;
    char situacao_saude[100];
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

void coletar_dados_paciente(Paciente* paciente);
Paciente* criar_paciente(char* nome, int idade, char* situacao_saude, struct Consultorio* consultorio);
Paciente* adicionar_paciente_ordenado(Paciente* lista, Paciente* novo_paciente);
Lista_geral* adicionar_paciente_geral(Lista_geral* lista_geral);
void tratamento_de_numero(char *variavelid);
void tratamento_de_palavras(char *palavra_var);
void string_maiuscula_minuscula(char *palavra_var);
//Paciente* buscar_paciente_por_nome(struct Consultorio* consultorio, char* nome);
//Paciente* editar_paciente(struct Consultorio* consultorio, char* nome);
//void remover_paciente_por_fila(Lista_geral** lista_geral, Lista_Atendidos** lista_atendidos);
//void editar_dados_paciente(Paciente*lista_pacientes);
#endif /* PACIENTE_H */
