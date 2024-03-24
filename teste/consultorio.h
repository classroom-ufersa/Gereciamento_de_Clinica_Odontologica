#ifndef CONSULTORIO_H
#define CONSULTORIO_H

struct Consultorio {
    int id;
    char especialidade[80];
    char equipamentos_disponiveis[100];
    struct ListaPaciente* pacientes;
    struct Consultorio* proximo;
};

typedef struct ListaConsultorio {
    struct Consultorio* consultorio;
    struct ListaConsultorio* proximo;
} ListaConsultorio;
ListaConsultorio* adicionar_consultorio(struct ListaConsultorio* lista_consultorios);
void imprimir_consultorios(struct ListaConsultorio* lista_consultorios);
#endif


