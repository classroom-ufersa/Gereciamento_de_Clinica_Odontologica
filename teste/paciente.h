#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct Paciente {
    char nome[100];
    int idade;
    char situacao_saude[100];
    struct Paciente* proximo;
}Paciente;

typedef struct ListaPaciente {
    struct Paciente* paciente;
    struct ListaPaciente* proximo;
}ListaPaciente;
struct Paciente* coletar_dados_paciente();
struct ListaPaciente* inserir_paciente_ordenado(struct ListaPaciente* lista_pacientes, struct Paciente*novo_paciente);
void buscar_por_nome_paciente(struct ListaPaciente* lista);
#endif