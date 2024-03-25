#include <stdio.h>
#include <stdlib.h>
#include "consultorio.h"
#include"paciente.h"

//lembrar  de adicionar as funcoes de tratamento de dados;
//talvez criar uma pasta para isso;
Lista_geral* adicionar_paciente_geral(Lista_geral* lista_geral, Paciente* novo_paciente) {
    Lista_geral* novo_item = (Lista_geral*)malloc(sizeof(Lista_geral));
    if (novo_item == NULL) {
        printf("Erro na alocacao, tente novamente;");
        exit(1);
    }

    novo_item->paciente_geral = novo_paciente;
    novo_item->proximo = NULL;

    if (lista_geral == NULL) {
        return novo_item;
    }

    Lista_geral* atual = lista_geral;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = novo_item;
    return lista_geral;
}


Consultorio* adicionar_consultorio(Consultorio* lista_consultorios) {
    Consultorio* novo_consultorio = (Consultorio*)malloc(sizeof(Consultorio));
    if (novo_consultorio == NULL) {
        printf("Erro ao alocar memoria para o novo consultorio\n");
        exit(1);
    }

    Consultorio *anterior = NULL;
    Consultorio* var = lista_consultorios;

    while (var != NULL && var->identificacao < novo_consultorio->identificacao) {
        anterior = var;
        var = var->proximo;
    }

    novo_consultorio->paciente = NULL;

    char escolha;
    printf("Deseja adicionar pacientes a esse consultorio (S/N)?\n");
    scanf("%c", &escolha);
  do {
        char nome_paciente[100];
        int idade_paciente;
        char situacao_saude_paciente[100];

        printf("Digite o nome do paciente: ");
        if (scanf(" %[^\n]", nome_paciente) != 1) {
            printf("Erro ao ler o nome do paciente.\n");
            return 1;
        }

        printf("Digite a idade do paciente: ");
        if (scanf("%d", &idade_paciente) != 1) {
            printf("Erro ao ler a idade do paciente.\n");
            return 1;
        }

        printf("Digite a situacao de saude do paciente: ");
        if (scanf(" %[^\n]", situacao_saude_paciente) != 1) {
            printf("Erro ao ler a situação de saúde do paciente.\n");
            return 1;
        }

        
        printf("Paciente adicionado com sucesso.\n");

        
        char continuar;
        printf("Deseja adicionar outro paciente? (s/n): ");
        scanf(" %c", &continuar);
        if (continuar != 's' && continuar != 'S') {
            break;
        }
    } while (1);   
   
   
    
    if (anterior == NULL) {
        novo_consultorio->proximo = lista_consultorios;
        return novo_consultorio;
    } else {
        anterior->proximo = novo_consultorio;
        novo_consultorio->proximo = var;
        return lista_consultorios;
    }
}
/*void remover_consultorio(Consultorio*lista){
    int id_remover;
    printf("Digite o id que deseja remover:\n");
    scanf("%d", &id_remover);
    Consultorio*lista_procurar= lista;
    int i;
    for (lista=0;lista!=NULL; lista->proximo)
    {
       if (id_remover==lista->identificacao)
       {
        
       }
        
    }
    
    
    
    while(lista!=NULL){
       if (lista!=NULL && id_remover==lista->identificacao) {
         
       
       }
       
    }
}*/