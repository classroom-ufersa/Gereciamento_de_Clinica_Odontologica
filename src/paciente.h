#ifndef PACIENTE_H
#define PACIENTE_H

#include"consultorio.h"

struct Consultorio;

typedef struct paciente {
    char nome[100];
    int idade;
    char situacao_saude[100];
    struct Consultorio* consultorio;
    struct Paciente* proximo;
} Paciente;

typedef struct lista_atendidos {
    struct Lista_atendidos* proximo;
    Paciente* paciente_atendido;
} Lista_Atendidos;

typedef struct lista_geral {
    struct Lista_geral* proximo;
    Paciente* paciente_geral;
} Lista_geral;

extern struct Lista_geral* lista_geral;

/*Funcao que coleta dados do paciente,
  Recebe como parametro um ponteiro para paciente*/
void coletar_dados_paciente(Paciente* paciente);

/*Funcao que cria um novo paciente e inicializa com os dados fornecidos,
  Recebe como parametros o nome, a idade, a situação de saude e um ponteiro para consultorio*/
Paciente* criar_paciente(char* nome, int idade, char* situacao_saude, struct Consultorio* consultorio);

/*Funcao que adiciona um novo paciente em ordem alfabetica a uma lista encadeada de pacientes,
  Recebe como parametros a lista atual de pacientes e o novo paciente adicionado*/
Paciente* adicionar_paciente_ordenado(Paciente* lista, Paciente* novo_paciente);

/*Funcao que adiciona paciente a uma lista geral de pacientes,
  Recebe como parametros um ponteiro para a lista geral*/
Lista_geral* adicionar_paciente_geral(Lista_geral* lista_geral);

/*Funcao que remove um paciente do inicio da lista e adiciona a lista de atendidos, 
  Recebe como parametros a lista e a lista de atendidos*/
void remover_paciente_por_fila(Lista_geral **lista, Lista_Atendidos **lista_atendidos);

/*Funcao que remove todos os caracteres que nao sao digitos numericos da string,
  Recebe como parametro uma string*/
void tratamento_de_numero(char *variavel_num);

/*Funcao que remove todos os caracteres que nao sao letras maiusculas, minusculas ou espaços,
  Recebe como parametro uma string*/
void tratamento_de_palavras(char *palavra_var);

/*Funcao que transforma a primeira letra em maiuscula e as demais em minusculas,
  Recebe como parametro uma string*/
void string_maiuscula_minuscula(char *palavra_var);

/*Funcao que imprime os dados de cada paciente na lista,
  Recebe como parametro uma lista de pacientes atendidos*/
void imprimir_atendidos(Lista_Atendidos*lista);

#endif /* PACIENTE_H */
