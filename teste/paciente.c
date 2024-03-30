#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "consultorio.h"
void coletar_dados_paciente(Paciente* paciente, struct Consultorio* lista) {
    char idade_var_string[50];
    char digito_unico_string[100];
    Consultorio* lista_pacientes = lista;
    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", paciente->nome);
    tratamento_de_palavras(paciente->nome);
    string_maiuscula_minuscula(paciente->nome);
    getchar();

    printf("Digite a idade do paciente: ");
    scanf(" %[^\n]", idade_var_string);

    tratamento_de_numero(idade_var_string);
    paciente->idade = atoi(idade_var_string);

    printf("Digite a situacao da saude do paciente: ");
    scanf(" %[^\n]", paciente->situacao_saude);
    tratamento_de_palavras(paciente->situacao_saude);

    while (1) {
        printf("Digite o digito unico desse paciente:\n");
        scanf(" %[^\n]", digito_unico_string);
        tratamento_de_numero(digito_unico_string);
        paciente->digito_unico = atoi(digito_unico_string);
        if (verificar_autenticidade(lista_pacientes, paciente->digito_unico) == 1) {
            printf("Um paciente ja possui esse digito, informe outro.\n");
        } else {
            break;
        }
    }
}

Paciente* cria_paciente(char* nome, int idade, char* situacao_saude, int dg) {
    Paciente* novo_paciente = (Paciente*)malloc(sizeof(Paciente));
    if (novo_paciente == NULL) {
        printf("Erro na alocacao, tente novamente;");
        exit(1);
    }

    strcpy(novo_paciente->nome, nome);
    novo_paciente->idade = idade;
    strcpy(novo_paciente->situacao_saude, situacao_saude);
    novo_paciente->digito_unico = dg;
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
Lista_geral* adicionar_paciente_geral(Lista_geral* lista_geral, Paciente* paciente) {
    Lista_geral* novo_paciente_geral = (Lista_geral*)malloc(sizeof(Lista_geral));
    if (novo_paciente_geral == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }
    novo_paciente_geral->paciente_geral = paciente;

    novo_paciente_geral->proximo = lista_geral;
    return novo_paciente_geral;
}




void tratamento_de_numero(char *variavel_num)
{
  int Contador, Contador2;
  for (Contador = 0; variavel_num[Contador] != '\0'; Contador++)
  {
    if (variavel_num[Contador] < 48 || variavel_num[Contador] > 57)
    {
      for (Contador2 = Contador; variavel_num[Contador2] != '\0'; Contador2++)
      {
        variavel_num[Contador2] = variavel_num[Contador2 + 1];
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
void imprimir_atendidos(Lista_Atendidos* lista) {
    if (lista == NULL) {
        printf("Nenhum paciente foi atendido ainda, lista esta vazia\n");
        return;
    }

    while (lista != NULL) {
        printf("Nome do paciente: %s\n", lista->paciente_atendido->nome);
        printf("Idade do paciente: %d\n", lista->paciente_atendido->idade);
        printf("Situacao de saude do paciente: %s\n", lista->paciente_atendido->situacao_saude);
        lista = lista->proximo;
    }
}

void arquivo_atendidos(Lista_Atendidos*lista){
  FILE*atendidos;
  Lista_Atendidos*lista_completa=lista;
  int cont=0;
    atendidos = fopen("lista_atendidos.txt", "w+"); 
    if (atendidos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
  while (lista_completa!=NULL)
  { 
    fprintf(atendidos, "===LISTA DE PACIENTES ATENDIDOS:===\n");
    fprintf(atendidos, "Paciente:%d\n", cont+1);
    fprintf(atendidos, "Nome: %s\n", lista_completa->paciente_atendido->nome);
    fprintf(atendidos,"Idade: %d\n", lista_completa->paciente_atendido->idade);
    fprintf(atendidos, "Situacao de saude: %s\n", lista_completa->paciente_atendido->situacao_saude);
    fprintf(atendidos, "Digito Unico: %d\n", lista_completa->paciente_atendido->digito_unico);
    lista_completa=lista_completa->proximo;
  }
  fclose(atendidos);
}
void remover_paciente_por_fila(Lista_geral **lista, Lista_Atendidos **lista_atendidos) {
    if (*lista == NULL) {
        printf("Lista geral esta vazia\n");
        return;
    }

    Lista_geral *removido = *lista;
    *lista = (*lista)->proximo;

    
    Lista_Atendidos *novo_atendimento = (Lista_Atendidos *)malloc(sizeof(Lista_Atendidos));
    if (novo_atendimento == NULL) {
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }

    novo_atendimento->paciente_atendido = removido->paciente_geral;
    novo_atendimento->proximo = *lista_atendidos;
    *lista_atendidos = novo_atendimento;

    free(removido); 
    printf("Paciente removido com sucessp\n");
}
 Paciente* buscar_paciente_por_nome(struct Consultorio* lista_consultorios, char* nome, int digitoUnico) {
    Consultorio* consultorio_atual = lista_consultorios;
    while (consultorio_atual != NULL) {
        Paciente* paciente_atual = consultorio_atual->paciente;
        while (paciente_atual != NULL) {
            if (strcmp(paciente_atual->nome, nome) == 0 && paciente_atual->digito_unico == digitoUnico) {
                printf("Paciente encontrado:\n");
                printf("Nome: %s, Idade: %d, Situacao Saude: %s\n", paciente_atual->nome, paciente_atual->idade, paciente_atual->situacao_saude);
                return paciente_atual; 
            }
            paciente_atual = paciente_atual->proximo;
        }
        consultorio_atual = consultorio_atual->proximo;
    }
    printf("Paciente nao encontrado\n");
    return NULL;
}
void imprimir_gerais(Lista_geral* lista) {
    if (lista == NULL) {
        printf("LISTA GERAL ESTA VAZIA, TESTE\n");
        return;
    }

    while (lista != NULL) {
        printf("nome: %s\n", lista->paciente_geral->nome);
        printf("Idade: %d\n", lista->paciente_geral->idade);
        lista = lista->proximo;
    }
}

void adicionar_paciente_por_id(struct Consultorio* lista_consultorios,  Lista_geral** lista_geral) {
    int id_procurar;
    char id_var[100];
    printf("Digite a identificacao do consultorio que esse paciente vai pertencer: ");
    scanf(" %[^\n]", id_var);

    tratamento_de_numero(id_var);
    id_procurar = atoi(id_var);

    if (verificar_lista(lista_consultorios) == 1) {
        printf("Lista de consultorios esta vazia\n");
        return;
    }

    Consultorio* consultorio_atual = lista_consultorios;
    while (consultorio_atual != NULL) {
        if (consultorio_atual->identificacao == id_procurar) {
            Paciente* novo_paciente = (Paciente*)malloc(sizeof(Paciente));
            if (novo_paciente == NULL) {
                printf("Erro na alocacao\n");
                exit(1);
            }

            coletar_dados_paciente(novo_paciente, lista_consultorios); 
            *lista_geral = adicionar_paciente_geral(*lista_geral, novo_paciente);
            consultorio_atual->paciente = adicionar_paciente_ordenado(consultorio_atual->paciente, novo_paciente);
            return;
        }
        consultorio_atual = consultorio_atual->proximo;
    }

    printf("Consultorio nao encontrado\n");
}
