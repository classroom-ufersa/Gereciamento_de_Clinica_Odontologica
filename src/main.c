#include <stdio.h>
#include <stdlib.h>
#include "paciente.c"
#include "consultorio.c"

int main() {
    struct Listapaciente* lista_pacientes = NULL;
    struct Listaconsultorio* lista_consultorio=NULL;
    char escolha;
    do{
        escolha=menu()
    

        switch (escolha) {
            case '1':
                

    break;
            case '2':
                
                break;
            case '3':
               
               int consultorio_id;
               printf("Digite o id do consultorio que esse paciente vai pertencer: ");
               scanf("%d", &consultorio_id);

               struct Consultorio* aux_consultorio = Listaconsultorios;
               while (aux_consultorio != NULL && aux_consultorio->id != consultorio_id) {
               aux_consultorio = aux_consultorio->proximo;
    }

               if (aux_consultorio != NULL) {
            aux_consultorio->pacientes = adicionar_paciente(aux_consultorio->pacientes);
             }
            else {
               printf("Consultorio nao encontrado.\n");
                   }
                break;
            case '4':
                printf("Opcao remover paciente:"); //aqui remove o primeiro da lista, igual a uma fila;
                lista_pacientes= remover_paciente(lista_pacientes);
                break;
            case '5':
                char nomeeditar[500];
                printf("Digite o nome do Paciente que deseja editar os dados:\n");
                scanf(" %[^\n]", nomeeditar);
                lista_consultorios= buscar_consultorio(lista_consultorios, nomeeditar);
                lista_pacientes= editar_pacientes(lista_pacientes);
                break;
            case '6':
            
                break;
            case '7':
            break;
            case '8':
            break;
          
            case '9':
             printf("Remover paciente especifico:\n"); //o famoso fura fila :) //talvez seja melhor nao colocar
             char paciente_escolhido;
             printf("Digite o nome do paciente que deseja remover:\n");
             scanf("%[^\n], paciente_escolhido");
             lista_consultorios= buscar_pacientes(lista_consultorios, paciente_escolhido); 
             struct Listapacientes*lista_atual= *listapaciente;

             while(lista_atual!=NULL){
             if (strcmp(lista_consultorios->pacientes->nome, paciente_escolhido)==NULL{
                struct Lista_atendidos *lista_atendidos= 
                strcpy(lista_consultorios->nome);
                strcpy(lista_consultorios->idade);
                strcpy(lista_consultorios->idade);
                return lista_atendidos;

             }
             }

            break;
            case '10';
            break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
          while(escolha!= '')
          }
          }
   

    return 0;
}
