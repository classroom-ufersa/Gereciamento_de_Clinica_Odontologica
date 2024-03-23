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
               
                break;
            case '5':
                char nomeeditar[500];
                printf("Digite o nome do Paciente que deseja editar os dados:\n");
                scanf(" %[^\n]", nomeeditar);
                 buscar_consultorio(lista_consultorios, nomeeditar);
                 editar_pacientes(lista_pacientes);
                break;
            case '6':
            
                break;
            case '7':
            break;
            case '8':
            break;
          
            case '9':
            }
         
           
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
          while(escolha!= '9')
          }
          }
   

    return 0;
}
