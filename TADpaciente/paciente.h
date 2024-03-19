#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct paciente { //Criacao de uma estrutura para os dados do paciente :)
  char nome[500];
    int idade;
    char situacao_saude[50];
    char nomeconsultorio[200];
    struct Paciente* proximo;
    struct Paciente* anterior;
}Paciente;

typedef listapaciente  {
    struct Paciente* paciente;
    struct Listapaciente* next;
}Listapaciente;




