
#include<stdio.h>
#include<stdlib.h>
#include "paciente.c"
#include"consultorio.c"
           
  
int main() {
    struct Consultorio* lista_consultorios = NULL;
    struct Lista_geral* lista_geral = NULL;  
    struct Paciente* lista_paciente=NULL; //nao sabemos se vai ser usado aqui;
      char opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar consultorio\n");
        printf("2. Remover Consultorio\n");
        printf("3. Adicionar paciente na lista geral\n");
        printf("4. Remover Paciente:"); //lembrar de adicionar as outras opcoes ao decorrer do progresso para ir testando;
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);
        getchar();

        switch (opcao) {
            case '1': {
                Consultorio* novo_consultorio = (Consultorio*)malloc(sizeof(Consultorio));
                if (novo_consultorio == NULL) {
                    printf("Erro ao alocar memoria para o novo consultorio\n");
                    exit(1);
                }

                printf("Digite o ID do consultorio: ");
                scanf("%d", &novo_consultorio->identificacao);
                getchar();

                printf("Digite a especialidade desse consultorio: ");
                scanf(" %[^\n]", novo_consultorio->especialidade);
                getchar();

                printf("Digite os equipamentos que estao disponiveis nesse consultorio:\n");
                scanf(" %[^\n]", novo_consultorio->equipamentos_disponiveis);
                getchar();

                lista_consultorios = adicionar_consultorio(lista_consultorios);
                
            }
            case '2': {
                printf("02");
                //remover consultorio;
                break; 
            }
               case '3':{
                Consultorio*atual;
                int id_procurar;
                printf("Digite o id do consultorio que deseja adicionar esse paciente");
                scanf("%d", &id_procurar);
                Paciente*novo_paciente=(Paciente*)malloc(sizeof(Paciente));
                coletar_dados_paciente(novo_paciente);
                lista_geral= adicionar_paciente_geral(lista_geral, novo_paciente);
                  while (atual != NULL) {
                    if (atual->identificacao == id_procurar){
                        //aqui vamos inserir o paciente que na posicao correta no consultorio;
                    }
               }
                
            
            case '4': {
               //remover paciente funcao;
                break;
            }
            case '0': {
            
                break;
            }
            default: {
                
                break;
            }
        }

    } while (opcao != '0');

    return 0;
}
