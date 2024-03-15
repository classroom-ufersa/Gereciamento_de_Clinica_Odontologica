#include "paciente.h"

struct paciente{
    char nome[Max];
    int idade;
    int situacao_saude;
};

Paciente* coletar_dados_paciente(Paciente *p, int quantidade_pacientes){
    
Paciente* p = NULL;
    int quantidade_pacientes = 0;
    char choose;
    int continuidade = 1;

    while (continuidade) {
        printf("Deseja adicionar um paciente? (S/N): ");
        scanf(" %c", &choose); 

        if (choose == 'S' || choose == 's') {
            p = (Paciente*)realloc(p, (quantidade_pacientes + 1) * sizeof(Paciente));

            printf("Digite o nome do cliente: ");
            scanf("%s", p[quantidade_pacientes].nome);

            printf("Digite a idade do paciente: ");
            scanf("%d", &p[quantidade_pacientes].idade);

            printf("Qual a situação da saúde (B para bom, R para ruim e M para médio): ");
            scanf(" %s", escolha); 

            if (escolha[0] == 'B') {
                strcpy(p[quantidade_pacientes].situacao_saude, "Boa");
            }
            else if (escolha[0] == 'M') {
                strcpy(p[quantidade_pacientes].situacao_saude, "Média");
            }
            else if (escolha[0] == 'R') {
                strcpy(p[quantidade_pacientes].situacao_saude, "Ruim");
            }
            else {
                printf("Escolha apenas as letras 'R', 'B' ou 'M'.\n");
                continue; 
            }

            quantidade_pacientes++;
        }
        else if (choose != 's' && choose != 'S') {
            printf("Digite novamente, apenas a letra 'S' ou 'N'.\n");
        }
    }

    

    return 0;
}

 void escrever_pacientes(Paciente*, int quantidade_pacientes)
 void ler_pacientes(Paciente*p, int quantidade_pacientes)
void remover_paciente(Paciente *p){

}

Paciente editar_paciente(Paciente *p, char[Max]){
}

void buscar_paciente(Paciente *p){
    
}

