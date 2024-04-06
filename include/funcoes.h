#ifndef FUNCOES_H
#define FUNCOES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consultorio.h"
#include "paciente.h"


/*Funcao do menu principal*/
void menu();


/*Funcao para limpar buffer*/
void limpar_buffer();

/*Funcao que remove todos os caracteres que nao sao digitos numericos da string,
  Recebe como parametro uma string*/
void tratamento_de_numero(char *variavel_num); 

/*Funcao que remove todos os caracteres que nao sao letras maiusculas, minusculas ou espaços,
  Recebe como parametro uma string*/
void tratamento_de_palavras(char *palavra_var); 

/*Funcao que transforma a primeira letra em maiuscula e as demais em minusculas,
  Recebe como parametro uma string*/
void string_maiuscula_minuscula(char *palavra_var); 

/*Funcao de tratamento da variavel equipamente para que aceite "." e ":",
  Recebe como parametro uma palavra*/
void tratamento_da_var_equipamentos(char *palavra_var);

#endif /* FUNCOES_H */
