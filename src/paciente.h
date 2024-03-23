#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct paciente {
    char nome[500];
    int idade;
    char situacao_saude[50];
    struct paciente* proximo;
} Paciente;

typedef struct listapaciente {
    struct paciente* paciente;
    struct listapaciente* proximo;
    struct pacientesatendidos* lista;
} Listapaciente;

typedef struct pacientesatendidos {
    struct pacientesatendidos* prox;
} Pacientes_atendidos;



struct Listapaciente* insere_paciente_ordenado(struct Listapaciente* inicio, struct Paciente* novo);
struct Paciente* coletar_dados_paciente();
void remover_paciente(struct Listapaciente* listapaciente);
void editar_paciente(struct Listapaciente* listapaciente);
#endif