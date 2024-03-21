#include "configuracoes.h"
#include "consultorio.h"
#include "paciente.h"
struct consultorio {
    int identificacao;
    char especialidade[50];
    char equipamentos_disponiveis[50];
     struct Listapacientes*pac;
    
};

struct listaconsultorio {
    struct next_consultorio;
    struct Listapaciente* next;
};

struct Listaconsultorio* lista_cria() {
    return NULL;
}

struct Listaconsultorio* listaconsultorio(Consultorio* consultorio, Listaconsultorio* Listaconsultorio) {
    struct Listaconsultorio* novo = (Listaconsultorio*)malloc(sizeof(Listaconsultorio));
    if (novo == NULL) {
        printf("Erro na alocacao \n");
        exit(1);
    }
    novo->consultorio = consultorio;
    novo->next = Listaconsultorio;
    return novo;
}

struct Consultorio* inserir_ordenado( Consultorio* inicio, Consultorio* novo) {
    if (inicio == NULL || (novo->identificacao, inicio->identificacao) < 0) {
        novo->proximo = inicio;
        return novo;
    }
    struct Consultorio* atual = inicio;
    while (atual->proximo != NULL && (novo->identificacao, atual->proximo->identificacao) >= 0) {
        atual = atual->proximo;
    } //mudar depois porque tem que ser ordenado por id nao por nome.
    novo->proximo = atual->proximo;
    atual->proximo = novo;
    return inicio;
}

struct Listaconsultorio* coletar_dados_consultorio() {

    printf("Digite a identificacao do consultorio: ");
    scanf("%d", &novo_consultorio->identificacao);

    printf("Digite a especialidade do consultorio: ");
    scanf("%s", novo_consultorio->especialidade);

    printf("Digite os equipamentos disponiveis: \n");
    scanf("%[^\n]" novo_consultorio->equipamentos_disponiveis);
    }

void escrever_consultorio(Listaconsultorio *listaconsultorio) {
    
}
   
void ler_consultorio(Listaconsultorio *listaconsultorio){

}

void remover_consultorio( Listaconsultorio *listaconsultorio) {
    char nomeremover[200];
    printf("Digite o nome do consultorio que deseja remover:\n");
    scanf(" %[^\n]", nomeremover);

    struct Listapaciente* atual = *listapaciente;
    struct Listapaciente* anterior = NULL;

    while (atual != NULL && strcmp(atual->paciente->identificacao, nomeremover) != 0) {
        anterior = atual;
        atual = atual->next;
    }

    if (atual == NULL) {
        printf("Consultorio nao encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *listaconsultorio = atual->next;
    } else {
        anterior->next = atual->next;
    }

    free(atual->consultorio);
    free(atual);
}

Consultorio adicionar_consultorio(Consultorio *c){

}
void verificar_lista_vazia(Listaconsultorio *lista_consultorio){
    if(lista_consultorio==NULL){
    return 1;}
return 0;
}
void remover_consultorio(Consultorio *c){
  
}
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
