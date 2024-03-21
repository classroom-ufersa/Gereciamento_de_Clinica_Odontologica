#include "paciente.h"

/*Lista encadeada de pacientes, inicia com nenhum paciente na lista*/
struct Listapaciente* lista_cria() {
    return NULL;
}

/*Funcao que insere paciente de forma ordenada*/
struct Listapaciente* insere_paciente_ordenado(struct Listapaciente* inicio, struct paciente* novo) {
    struct Listapaciente* new_node = (struct Listapaciente*)malloc(sizeof(struct Listapaciente));
    if (new_node == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    new_node->paciente = novo;

    if (inicio == NULL || strcmp(novo->nome, inicio->paciente->nome) < 0) {
        new_node->next = inicio;
        return new_node;
    }

    struct Listapaciente* atual = inicio;
    while (atual->next != NULL && strcmp(novo->nome, atual->next->paciente->nome) >= 0) {
        atual = atual->next;
    }
    new_node->next = atual->next;
    atual->next = new_node;

    return inicio;
}

/*Funcao que coleta os dados dos pacientes*/
struct Paciente* coletar_dados_paciente() {
    struct paciente* novo_paciente = (struct paciente*)malloc(sizeof(struct paciente));
    if (novo_paciente == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", novo_paciente->nome);

    printf("Digite a idade do paciente: ");
    scanf("%d", &novo_paciente->idade);

    printf("Qual a situacao da saude?\n");
    scanf(" %[^\n]", novo_paciente->situacao_saude);

    printf("Digite o nome do consultorio que esse paciente: ");
    scanf(" %[^\n]", novo_paciente->nomeconsultorio);

    novo_paciente->proximo = NULL;
    novo_paciente->consultorio = NULL;

    return novo_paciente;
}

/*Busca o paciente por meio do seu nome*/
struct Paciente* buscarpornome(struct Listapaciente* listapaciente) {
    char nomeprocurar[80];
    printf("Digite o nome que deseja buscar:\n");
    scanf(" %[^\n]", nomeprocurar);

    struct Listapaciente* variaveltemp = listapaciente;
    while (variaveltemp != NULL) {
        if (strcmp(variaveltemp->paciente->nome, nomeprocurar) == 0) {
            return variaveltemp->paciente;
        }
        variaveltemp = variaveltemp->next;
    }
    printf("Desculpe, nao conseguimos encontrar esse nome.\n");

    return NULL;
}

void remover_paciente_por_nome(struct Listapaciente* listapaciente) {
    char nomeremover[200];
    printf("Digite o nome do paciente que deseja remover:\n");
    scanf(" %[^\n]", nomeremover);

    struct Listapaciente* atual = *listapaciente;
    struct Listapaciente* anterior = NULL;

    while (atual != NULL && strcmp(atual->paciente->nome, nomeremover) != 0) {
        anterior = atual;
        atual = atual->next;
    }

    if (atual == NULL) {
        printf("Paciente nao encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *listapaciente = atual->next;
    } else {
        anterior->next = atual->next;
    }

    free(atual->paciente);
    free(atual);
}

void editar_paciente(struct Listapaciente* listapaciente) {
    char nomeeditar[500];
    printf("Digite o nome do Paciente que deseja editar os dados:\n");
    scanf(" %[^\n]", nomeeditar);
    struct Listapaciente* atual = listapaciente;

    while (atual != NULL && strcmp(atual->paciente->nome, nomeeditar) != 0) {
        atual = atual->next;
    }

    if (atual == NULL) {
        printf("Paciente nao encontrado.\n");
        return;
    } else {
        char novonome[500];
        int novaidade;
        char newsituacao_saude[500];
        printf("Digite o novo nome do paciente;\n");
        scanf(" %[^\n]", novonome);
        printf("Digite a nova idade:\n");
        scanf("%d", &novaidade);
        printf("Digite a nova situacao de saude:\n");
        scanf(" %[^\n]", newsituacao_saude);
        strcpy(atual->paciente->nome, novonome);
        atual->paciente->idade = novaidade;
        strcpy(atual->paciente->situacao_saude, newsituacao_saude);
    }
}


void escrever_pacientes(struct Listapaciente* listapaciente) {
    
}

void ler_pacientes(struct Listapaciente* listapaciente) {
    
}

void pacientes_atendidos(struct Listapaciente*listapaciente){
    
}
