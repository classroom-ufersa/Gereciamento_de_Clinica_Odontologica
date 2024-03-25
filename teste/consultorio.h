#ifndef CONSULTORIO_H
#define CONSULTORIO_H

typedef struct Consultorio {
    int identificacao;
    char especialidade[400];
    char equipamentos_disponiveis[100];
    struct Paciente* paciente;
    struct Consultorio* proximo;
    struct Lista_geral*listageral;
} Consultorio;

typedef struct listageral{
    struct Lista_geral*proximo;
    struct Paciente*paciente_geral;
} Lista_geral;

/*Funcao que adiciona pacinte a lista geral*/
Lista_geral* adicionar_paciente_geral(Lista_geral* lista_geral, Paciente* novo_paciente);

/*Funcao que adicina um consultorio*/
Consultorio* adicionar_consultorio(Consultorio* lista_consultorios);

/*Funcao que remove um consultorio por meio do id informado*/
Consultorio*remover_consultorio_por_id(Consultorio*lista_consultorios, int id);

#endif
