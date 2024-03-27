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

typedef struct Lista_geral {
    struct Lista_geral* proximo;
    Paciente* paciente_geral;
} Lista_geral;

typedef struct Lista_atendidos {
    struct Lista_atendidos* proximo;
    Paciente* paciente_atendido;
} Lista_Atendidos;

Paciente* criar_paciente(char* nome, int idade, char* situacao_saude, struct Consultorio* consultorio);
Paciente* adicionar_paciente_ordenado(Paciente* lista, Paciente* novo_paciente);
//Paciente* buscar_paciente_por_nome(struct Consultorio* consultorio, char* nome);
//Paciente* editar_paciente(struct Consultorio* consultorio, char* nome);
void remover_paciente_por_fila(Lista_geral** lista_geral, Lista_Atendidos** lista_atendidos);
void editar_dados_paciente(Paciente*lista_pacientes);
#endif /* PACIENTE_H */
