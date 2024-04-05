#ifndef PACIENTE_H
#define PACIENTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consultorio.h"
#include "funcoes.h"

struct Consultorio;

typedef struct Paciente {
    char nome[100];
    int idade;
    char situacao_saude[100];
    int digito_unico;
    struct Consultorio* consultorio;
    struct Paciente* proximo;
} Paciente;

typedef struct  Lista_atendidos {
    struct Lista_atendidos* proximo;
    Paciente* paciente_atendido;
} Lista_Atendidos;

typedef struct Lista_geral {
    struct Lista_geral* proximo;
    Paciente* paciente_geral;
} Lista_geral;

extern struct Lista_geral* lista_geral;

/*Funcao que coleta dados do paciente,
  Recebe como parametro um ponteiro para paciente*/
void coletar_dados_paciente(Paciente* paciente, struct Consultorio* lista);

/*Funcao que cria um novo paciente e inicializa com os dados fornecidos,
  Recebe como parametros o nome, a idade, a situação de saude e um ponteiro para consultorio*/
Paciente* criar_paciente(char* nome, int idade, char* situacao_saude, int dg);

    
/*Funcao que adiciona um novo paciente em ordem alfabetica a uma lista encadeada de pacientes,
  Recebe como parametros a lista atual de pacientes e o novo paciente adicionado*/
Paciente* adicionar_paciente_ordenado(Paciente* lista, Paciente* novo_paciente); 

/*Funcao que adiciona paciente a uma lista geral de pacientes,
  Recebe como parametros um ponteiro para a lista geral*/
Lista_geral* adicionar_paciente_geral(Lista_geral* lista_geral, Paciente* paciente); 

/*Funcao que imprime os dados de cada paciente na lista,
  Recebe como parametro uma lista de pacientes atendidos*/
void imprimir_atendidos(Lista_Atendidos*lista); 

/*Funcao que coloca os pacientes atendidos em uma lista,
  Recebe como parametro uma lista*/
void arquivo_atendidos(Lista_Atendidos*lista); 

/*Funcao que remove um paciente do inicio da lista e adiciona a lista de atendidos, 
  Recebe como parametros a lista e a lista de atendidos*/
void remover_paciente_por_fila(Lista_geral **lista, Lista_Atendidos **lista_atendidos); 

/*Funcao que busca o paciente no consultorio pelo nome,
  Recebe como parametros a lista de consultorios, o nome e o digito*/
Paciente* buscar_paciente_por_nome(struct Consultorio* lista_consultorios, char* nome, int digitoUnico); 

/* Funcao que exibe a lista geral, 
  Recebe como parametro a lista*/
void imprimir_gerais(Lista_geral* lista); 
    
/*Funcao que adiciona o paciente ao consultorio por meio do ID,
  Recebe como parametros a lista de consultorio e a lista geral*/
void adicionar_paciente_por_id(struct Consultorio* lista_consultorios,  Lista_geral** lista_geral); 

/*Funcao que edita paciente que esta na lista,
  Recebe como parametros a lista, o nome a ser editado e o dg procurar*/
void editar_paciente(struct Consultorio* lista, char* nome_editar, int dg_procurar);

/*Funcao que remove um paciente do consultorio,
  Recebe como parametros uma lista, o nome e o dg remover*/
void remover_paciente_para_inserir(struct Consultorio* lista, char* nome_remover, int dg_remover);

#endif /* PACIENTE_H */
