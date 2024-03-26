#ifndef CONSULTORIO_H
#define CONSULTORIO_H

#include "paciente.h"

typedef struct Consultorio {
    int identificacao;
    char especialidade[400];
    char equipamentos_disponiveis[100];
    Paciente* paciente;
    struct Consultorio* proximo;
    struct Lista_geral* listageral;
} Consultorio;

Consultorio* criar_consultorio(int identificacao, char* especialidade, char* equipamentos);
Consultorio* adicionar_consultorio(Consultorio* lista_consultorios);
void remover_consultorio_por_id(Consultorio* lista_consultorios);
void imprimir_consultorios_Disponiveis(Consultorio* lista);

#endif /* CONSULTORIO_H */

