#include "configuracoes.h"
#include "consultorio.h"
#include "paciente.h"

struct consultorio {
    int identificacao;
    char especialidade[50];
    char equipamentos_disponiveis[50];
    struct Listapacientes*pac;
}

struct listaconsultorio {
    struct next_consultorio;
    struct Listapaciente* next;
}

struct Listaconsultorio* lista_cria() {
    return NULL;
}

/*Tipo estruturado que cria e adiciona um novo consultorio a lista encadeada*/
struct Listaconsultorio* listaconsultorio(Consultorio* consultorio, Listaconsultorio* Listaconsultorio) {
    struct Listaconsultorio* novo = (Listaconsultorio*)malloc(sizeof(Listaconsultorio));
    if (novo == NULL) {
        printf("Erro na alocacao da memoria.\n");
        exit(1);
    }
    
    novo->consultorio = consultorio;
    novo->next = Listaconsultorio;
    return novo;
}

/*Tipo estruturado que insere o consultorio de forma ordenada por meio do id*/
struct Consultorio* inserir_ordenado(Consultorio* inicio, Consultorio* novo) {
    if (inicio == NULL || novo->identificacao < inicio->identificacao) {
        novo->proximo = inicio;
        return novo;
    }
    
    struct Consultorio* atual = inicio;
    while (atual->proximo != NULL && novo->identificacao >= atual->proximo->identificacao) {
        atual = atual->proximo;
    } 
    
    novo->proximo = atual->proximo;
    atual->proximo = novo;
    return inicio;
}

/*Tipo estruturado para coleta e armazenamento de dados do consultorio*/
struct Listaconsultorio* coletar_dados_consultorio() {
    
    printf("Digite a identificacao do consultorio: ");
    scanf("%d", &novo_consultorio->identificacao);

    printf("Digite a especialidade do consultorio: ");
    scanf("%s", novo_consultorio->especialidade);

    printf("Digite os equipamentos disponiveis: \n");
    scanf("%[^\n]" novo_consultorio->equipamentos_disponiveis);
}

void escrever_consultorio(Listaconsultorio *listaconsultorio) {
    //texto
}

/*Funcao que percorre a lista e imprime na tela as informações de cada consultorio*/
void ler_consultorio(Listaconsultorio *listaconsultorio) {
    struct Listaconsultorio *atual = listaconsultorio;
    
    while (atual != NULL) {
        printf("Identificacao: %d\n", atual->consultorio->identificacao);
        printf("Especialidade: %s\n", atual->consultorio->especialidade);
        printf("Equipamentos Disponiveis: %s\n", atual->consultorio->equipamentos_disponiveis);
        
        atual = atual->next;
    }
}

/*Fucao que remove consultorio a partir do seu id*/
void remover_consultorio(Listaconsultorio *listaconsultorio) {
    int id_remover;
    printf("Digite a identificacao do consultorio que deseja remover:\n");
    scanf("%d", &id_remover);

    struct Listaconsultorio *atual = listaconsultorio;
    struct Listaconsultorio *anterior = NULL;

    while (atual != NULL && atual->consultorio->identificacao != id_remover) {
        anterior = atual;
        atual = atual->next;
    }

    if (atual == NULL) {
        printf("Consultorio nao encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        listaconsultorio = atual->next;
    } else {
        anterior->next = atual->next;
    }

    free(atual->consultorio);
    free(atual);
}


Consultorio adicionar_consultorio(Consultorio *c){

}

/*Funcao que verifica se a lista esta vazia*/
void verificar_lista_vazia(Listaconsultorio *lista_consultorio){
    if(lista_consultorio==NULL){
        return 1;
    }
    return 0;
}

/*Funcao que buscar por um paciente específico dentro de uma lista de consultórios*/
void buscar_por_paciente(Listaconsultorio* lista_consultorio, char* nome_paciente) {
    if (lista_consultorio == NULL) {
        printf("Lista de consultórios vazia.\n");
        return;
    }
    Listaconsultorio* consultorio_atual = lista_consultorio;
    while (consultorio_atual != NULL) {
        Listapacientes* paciente_atual = consultorio_atual->lista_pacientes;
        while (paciente_atual != NULL) {
            if (strcmp(paciente_atual->paciente->nome, nome_paciente) == 0) {
                printf("Paciente encontrado: %s\n", paciente_atual->paciente->nome);
                return;
            }
            paciente_atual = paciente_atual->next;
        }
        consultorio_atual = consultorio_atual->next_consultorio;
    }
}
