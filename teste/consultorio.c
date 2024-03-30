#include <stdio.h>
#include <stdlib.h>
#include "consultorio.h"
#include"paciente.h"

void salvar_consultorios_e_pacientes_em_arquivo(Consultorio* lista_consultorios) {
    FILE* arquivo;
    Consultorio* atual = lista_consultorios;

    arquivo = fopen("consultorios_e_pacientes.txt", "w+"); 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (atual != NULL) {
        fprintf(arquivo, " ----Lista de consultorios da      ----\n");
        fprintf(arquivo, "Identificacao: %d\n", atual->identificacao);
        fprintf(arquivo, "Especialidade: %s\n", atual->especialidade);
        fprintf(arquivo, "Equipamentos disponiveis: %s\n", atual->equipamentos_disponiveis);

    
        Paciente* paciente_atual = atual->paciente;
        while (paciente_atual != NULL) {
            fprintf(arquivo, "   ||Pacientes||:  \n");
            fprintf(arquivo, "Nome do paciente: %s\n", paciente_atual->nome);
            fprintf(arquivo, "Idade do paciente: %d\n", paciente_atual->idade);
            fprintf(arquivo, "Situacao de saude do paciente: %s\n", paciente_atual->situacao_saude);
            fprintf(arquivo, "Digito unico: %d\n", atual->paciente->digito_unico);
            paciente_atual = paciente_atual->proximo;
        }
        fprintf(arquivo, "===========\n");

        atual = atual->proximo;
    }

    fclose(arquivo);
    printf("Dados dos consultorios salvos com sucesso no arquivo consultorios.txt\n");
}

void arquivo_para_consultorios(Consultorio*lista_completa){
FILE *consultorios;
Consultorio*lista_atual=lista_completa;

consultorios = fopen("consultorios_lista.txt", "w+"); 
    if (consultorios == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
while (lista_atual!=NULL)
{  fprintf(consultorios, "---Lista de consultorios:---\n");
    fprintf(consultorios, "Identificacao: %d\n", lista_atual->identificacao);
    fprintf(consultorios, "Especialidade: %s\n", lista_atual->especialidade);
    fprintf(consultorios, "Equipamentos Disponiveis: %s\n", lista_atual->equipamentos_disponiveis);
     fprintf(consultorios, "-------------------");
    lista_atual=lista_atual->proximo;
   
}
fclose(consultorios);


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
        printf("Erro ao alocar memoria para o novo consultorio\n");
        exit(1);
    }

    while (1) {
        char identificacao[500];
        printf("Digite o ID do consultorio:\n ");
        scanf(" %[^\n]", identificacao);
        tratamento_de_numero(identificacao);
        novo_consultorio->identificacao = atoi(identificacao);
        if (verificar_id_existente(lista_consultorios, novo_consultorio->identificacao) == 1) {
            printf("Esse id ja pertence a um consultorio, digite outro.\n");
        } else {
            break; 
        }
    }

    printf("Digite a especialidade desse consultorio:\n ");
    scanf(" %[^\n]", novo_consultorio->especialidade);
    tratamento_de_palavras(novo_consultorio->especialidade);
    string_maiuscula_minuscula(novo_consultorio->especialidade);

    printf("Digite os equipamentos que estao disponiveis nesse consultorio:\n");
    scanf(" %[^\n]", novo_consultorio->equipamentos_disponiveis);
    tratamento_de_palavras(novo_consultorio->equipamentos_disponiveis);
    string_maiuscula_minuscula(novo_consultorio->equipamentos_disponiveis);

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

    if (verificar_lista(lista)==1)
    {
        printf("Lista de consultorios esta vazia, nao ha nada para imprimir\n");
    }
    
    Consultorio* imprimir_lista = lista;
    printf("Lista de consultorios:\n");
    
    while (imprimir_lista != NULL) {
        printf("Identificacao do consultorio: %d\n", imprimir_lista->identificacao);
        printf("Especialidade: %s\n", imprimir_lista->especialidade);
        printf("Equipamentos disponiveis: %s\n", imprimir_lista->equipamentos_disponiveis);
       
        imprimir_lista = imprimir_lista->proximo;
    }
}


void editar_paciente(Consultorio* lista, char* nome_editar, int dg_procurar) {
    char opcao;
    if (verificar_lista(lista) == 1) {
        printf("Lista de consultorios esta vazia\n");
        return;
    }

    Paciente* paciente_Editar = buscar_paciente_por_nome(lista, nome_editar, dg_procurar);
    if (paciente_Editar != NULL) {
        printf("Edicao de dados do paciente:\n");
        printf("Deseja editar apenas um dado ou todos? Digite 1 para todos e 0 para apenas um dado\n ");
        scanf(" %c", &opcao);
        char idade_var[100];
        if (opcao == '1') {
            printf("Digite o novo nome do paciente:\n");
            scanf(" %[^\n]", paciente_Editar->nome);
            tratamento_de_palavras(paciente_Editar->nome);
            string_maiuscula_minuscula(paciente_Editar->nome);
            printf("Digite a nova idade do paciente:\n ");
            scanf(" %[^\n]", idade_var);
            tratamento_de_numero(idade_var);
            paciente_Editar->idade = atoi(idade_var);

            printf("Digite a nova situacao de saude:\n");
            scanf(" %[^\n]", paciente_Editar->situacao_saude);
            tratamento_de_palavras(paciente_Editar->situacao_saude);
            string_maiuscula_minuscula(paciente_Editar->situacao_saude);

            char dg_str[100];
            printf("Insira o novo digito unico do paciente:\n");
            scanf(" %[^\n]", dg_str);
            tratamento_de_numero(dg_str);
            paciente_Editar->digito_unico = atoi(dg_str);

        } else if (opcao == '0') {
            char dado_editar;
            printf("Digite o dado que voce quer editar: '1' para nome, '2' para idade e '3' para situacao de saude ou '4' para o digito unico\n");
            scanf(" %c", &dado_editar);

            if (dado_editar == '1') {
                printf("Digite o novo nome do paciente:\n");
                scanf(" %[^\n]", paciente_Editar->nome);
                tratamento_de_palavras(paciente_Editar->nome);
                string_maiuscula_minuscula(paciente_Editar->nome);

            } else if (dado_editar == '2') {
                printf("Digite a nova idade do paciente:\n ");
                scanf(" %[^\n]", idade_var);
                tratamento_de_numero(idade_var);
                paciente_Editar->idade = atoi(idade_var);

            } else if (dado_editar == '3') {
                printf("Digite a nova situacao de saude:\n");
                scanf(" %[^\n]", paciente_Editar->situacao_saude);
                tratamento_de_palavras(paciente_Editar->situacao_saude);
                string_maiuscula_minuscula(paciente_Editar->situacao_saude);
            } else if (dado_editar == '4') {
                char dg_str[100];
                printf("Insira o novo digito unico do paciente:\n");
                scanf(" %[^\n]", dg_str);
                tratamento_de_numero(dg_str);
                paciente_Editar->digito_unico = atoi(dg_str);
            } else {
                printf("Opcao invalida. Digite numeros correspondentes com os pedidos. Apenas 1, 2, 3 ou 4\n");
            }
        } else {
            printf("Opcao invalida. Digite nuemros correspondentes com os pedidos. Apenas 0 ou 1\n");
        }
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