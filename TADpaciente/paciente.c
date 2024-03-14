#include 

struct paciente{
    char nome[Max];
    int idade;
    int situacao_saude;
};

Paciente coletar_dados_paciente(Paciente *p){
    p=(Paciente*)malloc(sizeof(Paciente*));
    if (a==NULL){
        printf("Erro de alocação de memória");
        exit(1);
    }
    do{
        qualquer=0; char  choose;
   printf("Caso deseje cadastrar algum paciente digite \"S\"\n");
    scanf(" %c", &choose);
    choose = toupper(choose); 
char escolha;
    if (choose == 'S'){
      p = (Paciente*)realloc(p, (Quantidade_pacientes + 1) * sizeof(Pacientes));

    return p;
}
printf("Digite o nome do cliente:\n");
scanf("%s" p->nome);
printf ("Digite a idade do paciente:\n");
scanf("%d", p->idade);
printf("Qual a situação da saúde, digite B para bom, R para ruim e M para medio:\n");
scanf("%s", escolha);
if (escolha== 'B' && escolha=='b')

{
    p->situacao_saude= "Boa";
}


Quantidade_pacientes++;

void remover_paciente(Paciente *p){

}

Paciente editar_paciente(Paciente *p, char[Max]){
}

void buscar_paciente(Paciente *p){
    
}

