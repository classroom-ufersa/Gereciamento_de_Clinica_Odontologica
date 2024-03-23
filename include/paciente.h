#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

// Definição da estrutura do Paciente
typedef struct Paciente {
    char nome[50];
    int idade;
    char situacao_saude[100];
} Paciente;

// Definição da estrutura da Lista de Pacientes
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

Listapaciente* lista_cria_paciente();
Listapaciente* addPaciente(struct Paciente *paciente, Listapaciente *lista);
struct Paciente *coletar_Dados(void);
void liberar_paciente(struct Paciente* paciente);
void remover_paciente(Listapaciente *lista_geral, Listaatendidos *lista_atendidos) 
 editar_paciente(struct Listapaciente *lista);

#endif // PACIENTE_H_INCLUDED





