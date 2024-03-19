#include "configuracoes.h"
#include "paciente.h"

/*Renomeacao de um tipo estruturado para Consultorio*/
typedef struct consultorio Consultorio;

/*Renomeacao de um tipo estruturado para Lista*/
typedef struct listaconsultorio Lista;

/*Funcao que adiciona um consultorio,
  Recebe como paramentro um ponteiro*/
Consultorio adicionar_consultorio(Consultorio *c);

/*Funcao que remove um consultorio,
  Recebe como parametro um ponteiro*/
void remover_consultorio(Consultorio *c);

/*Funcao que escreve o consultorio*/
void escrever_consultorio(Listaconsultorio *listaconsultorio);

/**/
void ler_consultorio(Listaconsultorio *listaconsultorio);

/**/
void remover_consultorio( Listaconsultorio *listaconsultorio);

/**/
Consultorio adicionar_consultorio(Consultorio *c);

/*Funcao que remove consultorio*/
void remover_consultorio(Consultorio *c);
