#ifndef CONSULTORIO_H
#define CONSULTORIO_H
  #include"paciente.h"
typedef struct consultorio Consultorio;


typedef struct listaconsultorio Listaconsultorio;

struct Listaconsultorio* lista_cria();
 Listaconsultorio* adicionar_consultorio(Consultorio* consultorio, Listaconsultorio* lista_consultorios);

Consultorio* coletar_Dados();
void escrever_consultorio(struct Listaconsultorio* listaconsultorio);
void ler_consultorio(struct Listaconsultorio *listaconsultorio);
void remover_consultorio(Listaconsultorio **listaconsultorio);
void verificar_lista_vazia(struct Listaconsultorio* lista_consultorio);

#endif

