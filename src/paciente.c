#include "paciente.h"



struct Listapaciente* lista_cria() {
    return NULL;
}

struct Listapaciente* insere_paciente_ordenado(struct Listapaciente* inicio, struct Paciente* novo) {
    struct Listapaciente* novo_no = (struct Listapaciente*)malloc(sizeof(struct Listapaciente));
    if (novo_no == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    novo_no->paciente = novo;//variavel criada para fazer comparacao
    if (inicio == NULL || strcmp(novo->nome, inicio->paciente->nome) < 0) {
        novo_no->next = inicio;
        return novo_no;
    }

    Listapaciente* atual = inicio;
    while (atual->next != NULL && strcmp(novo->nome, atual->next->paciente->nome) >= 0) {
        atual = atual->next;
    }
    novo_no->next = atual->next;
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
    //leticia, lembrar de colocar o while aqui para percorrer a  lista de consultorio; e em todas as funcoes que conter buscar
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

void remover_paciente(struct Listapaciente* listapaciente, struct Pacientes_atendidos*listaatendidos;) { //remove apenas o primeiro ciente  da lista
 if (listapaciente==NULL)
   {
       printf("Lista Vazia:\n");
     return 0;
   }
   struct ListaPaciente* lista_atual= *listapaciente;
   *listapaciente= (*listapaciente)->proximo;
   struct Pacientes_atendidos*listaatendidos= *lista_atual
   //aqui a gente pode abrir um arquivo de texto ou adicionar esse paciente a outra lista :)
   free(lista_atual);
}





void editar_paciente(struct Listapaciente* listapaciente, char nome, int idade, char situacao_saude) {
   
        char novo_nome[500];
        int nova_idade;
        char nova_situacao_saude[500];
        
        
        printf("Digite o novo nome do paciente;\n");
        scanf(" %[^\n]", novo_nome);


        printf("Digite a nova idade:\n");
        scanf("%d", &nova_idade);


        printf("Digite a nova situacao de saude:\n");

        scanf(" %[^\n]", nova_situacao_saude);

      strcpy(atual->paciente->nome, novo_nome);
        atual->paciente->idade = nova_idade;
        strcpy(atual->paciente->situacao_saude, nova_situacao_saude);
    }
}

void escrever_pacientes(struct Listapaciente* listapaciente) {}

void ler_pacientes(struct Listapaciente* listapaciente) {}
void pacientes_atendidos(struct Listapaciente*listapaciente){}
 



    
}

void pacientes_atendidos(struct Listapaciente*listapaciente){
    
}
