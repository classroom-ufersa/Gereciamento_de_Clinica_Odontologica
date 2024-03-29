#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "consultorio.h"


void coletar_dados_paciente(Paciente* paciente) {
    char idade_var[50];
    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", paciente->nome);
    tratamento_de_palavras(paciente->nome);
     string_maiuscula_minuscula(paciente->nome);
     getchar();

 
    printf("Digite a idade do paciente: ");
    scanf(" %[^\n]", idade_var);

    tratamento_de_numero(idade_var);
    paciente->idade = atoi(idade_var);

    printf("Digite a situacao da saude do paciente: ");
    scanf(" %[^\n]", paciente->situacao_saude);
    tratamento_de_palavras(paciente->situacao_saude);
}


Paciente* cria_paciente(char* nome, int idade, char* situacao_saude) {
    Paciente* novo_paciente = (Paciente*)malloc(sizeof(Paciente));
    if (novo_paciente == NULL) {
        printf("Erro na alocacao, tente novamente;");
        exit(1);
    }

    strcpy(novo_paciente->nome, nome);
    novo_paciente->idade=idade;
    strcpy(novo_paciente->situacao_saude, situacao_saude);
    novo_paciente->proximo = NULL;
    return novo_paciente;
}


Paciente* adicionar_paciente_ordenado(Paciente* lista, Paciente* novo_paciente) {
    if (lista == NULL || novo_paciente == NULL || strcmp(novo_paciente->nome, lista->nome) < 0) {
        novo_paciente->proximo = lista;
        return novo_paciente;
    }

    Paciente* anterior = lista;
    Paciente* atual = lista->proximo;

    while (atual != NULL && strcmp(novo_paciente->nome, atual->nome) > 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = novo_paciente;
    novo_paciente->proximo = atual;

    return lista;
}


   Lista_geral* adicionar_paciente_geral(Lista_geral* lista_geral) {
    Lista_geral* novo_paciente_geral = (Lista_geral*)malloc(sizeof(Lista_geral));
    if (novo_paciente_geral == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }
;

    novo_paciente_geral->proximo = lista_geral; 
    return novo_paciente_geral; 
}

void tratamento_de_numero(char *variavelid)
{
  int Contador, Contador2;
  for (Contador = 0; variavelid[Contador] != '\0'; Contador++)
  {
    if (variavelid[Contador] < 48 || variavelid[Contador] > 57)
    {
      for (Contador2 = Contador; variavelid[Contador2] != '\0'; Contador2++)
      {
        variavelid[Contador2] = variavelid[Contador2 + 1];
      }
      Contador--;
    }
  }
}


void tratamento_de_palavras(char *palavra_var){
  int Contador, Contador2; 
  for (Contador = 0; palavra_var[Contador] != '\0'; Contador++)  {
    if((palavra_var[Contador] < 65 || palavra_var[Contador] > 90) && (palavra_var[Contador] < 97 || palavra_var[Contador] > 122) && (palavra_var[Contador] != 32)){
       for(Contador2 = Contador;palavra_var[Contador2] != '\0';Contador2++){
        palavra_var[Contador2] = palavra_var[Contador2 + 1];
       }
       Contador--;
    }
  }
}

void string_maiuscula_minuscula(char *palavra_var){ 
  int Contador; 
  palavra_var[0] = toupper(palavra_var[0]);  
  for (Contador = 1; palavra_var[Contador] != '\0'; Contador++)  { 
    if (isspace(palavra_var[Contador - 1]))  { 
      palavra_var[Contador] = toupper(palavra_var[Contador]);
    } else  { 
      palavra_var[Contador] = tolower(palavra_var[Contador]); 
    }
  }
}
