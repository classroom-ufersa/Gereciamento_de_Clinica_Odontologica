#include "../include/consultorio.h"
#include "../include/paciente.h"
#include "../include/funcoes.h"

void salvar_consultorios_e_pacientes_em_arquivo(Consultorio* lista_consultorios) {
    FILE* arquivo = fopen("consultorios_e_pacientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        return;
    }

    Consultorio* atual = lista_consultorios;
    while (atual != NULL) {
        
        fprintf(arquivo, "CONSULTORIO:\n");
        fprintf(arquivo, "Identificacao: %d\n", atual->identificacao);
        fprintf(arquivo, "Especialidade: %s\n", atual->especialidade);
        fprintf(arquivo, "Equipamentos disponiveis: %s\n", atual->equipamentos_disponiveis);
        fprintf(arquivo, "\n");

       
        Paciente* paciente_atual = atual->paciente;
        while (paciente_atual != NULL) {
            fprintf(arquivo, "PACIENTE:\n");
            fprintf(arquivo, "Nome: %s\n", paciente_atual->nome);
            fprintf(arquivo, "Idade: %d\n", paciente_atual->idade);
            fprintf(arquivo, "Situacao de saude: %s\n", paciente_atual->situacao_saude);
            fprintf(arquivo, "Digito Unico: %d\n", paciente_atual->digito_unico);
            fprintf(arquivo, "\n");

            paciente_atual = paciente_atual->proximo;
        }

        atual = atual->proximo;
    }

    fclose(arquivo);
}


int verificar_lista(Consultorio* consultorio_aux) {
    if (consultorio_aux == NULL) {
        printf("Lista de consultorios esta vazia\n");
        return 1;
    } else {
        return 0;
    }
}

Consultorio* adicionar_consultorio(Consultorio* lista_consultorios) {
    Consultorio* novo_consultorio = (Consultorio*)malloc(sizeof(Consultorio));
    if (novo_consultorio == NULL) {
        printf("Erro ao alocar memoria para o novo consultorio.\n");
        exit(1);
    }

while (1) {
    char identificacao[500];
    printf("Digite o ID do consultorio:\n ");
    scanf(" %[^\n]", identificacao);
    tratamento_de_numero(identificacao);
    novo_consultorio->identificacao = atoi(identificacao);

    if (verificar_id_existente(lista_consultorios, novo_consultorio->identificacao) == 1 || novo_consultorio->identificacao == 0) {
        if (verificar_id_existente(lista_consultorios, novo_consultorio->identificacao) == 1) {
            printf("Esse id ja pertence a um consultorio, digite outro.\n");
        }
        if (novo_consultorio->identificacao == 0) {
            printf("Nao se pode digitar apenas letras\n");
        }
    } else {
        break; 
    }
}
do
 {
    printf("Digite a especialidade desse consultorio:\n ");
    scanf(" %[^\n]", novo_consultorio->especialidade);
    tratamento_de_palavras(novo_consultorio->especialidade);
    string_maiuscula_minuscula(novo_consultorio->especialidade);
 }while (novo_consultorio->especialidade[0]=='\0');
 
  do
  {
    printf("Digite os equipamentos que estao disponiveis nesse consultorio:\n");
    scanf(" %[^\n]", novo_consultorio->equipamentos_disponiveis);
    tratamento_da_var_equipamentos(novo_consultorio->equipamentos_disponiveis);
    string_maiuscula_minuscula(novo_consultorio->equipamentos_disponiveis);
  }while (novo_consultorio->equipamentos_disponiveis==0);
  

    novo_consultorio->paciente = NULL;
    novo_consultorio->proximo = NULL;

    if (lista_consultorios == NULL || novo_consultorio->identificacao < lista_consultorios->identificacao) {
        novo_consultorio->proximo = lista_consultorios;
        return novo_consultorio;
    }

    Consultorio* anterior = lista_consultorios;
    Consultorio* atual = lista_consultorios->proximo;

    while (atual != NULL && novo_consultorio->identificacao > atual->identificacao) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = novo_consultorio;
    novo_consultorio->proximo = atual;

    return lista_consultorios;
}

void liberar_listas(struct Consultorio* lista) {
    struct Consultorio* temp_consultorio;
    while (lista != NULL) {
        temp_consultorio = lista;
        lista = lista->proximo;
        free(temp_consultorio);
    }


}

Consultorio* remover_consultorio_por_id(Consultorio* lista_consultorios) {
    char id_remover[500];
    int id_a_remover;

    if (verificar_lista(lista_consultorios) == 1) {
       printf("Lista de consultorios esta vazia\n");
       return lista_consultorios;
    }

    Consultorio *atual = lista_consultorios;
    Consultorio *anterior = NULL;

    printf("Digite o id do consultorio que deseja remover:\n");
    scanf(" %[^\n]", id_remover);
    tratamento_de_numero(id_remover);
    id_a_remover = atoi(id_remover);

    while (atual != NULL && atual->identificacao != id_a_remover) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Consultorio nao encontrado no sistema\n");
        return lista_consultorios;
    }

    if (anterior == NULL) {
        lista_consultorios = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    
    printf("Consultorio removido com sucesso.\n");

    return lista_consultorios;
}

void imprimir_consultorios_Disponiveis(Consultorio* lista) {
    if (verificar_lista(lista)==1){
        printf("Lista de consultorios esta vazia, nao ha nada para imprimir\n");
    }
    
    Consultorio* imprimir_lista = lista;
    printf("===Lista de consultorios===\n");
    
    while (imprimir_lista != NULL) {
        printf("Identificacao do consultorio: %d\n", imprimir_lista->identificacao);
        printf("Especialidade: %s\n", imprimir_lista->especialidade);
        printf("Equipamentos disponiveis: %s\n", imprimir_lista->equipamentos_disponiveis);
       
        imprimir_lista = imprimir_lista->proximo;
    }
}

int verificar_autenticidade(Consultorio* lista_consultorios, int digito_u) {
    Consultorio* consultorio_atual = lista_consultorios;
    while (consultorio_atual != NULL) {
        Paciente* paciente_atual = consultorio_atual->paciente;
        while (paciente_atual != NULL) {
            if (paciente_atual->digito_unico == digito_u) {
            
                return 1;
            }
            paciente_atual = paciente_atual->proximo;
        }
        consultorio_atual = consultorio_atual->proximo;
    }
    return 0;
}

int verificar_id_existente(Consultorio* lista_consultorios, int id) {
    Consultorio* consultorio_atual = lista_consultorios;
    while (consultorio_atual != NULL) {
        if (consultorio_atual->identificacao == id) {
            return 1; 
        }
        consultorio_atual = consultorio_atual->proximo;
    }
    return 0;
}

void ler_arquivo_e_inserir_lista(Consultorio **comeco, struct Paciente **pacientes, struct Lista_geral **pacientesgerais) {
    FILE *arquivo = fopen("consultorios_e_pacientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro na leitura de arquivo.\n");
        return;
    }
    char linha[200];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strncmp(linha, "CONSULTORIO:", strlen("CONSULTORIO:")) == 0) {
            Consultorio *novo_consultorio = (Consultorio *)malloc(sizeof(Consultorio));
            if (novo_consultorio == NULL) {
                printf("Erro ao reservar memoria para um novo consultorio.\n");
                return;
            }
            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "Identificacao: %d", &novo_consultorio->identificacao);

            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "Especialidade: %[^\n]", novo_consultorio->especialidade);

            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "Equipamentos disponiveis: %[^\n]", novo_consultorio->equipamentos_disponiveis);

            novo_consultorio->paciente = NULL;
            novo_consultorio->proximo = NULL;

            if (*comeco == NULL) {
                *comeco = novo_consultorio;
            } else {
                Consultorio *ultimo = *comeco;
                while (ultimo->proximo != NULL) {
                    ultimo = ultimo->proximo;
                }
                ultimo->proximo = novo_consultorio;
            }
        } else if (strncmp(linha, "PACIENTE:", strlen("PACIENTE:")) == 0) {
            Consultorio *ultimo = *comeco;
            while (ultimo->proximo != NULL) {
                ultimo = ultimo->proximo;
            }

            Paciente *novo_paciente = (Paciente *)malloc(sizeof(Paciente));
            if (novo_paciente == NULL) {
                printf("Erro: Não foi possível alocar memória para o novo paciente.\n");
                return;
            }

            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "Nome: %[^\n]", novo_paciente->nome);

            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "Idade: %d", &novo_paciente->idade);

            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "Situacao de saude: %[^\n]", novo_paciente->situacao_saude);

            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "Digito Unico: %d", &novo_paciente->digito_unico);

            *pacientesgerais=adicionar_paciente_geral(*pacientesgerais, novo_paciente);

            novo_paciente->proximo = NULL;

            if (ultimo->paciente == NULL) {
                ultimo->paciente = novo_paciente;
            } else {
                Paciente *ultimo_paciente = ultimo->paciente;
                while (ultimo_paciente->proximo != NULL) {
                    ultimo_paciente = ultimo_paciente->proximo;
                }
                ultimo_paciente->proximo = novo_paciente;
            } }
    }

    fclose(arquivo);
    
    printf("Dados inseridos na lista\n");
}
