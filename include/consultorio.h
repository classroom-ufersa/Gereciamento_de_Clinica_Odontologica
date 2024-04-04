#ifndef CONSULTORIO_H
#define CONSULTORIO_H
#include"paciente.h"

typedef struct Consultorio {
  int identificacao;
  char especialidade[400];
  char equipamentos_disponiveis[100];
  struct Paciente* paciente;
  struct Consultorio* proximo;
  struct Lista_geral* listageral;
} Consultorio; 

/*Funcao que ler arquivo de texto e insere na lista antes de carregar o menu,
  Recebe como parametros um comeco e um tipo estruturado paciente*/
void ler_arquivo_e_inserir_lista(Consultorio **comeco, struct Paciente **pacientes);

/*Funcao que verifica se a lista esta vazia,
  Recebe como parametros um ponteiro de consultorio*/
int verificar_lista(Consultorio*consultorio_aux); 

/*Funcao que adiciona um consultorio a lista de consultorios,
  Recebe como parametros um ponteiro de consultorio*/
Consultorio* adicionar_consultorio(Consultorio* lista_consultorios); 

/*Funcao que remove um consultorio pelo ID informado,
  Recebe como parametro um ponteiro de consultorio*/
Consultorio* remover_consultorio_por_id(Consultorio* lista_consultorios); 

/*Funcao que verifica se o id digitado existe,
  Recebe como parametro a lista de consultorio e o id*/
int verificar_id_existente(Consultorio* lista_consultorios, int id); 

/*Funcao que verifica a autenticidade do digito unico,
  Recebe como parametros a lista de pacientes e o digito unico*/
int verificar_autenticidade(Consultorio* lista_consultorios, int digito_u); 

/*Funcao que imprime os consultorios disponiveis,
  Recebe como parametro um ponteiro de consultorio*/
void imprimir_consultorios_Disponiveis(Consultorio* lista); 

/*Funcao que salva os consultorios cadastrados e pacientes em um arquivo,
  Recebe como parametros uma lista de consultorios*/
void salvar_consultorios_e_pacientes_em_arquivo(Consultorio* lista_consultorios); 
  
#endif /* CONSULTORIO_H */
