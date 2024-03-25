#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

// Definição da estrutura do Paciente
typedef struct Paciente {
    char nome[50];
    int idade;
    char situacao_saude[100];
} Paciente;

// Definição da estrutura da Lista de Pacientes(Aqui vai ser a lista por ordem alfabetica)
typedef struct Listapaciente {
    struct Paciente *paciente;
    struct Listapaciente *proximo;
    
} Listapaciente;
typedef struct listageral{
    struct Paciente *paciente;
    struct Listageral  *prox;
}Listageral;

typedef struct listatendidos{
    Paciente *paciente;
    struct Listaatendidos*primeiro;
}Listaatendidos;

struct Paciente *coletar_Dados(void);

/*Funcao que cria e inicializa uma nova lista de pacientes*/
Listapaciente* lista_cria_paciente();

/*Funcao que adiciona um paciente a lista de pacientes
  Recebe um ponteiro para o paciente a ser adicionado e uma lista*/
Listapaciente* addPaciente(struct Paciente *paciente, Listapaciente *lista);

/*Funcao que libera espaco da memoria*/
void liberar_paciente(struct Paciente* paciente);

/*Funcao que remove o paciente de acordo com a ordem de chegada*/
void remover_paciente(Listapaciente *lista_geral, Listaatendidos *lista_atendidos);

/*Funcao que edita pacientes da lista*/
void editar_paciente(struct Listapaciente *lista);

#endif // PACIENTE_H_INCLUDED
