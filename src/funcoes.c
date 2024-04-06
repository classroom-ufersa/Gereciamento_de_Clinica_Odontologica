#include "../include/consultorio.h"
#include "../include/paciente.h"
#include "../include/funcoes.h"

/*Funcao do menu principal*/
void menu(void) {
        printf("========= MENU CHAR OF SMILE DENTAL CLINIC ==========\n");
        printf("[1] Adicionar consultorio\n");
        printf("[2] Remover consultorio \n");
        printf("[3] Adicionar paciente\n");
        printf("[4] Remover paciente\n");
        printf("[5] Editar informacoes de paciente\n");
        printf("[6] Buscar paciente por nome\n");
        printf("[7] Listar consultorios \n");
        printf("[8] Listar pacientes atendidos\n");
        printf("[9] Sair\n");
        printf("==============================================\n");
        printf("Escolha uma das opcoes acima:\n");

        scanf(" %c", &opcao);
    
        switch (opcao) {
            case '1': {
                lista_consultorios = adicionar_consultorio(lista_consultorios);
                salvar_consultorios_e_pacientes_em_arquivo(lista_consultorios);
                break;
            }
            case '2': {
                lista_consultorios= remover_consultorio_por_id(lista_consultorios);
                salvar_consultorios_e_pacientes_em_arquivo(lista_consultorios);
                break; 
            }
            case '3': {
                adicionar_paciente_por_id(lista_consultorios,&lista_geral);
                salvar_consultorios_e_pacientes_em_arquivo(lista_consultorios);
                break;
            }
            case '4': {
                remover_paciente_por_fila(&lista_geral,&lista_atendidos);
                break;
            }
            case '5': {
                char nome_editar[500];
                char dg_string[100];
                int digito_unico;

                printf("Digite o nome do paciente que deseja editar:\n");
                scanf(" %[^\n]", nome_editar);
                tratamento_de_palavras(nome_editar);
                string_maiuscula_minuscula(nome_editar);
                printf("Agora insira o digito unico desse paciente:\n");
                scanf(" %[^\n]", dg_string);
                tratamento_de_numero(dg_string);
                digito_unico=atoi(dg_string);

                editar_paciente(lista_consultorios, nome_editar,digito_unico);
                salvar_consultorios_e_pacientes_em_arquivo(lista_consultorios);
                break;
            }
            case '6': {
                char nome_buscar[500];
                char dg_string[100];
                int digito_unico;
                printf("Digite o nome do paciente que deseja buscar:\n");
                scanf(" %[^\n]", nome_buscar);
                tratamento_de_palavras(nome_buscar);
                string_maiuscula_minuscula(nome_buscar);
                printf("Agora insira o digito unico desse paciente:\n");
                scanf(" %[^\n]", dg_string);
                tratamento_de_numero(dg_string);
                digito_unico=atoi(dg_string);
                lista_paciente = buscar_paciente_por_nome(lista_consultorios, nome_buscar, digito_unico);
            }
            case '7': {
                imprimir_consultorios_Disponiveis(lista_consultorios);
                break;
            }
            case '8': {
                imprimir_gerais(lista_geral);
                imprimir_atendidos(lista_atendidos);
                arquivo_atendidos(lista_atendidos);
                break;
            }
            case '9': {
                printf("======....Saindo do sistema....======\n");
                break;
            }
    
            default: {
                printf("Opção invalida. Tente novamente. \n");
                break;
            }
        }

    } while (opcao != '9');
  
    //Liberar memoria
    free(lista_consultorios);
    free(lista_atendidos);
    free(lista_paciente);
    free(lista_geral);
    return 0;
}

/*Funcao para limpar buffer*/
void limpa_buffer(void);

void tratamento_de_numero(char *variavel_num) {
    int Contador, contador2
    ;
    for (Contador = 0; variavel_num[Contador] != '\0'; Contador++){
        if (variavel_num[Contador] < 48 || variavel_num[Contador] > 57) {
            for (contador2= Contador; variavel_num[contador2] != '\0'; contador2++) {
                variavel_num[contador2] = variavel_num[contador2+ 1];
            }
        Contador--;
    }
  }
}

void tratamento_de_palavras(char *palavra_var){
    int Contador, contador2;
    for (Contador = 0; palavra_var[Contador] != '\0'; Contador++)  {
        if((palavra_var[Contador] < 65 || palavra_var[Contador] > 90) && (palavra_var[Contador] < 97 || palavra_var[Contador] > 122) && (palavra_var[Contador] != 32 )){
            for(contador2= Contador;palavra_var[contador2] != '\0';contador2++){
                palavra_var[contador2] = palavra_var[contador2+ 1];
            }
       Contador--;
    }
  }
}

void tratamento_da_var_equipamentos(char *palavra_var){
    int Contador, contador2; 
    for (Contador = 0; palavra_var[Contador] != '\0'; Contador++)  {
        if((palavra_var[Contador] < 65 || palavra_var[Contador] > 90) && (palavra_var[Contador] < 97 || palavra_var[Contador] > 122) && (palavra_var[Contador] != 32) && (palavra_var[Contador]!=46) && (palavra_var[Contador]!=250) && (palavra_var[Contador] != 44)){
            for(contador2= Contador;palavra_var[contador2] != '\0';contador2++){
                palavra_var[contador2] = palavra_var[contador2 + 1];
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
