#ifndef CONSULTORIO_H
#define CONSULTORIO_H

typedef struct Consultorio {
    
    int identificacao;
    char especialidade[50];
    char equipamentos_disponiveis[50];
    struct Paciente* lista_paciente;
    struct Consultorio* proximo;
} Consultorio;

typedef struct Listaconsultorio {
    Consultorio *consultorio;
    struct Listaconsultorio* proximo;
} Listaconsultorio;

Listaconsultorio* lista_cria_consultorios();

struct Consultorio* adicionar_consultorio(struct Consultorio* lista_consultorios);

void coletar_dados_consultorio(struct Consultorio* consultorio);

#endif

