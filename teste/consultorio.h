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

void ler_arquivo_e_inserir_lista(Consultorio **comeco, struct Paciente **pacientes, struct Lista_geral **pacientesgerais);
int verificar_lista(Consultorio*consultorio_aux);
Consultorio* adicionar_consultorio(Consultorio* lista_consultorios);
int verificar_id_existente(Consultorio* lista_consultorios, int id);
int verificar_autenticidade_digito_unico(Consultorio* lista_pacientes, int digito_unico);
Consultorio* remover_consultorio_por_id(Consultorio* lista_consultorios);
void imprimir_consultorios_Disponiveis(Consultorio* lista);
void salvar_consultorios_e_pacientes_em_arquivo(Consultorio* lista_consultorios);


#endif /* CONSULTORIO_H */
