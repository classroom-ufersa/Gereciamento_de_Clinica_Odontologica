#include "../include/funcoes.h"

/*Funcao do menu principal*/
 void menu() {
    
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
