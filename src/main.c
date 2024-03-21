#include <stdio.h>
#include <stdlib.h>
#include "paciente.c"

int main() {
    struct Listapaciente* lista_pacientes = NULL;
    char escolha;
    

        switch (escolha) {
            case '1':
                lista_pacientes = coletar_dados_paciente(lista_pacientes);
            
}
                break;
            case '2':
                
                break;
            case '3':
               
                break;
            case '4':
                
                break;
            case '5':
                
                break;
            case '6':
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (escolha != '6');

   
    struct Listapaciente* atual = lista_pacientes;
    while (atual != NULL) {
        struct Listapaciente* proximo = atual->next;
        free(atual->paciente);
        free(atual);
        atual = proximo;
    }

    return 0;
}
