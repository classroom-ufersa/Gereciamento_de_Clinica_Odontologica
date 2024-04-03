#ifndef CONSULTORIO_H
#define CONSULTORIO_H
#include"paciente.h"

typedef struct Consultorio {
    int identificacao;
    char especialidade[400];
    char equipamentos_disponiveis[100];
    struct Paciente* paciente;
    struct Consultorio* proximo;
    struct Lista_geral* listageral;
} Consultorio; 



/*Funcao que ler arquivos que estavm guardados em um arquivo de texto e insere na lista, antes de carregar o menu*/
void ler_arquivo_e_inserir_lista(Consultorio **comeco,  struct Paciente **pacientes);
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



/*Funcao que verifica se o id digitado existe,
  Recebe como parametro a lista de consultorio e o id*/
int verificar_id_existente(Consultorio* lista_consultorios, int id);

/*Funcao que verifica a autenticidade do digito unico,
  Recebe como parametros a lista de pacientes e o digito unico*/
int verificar_autenticidade_digito_unico(Consultorio* lista_pacientes, int digito_unico);

/*Funcao que exibe os consultorios disponiveis,
  Recebe como parametro uma lista*/
void imprimir_consultorios_Disponiveis(Consultorio* lista);

/**/
void salvar_consultorios_e_pacientes_em_arquivo(Consultorio* lista_consultorios);



/**/
//void arquivo_para_consultorios(Consultorio*lista_completa);

#endif /* CONSULTORIO_H */
