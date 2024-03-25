#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct Paciente {
    char nome[100];
    int idade;
    char situacao_saude[100];
    struct Consultorio* consultorio;
    struct Paciente* proximo;
} Paciente;

/*Funcao que cria paciente*/
Paciente* cria_paciente(char nome, int idade, char situacao_saude);
void coletar_dados_paciente(Paciente* paciente);
/*Funcao que adiciona paciente de forma ordenada na lista*/
Paciente* adicionar_paciente_ordenado(Paciente*lista, Paciente*paciente);
#endif