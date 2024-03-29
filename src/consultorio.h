#ifndef CONSULTORIO_H
#define CONSULTORIO_H
#include"paciente.h"

typedef struct consultorio {
    int identificacao;
    char especialidade[400];
    char equipamentos_disponiveis[100];

    struct Paciente* paciente;
    struct Consultorio* proximo;
    struct Lista_geral* listageral;
} Consultorio; 

/*Funcao que verifica se a lista esta vazia,
  Recebe como parametros um ponteiro de consultorio*/
int verificar_lista(Consultorio*consultorio_aux);

/*Funcao que adiciona um consultorio a lista de consultorios,
  Recebe como parametros um ponteiro de consultorio*/
Consultorio* adicionar_consultorio(Consultorio* lista_consultorios);

/*Funcao que remove um consultorio pelo ID informado,
  Recebe como parametro um ponteiro de consultorio*/
Consultorio* remover_consultorio_por_id(Consultorio* lista_consultorios);

/*Funcao que imprime os consultorios disponiveis,
  Recebe como parametro um ponteiro de consultorio*/
void imprimir_consultorios_Disponiveis(Consultorio* lista);

/*Funcao que adiciona um paciente ao consultorio informado, 
  Recebe como parametro um ponteiro de consultorio*/
void adicionar_paciente_por_id(Consultorio *lista_consultorios);

/*Funcao que busca o paciente pelo nome, 
  Recebe como parametros um ponteiro de consultorio e o nome*/
Consultorio* buscar_paciente_por_nome(Consultorio* lista_consultorios, char* nome);

/*Funncao que salva o consultorio no arquivo de texto,
  Recebe como parametro um ponteiro para consultorios*/
void salvar_consultorios_em_arquivo(Consultorio* lista_consultorios);

/*Funcao que edita os dados do paciente existente na lista,
  Recebe com parametros um ponteiro de consultorio e o nome do paciente para editar*/
Consultorio* editar_paciente(Consultorio* lista, char* nome_editar);

#endif /* CONSULTORIO_H */
