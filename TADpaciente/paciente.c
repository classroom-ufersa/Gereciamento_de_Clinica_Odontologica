#include "paciente.h"


struct Listapaciente* lista_cria() {
    return NULL;
}

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

    Listapaciente* atual = inicio;
    while (atual->next != NULL && strcmp(novo->nome, atual->next->paciente->nome) >= 0) {
        atual = atual->next;
    }
    new_node->next = atual->next;
    atual->next = new_node;

    return inicio;
}
void verificar_lista_vazia(Listapaciente*lista_paciente_var){
    if (lista_paciente_var==NULL){
        return ;
    }
    return ;
}

struct Paciente* coletar_dados_paciente() {//essa funcao deve ser chamada na main depois.
    struct Paciente* novo_paciente = (struct Paciente*)malloc(sizeof(struct Paciente));
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


    novo_paciente->proximo = NULL;
    return novo_paciente;
}

struct Paciente* buscarpornome(struct Listapaciente* listapaciente) {
    char nomeprocurar[80];
    //lembrar de colocar o while aqui para percorrer a  lista de consultorio; e em todas as funcoes que conter buscar
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

Listaconsultorio= buscar_por_consultorios(Listaconsultorio );
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

void escrever_pacientes(struct Listapaciente* listapaciente) {}

void ler_pacientes(struct Listapaciente* listapaciente) {}
void pacientes_atendidos(struct Listapaciente*listapaciente){}
 

    

