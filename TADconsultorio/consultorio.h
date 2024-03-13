#inclide "configuracoes.h"

/*Renomeacao de um tipo estruturado para Consultorio*/
typedef struct consultorio Consultorio;

/*Funcao que adiciona um consultorio,
  Recebe como paramentro um ponteiro*/
Consultorio adicionar_consultorio(Consultorio *c);

/*Funcao que remove um consultorio,
  Recebe como parametro um ponteiro*/
void remover_consultorio(Consultorio *c);
