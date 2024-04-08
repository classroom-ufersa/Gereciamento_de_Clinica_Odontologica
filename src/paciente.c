#include "../include/consultorio.h"
#include "../include/paciente.h"
#include "../include/funcoes.h"

void coletar_dados_paciente(Paciente* paciente, struct Consultorio* lista) {
    char idade_var_string[50];
    char digito_unico_string[100];
    Consultorio* lista_pacientes = lista;
    do {
    
        printf("Digite o nome do paciente: ");
        scanf(" %[^\n]", paciente->nome);
        tratamento_de_palavras(paciente->nome);
        string_maiuscula_minuscula(paciente->nome);
        getchar();
    }
     while (paciente->nome[0] == '\0');

    do {
        printf("Digite a idade do paciente: ");
        scanf(" %[^\n]", idade_var_string);
        tratamento_de_numero(idade_var_string);
        paciente->idade = atoi(idade_var_string);
    } while (paciente->idade == 0);

    do {
        printf("Digite a situacao da saude do paciente: ");
        scanf(" %[^\n]", paciente->situacao_saude);
        tratamento_de_palavras(paciente->situacao_saude);
    } while (paciente->situacao_saude[0] == '\0');


while (1) {
    printf("Lembre-se, o digito unico nao podera ser editado depois\n");
    printf("Digite o digito unico desse paciente:\n");
    scanf(" %[^\n]", digito_unico_string);
    tratamento_de_numero(digito_unico_string);
    paciente->digito_unico = atoi(digito_unico_string);

    if (verificar_autenticidade(lista_pacientes, paciente->digito_unico) == 1 || paciente->digito_unico == 0) {
        if (verificar_autenticidade(lista_pacientes, paciente->digito_unico) == 1) {
            printf("Algum paciente ja possui esse digito unico, informe outro\n"); 
        }
        if (paciente->digito_unico == 0) {
            printf("O campo nao pode estar vazio.\n");
        }
    } else {
        break;
    }
}
}

Paciente* cria_paciente(char* nome, int idade, char* situacao_saude) {
    Paciente* novo_paciente = (Paciente*)malloc(sizeof(Paciente));
    if (novo_paciente == NULL) {
        printf("Erro na alocacao.\n");
        exit(1);
    }

    strcpy(novo_paciente->nome, nome);
    novo_paciente->idade = idade;
    strcpy(novo_paciente->situacao_saude, situacao_saude);
    novo_paciente->proximo = NULL;
    return novo_paciente;
}

Paciente* adicionar_paciente_ordenado(Paciente* lista, Paciente* novo_paciente) {
    if (lista == NULL || strcmp(lista->nome, novo_paciente->nome) > 0) {
        novo_paciente->proximo = lista;
        return novo_paciente;
    }

    Paciente* atual = lista;
    while (atual->proximo != NULL && strcmp(atual->proximo->nome, novo_paciente->nome) < 0) {
        atual = atual->proximo;
    }

    novo_paciente->proximo = atual->proximo;
    atual->proximo = novo_paciente;
    return lista;
}

Lista_geral* adicionar_paciente_geral(Lista_geral* lista_geral, Paciente* paciente) {
    Lista_geral* novo_paciente_geral = (Lista_geral*)malloc(sizeof(Lista_geral));
    if (novo_paciente_geral == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }
    novo_paciente_geral->paciente_geral = paciente;
    novo_paciente_geral->proximo = NULL; 

    
    if (lista_geral == NULL) {
        return novo_paciente_geral;
    }
    
    Lista_geral* atual = lista_geral;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
     
     atual->proximo = novo_paciente_geral;
     return lista_geral;
}

void imprimir_atendidos(Lista_Atendidos* lista) {
    if (lista == NULL) {
        printf("Nenhum paciente foi atendido ainda, lista esta vazia. \n");
        return;
    }
printf("***===Lista de Pacientes atendidos===***\n");
    while (lista != NULL) {
        printf("Nome do paciente: %s\n", lista->paciente_atendido->nome);
        printf("Idade do paciente: %d\n", lista->paciente_atendido->idade);
        printf("Situacao de saude do paciente: %s\n \n", lista->paciente_atendido->situacao_saude);
        printf("Digito Unico do paciente: %d\n", lista->paciente_atendido->digito_unico);
        lista = lista->proximo;
    }
}

void arquivo_atendidos(Lista_Atendidos*lista){
    FILE*atendidos;
    Lista_Atendidos*lista_completa=lista;
    atendidos = fopen("lista_atendidos.txt", "w+"); 
    if (atendidos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    fprintf(atendidos, "====Banco de dados dos pacientes atendidos.=====\n");
    while (lista_completa!=NULL) { 
    fprintf(atendidos, "Paciente:\n");
    fprintf(atendidos, "Nome: %s\n", lista_completa->paciente_atendido->nome);
    fprintf(atendidos, "Idade: %d\n", lista_completa->paciente_atendido->idade);
    fprintf(atendidos, "Situacao de saude: %s\n", lista_completa->paciente_atendido->situacao_saude);
    fprintf(atendidos, "Digito Unico: %d\n", lista_completa->paciente_atendido->digito_unico);
    fprintf(atendidos, "\n");
    lista_completa=lista_completa->proximo;
    
    }
    fclose(atendidos);
}

void remover_paciente_por_fila(Lista_geral **lista, Lista_Atendidos **lista_atendidos) {
    if (*lista == NULL) {
        printf("A lista geral está vazia.\n");
        return;
    }

    Lista_geral *removido = *lista;
    *lista = (*lista)->proximo;

    Lista_Atendidos *novo_atendimento = (Lista_Atendidos *)malloc(sizeof(Lista_Atendidos));
    if (novo_atendimento == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }

    novo_atendimento->paciente_atendido = removido->paciente_geral;
    novo_atendimento->proximo = *lista_atendidos;
    *lista_atendidos = novo_atendimento;

    free(removido);
    printf("Paciente removido com sucesso.\n");
}

Paciente* buscar_paciente_por_nome(struct Consultorio* lista_consultorios, char* nome, int digitoUnico) {
    Consultorio* consultorio_atual = lista_consultorios;
    while (consultorio_atual != NULL) {
        Paciente* paciente_atual = consultorio_atual->paciente;
        while (paciente_atual != NULL) {
            if (strcmp(paciente_atual->nome, nome) == 0 && paciente_atual->digito_unico == digitoUnico) {
                printf("Paciente encontrado:\n");
                printf("\nNome: %s \n Idade: %d \n Situacao Saude: %s\n", paciente_atual->nome, paciente_atual->idade, paciente_atual->situacao_saude);
                return paciente_atual; 
            }
            paciente_atual = paciente_atual->proximo;
        }
        consultorio_atual = consultorio_atual->proximo;
    }
    printf("Paciente nao encontrado no sistema.\n");
    return NULL;
}

void imprimir_gerais(Lista_geral* lista) {
    if (lista == NULL) {
        printf("LISTA GERAL ESTA VAZIA.\n");
        return;
    }

    printf("====Lista geral:====\n");
    Lista_geral* atual = lista;
    while (atual != NULL) {
        printf("nome: %s\n", atual->paciente_geral->nome);
        printf("Idade: %d\n", atual->paciente_geral->idade);
        printf("Situacao de saude: %s\n", atual->paciente_geral->situacao_saude);
        printf("Digito unico: %d\n", atual->paciente_geral->digito_unico);
        atual = atual->proximo;
    }
}

void adicionar_paciente_por_id(struct Consultorio* lista_consultorios,  Lista_geral** lista_geral) {
    int id_procurar;
    char id_var[100];
    printf("\n Digite a identificacao do consultorio que esse paciente vai pertencer: ");
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
                printf("Erro na alocacao.\n");
                exit(1);
            }
            coletar_dados_paciente(novo_paciente, lista_consultorios); 
            *lista_geral = adicionar_paciente_geral(*lista_geral, novo_paciente);
            consultorio_atual->paciente = adicionar_paciente_ordenado(consultorio_atual->paciente, novo_paciente);
            return;
        }
        consultorio_atual = consultorio_atual->proximo;
    }
    printf("Consultorio nao encontrado. \n");
}

void remover_paciente_para_inserir(struct Consultorio* lista, char* nome_remover, int dg_remover) {
    if (verificar_lista(lista) == 1) {
        printf("Lista esta vazia.\n");
        return;
    }
    Consultorio* consultorio_atual = lista;

    while (consultorio_atual != NULL) {
        Paciente* paciente_atual = consultorio_atual->paciente;
        Paciente* paciente_anterior_ao_atual = NULL;

        while (paciente_atual != NULL) {
            if (strcmp(paciente_atual->nome, nome_remover) == 0 && paciente_atual->digito_unico == dg_remover) {
                if (paciente_anterior_ao_atual== NULL) {
                    consultorio_atual->paciente = paciente_atual->proximo;
                } else {
                    paciente_anterior_ao_atual->proximo = paciente_atual->proximo;
                }
                free(paciente_atual);
                return;
            }
            paciente_anterior_ao_atual = paciente_atual;
            paciente_atual = paciente_atual->proximo;
        }

        consultorio_atual = consultorio_atual->proximo;
    }

    printf("Paciente nao encontrado.\n");
    return;
}

void liberar_atendidos_lista(Lista_Atendidos*lista_atendidos){
    Lista_Atendidos*aux_var;
    while (lista_atendidos!= NULL) {
        aux_var = lista_atendidos;
        lista_atendidos =lista_atendidos->proximo;
        free(aux_var);
    }
}

void liberar_lista_geral(Lista_geral*lista_geral){
    Lista_geral*aux_var;
    while (lista_geral != NULL) {
        aux_var = lista_geral;
        lista_geral =lista_geral->proximo;
        free(aux_var);
    }
}

void editar_paciente(struct Consultorio* lista, char* nome_editar, int dg_procurar) {
    char opcao;
    if (verificar_lista(lista) == 1) {
        printf("Lista de consultorios esta vazia\n");
        return;
    }
    int paciente_encontrado = 0;
    Consultorio* consultorio_paciente = NULL;
    Consultorio* consultorio_atual = lista;
    
    while (consultorio_atual != NULL) {
        Paciente* paciente_atual = consultorio_atual->paciente;
        while (paciente_atual != NULL) {
            if (strcmp(paciente_atual->nome, nome_editar) == 0 && paciente_atual->digito_unico == dg_procurar) {
                paciente_encontrado = 1;
                consultorio_paciente = consultorio_atual; 
                break;
            }
            paciente_atual = paciente_atual->proximo;
        }
        if (paciente_encontrado) {
            break; 
        }
        consultorio_atual = consultorio_atual->proximo;
    }

    if (!paciente_encontrado) {
        printf("Paciente nao encontrado.\n");
        return;
    }

    char novo_nome[100];
    int nova_idade;
    char nova_situacao[100];
    //int novo_digito;
        
    printf("Edicao de dados do paciente:\n");
    remover_paciente_para_inserir(consultorio_paciente, nome_editar, dg_procurar); 

    char idade_var[100];
do
{
    printf("Digite o novo nome do paciente:\n");
    scanf(" %[^\n]", novo_nome);
    tratamento_de_palavras(novo_nome);
    string_maiuscula_minuscula(novo_nome);
}while (novo_nome[0]=='\0');

do
{
    printf("Digite a nova idade do paciente:\n ");
    scanf(" %[^\n]", idade_var);
    tratamento_de_numero(idade_var);
    nova_idade = atoi(idade_var);
}while (nova_idade==0);
    
do{
    printf("Digite a nova situacao de saude:\n");
    scanf(" %[^\n]", nova_situacao);
    tratamento_de_palavras(nova_situacao);
    string_maiuscula_minuscula(nova_situacao);
}while (nova_situacao[0]=='\0');

    Paciente* paciente_atualizado = cria_paciente(novo_nome, nova_idade, nova_situacao);
    consultorio_paciente->paciente = adicionar_paciente_ordenado(consultorio_paciente->paciente, paciente_atualizado); 
}
