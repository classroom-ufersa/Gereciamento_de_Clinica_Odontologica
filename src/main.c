#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/consultorio.h"
#include "../include/paciente.h"
#include "../include/funcoes.h"

int main() {
    Consultorio* lista_consultorios =NULL; 
    Lista_Atendidos* lista_atendidos = NULL;
    Paciente*lista_paciente=NULL;
    Lista_geral*lista_geral=NULL;
    char opcao;

    ler_arquivo_e_inserir_lista(&lista_consultorios,&lista_paciente, &lista_geral);
    do {
        menu();
    } while (opcao != '9');
    //Liberar memoria
    free(lista_consultorios);
    free(lista_atendidos);
    free(lista_paciente);
    free(lista_geral);
    return 0;
}
