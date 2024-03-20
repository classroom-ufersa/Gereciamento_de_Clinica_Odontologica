#include <stdio.h>
#include <stdlib.h>
#include "paciente.c"

int main() {
    struct Listapaciente* lista_pacientes = NULL;
    char escolha;
    do{
        escolha=menu()
    

        switch (escolha) {
            case '1':
                
}
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
                
                break;
            case '6':
            
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (escolha != '8');}

   
    struct Listapaciente* atual = lista_pacientes;
    while (atual != NULL) {
        struct Listapaciente* proximo = atual->next;
        free(atual->paciente);
        free(atual);
        atual = proximo;
    }

    return 0;
}