int verificar_id_existente(Consultorio* lista_consultorios, int id);
int verificar_autenticidade_digito_unico(Consultorio* lista_pacientes, int digito_unico);
void imprimir_consultorios_Disponiveis(Consultorio* lista);
void salvar_consultorios_e_pacientes_em_arquivo(Consultorio* lista_consultorios);
void editar_paciente(Consultorio* lista, char* nome_editar, int dg_procurar);
void arquivo_para_consultorios(Consultorio*lista_completa);

#endif /* CONSULTORIO_H */


/**/
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

/*Funncao que salva o consultorio no arquivo de texto,
  Recebe como parametro um ponteiro para consultorios*/
void salvar_consultorios_em_arquivo(Consultorio* lista_consultorios); 


#endif /* CONSULTORIO_H */
