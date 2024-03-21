#include "configuracoes.h"
#include "paciente.h"


typedef struct consultorio Consultorio;


typedef struct listaconsultorio Lista;


Consultorio adicionar_consultorio(Consultorio *c);

void remover_consultorio(Consultorio *c);


void escrever_consultorio(Listaconsultorio *listaconsultorio);


void ler_consultorio(Listaconsultorio *listaconsultorio);

void remover_consultorio( Listaconsultorio *listaconsultorio);

/**/
Consultorio adicionar_consultorio(Consultorio *c);

/*Funcao que remove consultorio*/
void remover_consultorio(Consultorio *c);
