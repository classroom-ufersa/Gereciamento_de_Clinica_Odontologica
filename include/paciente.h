#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct paciente { //Criacao de uma estrutura para os dados do paciente :)
  char nome[500];
    int idade;
    char situacao_saude[50];
    struct Paciente* proximo;
 
}Paciente;

typedef listapaciente  {
    struct Paciente* paciente;
    struct Listapaciente* proximo;
    struct Pacientes_atendidos *lista;
}Listapaciente;

typedef struct pacientesatendidos{
  struct Pacientes_atendidos*prox;
}Pacientes_atendidos;




