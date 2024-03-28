#ifndef CONSULTORIO_H
#define CONSULTORIO_H

#include "paciente.h"

typedef struct Consultorio {
    int identificacao;
    char especialidade[400];
    char equipamentos_disponiveis[100];
    struct Paciente* paciente;
    struct Consultorio* proximo;
    struct Lista_geral* listageral;
} Consultorio;


int verificar_lista(Consultorio*consultorio_aux);
Consultorio* adicionar_consultorio(Consultorio* lista_consultorios);
Consultorio* remover_consultorio_por_id(Consultorio* lista_consultorios);
void imprimir_consultorios_Disponiveis(Consultorio* lista);
void adicionar_paciente_por_id(Consultorio *lista_consultorios);
Consultorio* buscar_paciente_por_nome(Consultorio* lista_consultorios, char* nome);
void salvar_consultorios_em_arquivo(Consultorio* lista_consultorios);
Consultorio* editar_paciente(Consultorio* lista, char* nome_editar);
#endif /* CONSULTORIO_H */

