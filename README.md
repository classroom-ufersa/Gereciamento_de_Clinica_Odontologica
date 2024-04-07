# **Gereciamento de Clinica Odontológica**
Projeto de  um sistema na Linguagem C para gerenciamento de uma Clínica Odontológica, que realiza a manipulação de consultórios e pacientes.  

## **Desenvolvedores**
> [Letícia Vieira Gonçalves](https://github.com/LeticiaVieirg)
>
> [Maria Isabelly de Lima Sousa](https://github.com/isabellylimals)
***

# **Tabela de conteúdo**
> [Introdução](#introdução)
> 
> [Problemática](#problemática)
>
> [Desenvolvimento](#desenvolvimento)
> 
> [Organização do repositório](#organização-do-repositório)
> 
> [Compilação e execução](#compilação-e-execução)
***

## **Introdução**

A gestão eficiente de uma clínica odontológica é crucial para garantir sua operação sem problemas e a máxima eficácia nos atendimentos aos pacientes. Isso abrange desde a organização dos prontuários até o agendamento de consultas e a administração dos recursos disponíveis. De forma a simplificar todas as operações necessárias para o funcionamento do negócio.

Esse sistema utiliza estruturas de dados como listas encadeadas para organizar as informações dos pacientes, consultórios, históricos de tratamento e outros aspectos relevantes para a clínica. Por meio de uma lista encadeada de consultórios, por exemplo, é possível gerenciar consultórios de forma dinâmica, incluindo adições, gerenciar fila de espera, remoções e alterações conforme a necessidade da clínica.

A utilização de listas encadeadas nesse contexto oferece flexibilidade, organização e escalabilidade, contribuindo para uma experiência mais eficiente tanto para os pacientes quanto para a equipe médica e administrativa.
***

## **Problemática**
- O sistema de gerenciamento para uma clínica odontológica - CHAR OF SMILLE, desenvolvido em Linguagem C, tem como objetivo simplificar as operações cruciais para o funcionamento eficiente do estabelecimento. Ele proporciona funcionalidades como adicionar, excluir, buscar e editar pacientes e consultas, além de listar os pacientes e seus históricos de consultas. Essas funcionalidades são essenciais para garantir uma gestão eficaz e organizada das atividades da clínica odontológica.

### Atribuições
#### *Atributos Consultório*
- [x] Idetificação
- [x] Especialidade
- [x] Equipamentos disponíveis
- [x] Pacientes

#### *Atributos Pacientes*
- [x] Nome
- [x] Idade
- [x] Situação de saúde

#### *Menu*
- [x] Adicionar consultório
- [x] Remover consultório
- [x] Adicionar paciente
- [x] Remover paciente
- [x] Editar informações do paciente
- [x] Buscar paciente por nome
- [x] Listar conultórios e pacientes atendidos
- [x] Sair
***

## **Desenvolvimento**
- O projeto desenvolvimento conta com 3 TAD's, sendo estas consultorio, paciente e funções.  

### Tipos estruturados
- O projeto apresenta os seguintes tipos estruturados:

#### *Struct Consultorio*
```c
typedef struct Consultorio {
  int identificacao;
  char especialidade[400];
  char equipamentos_disponiveis[100];
  struct Paciente* paciente;
  struct Consultorio* proximo;
  struct Lista_geral* listageral;
} Consultorio; 
```
#### *Struct paciente*
```c
typedef struct Paciente {
    char nome[100];
    int idade;
    char situacao_saude[100];
    int digito_unico;
    struct Consultorio* consultorio;
    struct Paciente* proximo;
}Paciente;

typedef struct  Lista_atendidos {
    struct Lista_atendidos* proximo;
    Paciente* paciente_atendido;
} Lista_Atendidos;

typedef struct Lista_geral {
    struct Lista_geral* proximo;
    Paciente* paciente_geral;
} Lista_geral;
```

### **Tipo Abstrato de Dados**
- Durante o desenvolvimento do projeto percebemos a necessidade da utilização de 3 TAD's e de listas encadeadas simples, com o objetivo de manipular qualquer nó da lista. Dessa forma, permite flexibilidade no gerenciamento, organização, possibilidade de adicão, remoção e busca de forma dinâmica dos dados. Portanto, as listas encadeadas facilitam a manipulação, organização e gerenciamento dinâmico dos dados relacionados aos consultórios e pacientes, contribuindo para um código mais eficiente e modular.
  
#### *consultorio.h*
```c
/*Funcao que ler arquivo de texto e insere na lista antes de carregar o menu,
  Recebe como parametros um comeco e um tipo estruturado paciente*/
void ler_arquivo_e_inserir_lista(Consultorio **comeco, struct Paciente **pacientes, struct Lista_geral **pacientesgerais);

/*Funcao que verifica se a lista esta vazia,
  Recebe como parametros um ponteiro de consultorio*/
int verificar_lista(Consultorio*consultorio_aux); 

/*Funcao que adiciona um consultorio a lista de consultorios,
  Recebe como parametros um ponteiro de consultorio*/
Consultorio* adicionar_consultorio(Consultorio* lista_consultorios); 

/*Funcao que remove um consultorio pelo ID informado,
  Recebe como parametro um ponteiro de consultorio*/
Consultorio* remover_consultorio_por_id(Consultorio* lista_consultorios); 

/*Funcao que verifica se o id digitado existe,
  Recebe como parametro a lista de consultorio e o id*/
int verificar_id_existente(Consultorio* lista_consultorios, int id); 

/*Funcao que verifica a autenticidade do digito unico,
  Recebe como parametros a lista de pacientes e o digito unico*/
int verificar_autenticidade(Consultorio* lista_consultorios, int digito_u); 

/*Funcao que imprime os consultorios disponiveis,
  Recebe como parametro um ponteiro de consultorio*/
void imprimir_consultorios_Disponiveis(Consultorio* lista); 

/*Funcao que salva os consultorios cadastrados e pacientes em um arquivo,
  Recebe como parametros uma lista de consultorios*/
void salvar_consultorios_e_pacientes_em_arquivo(Consultorio* lista_consultorios); 
```

#### *paciente.h*
```c
/*Funcao que coleta dados do paciente,
  Recebe como parametro um ponteiro para paciente*/
void coletar_dados_paciente(Paciente* paciente, struct Consultorio* lista);

/*Funcao que cria um novo paciente e inicializa com os dados fornecidos,
  Recebe como parametros o nome, a idade, a situação de saude e um ponteiro para consultorio*/
Paciente* criar_paciente(char* nome, int idade, char* situacao_saude, int dg);
    
/*Funcao que adiciona um novo paciente em ordem alfabetica a uma lista encadeada de pacientes,
  Recebe como parametros a lista atual de pacientes e o novo paciente adicionado*/
Paciente* adicionar_paciente_ordenado(Paciente* lista, Paciente* novo_paciente); 

/*Funcao que adiciona paciente a uma lista geral de pacientes,
  Recebe como parametros um ponteiro para a lista geral*/
Lista_geral* adicionar_paciente_geral(Lista_geral* lista_geral, Paciente* paciente); 

/*Funcao que imprime os dados de cada paciente na lista,
  Recebe como parametro uma lista de pacientes atendidos*/
void imprimir_atendidos(Lista_Atendidos*lista); 

/*Funcao que coloca os pacientes atendidos em uma lista,
  Recebe como parametro uma lista*/
void arquivo_atendidos(Lista_Atendidos*lista); 

/*Funcao que remove um paciente do inicio da lista e adiciona a lista de atendidos, 
  Recebe como parametros a lista e a lista de atendidos*/
void remover_paciente_por_fila(Lista_geral **lista, Lista_Atendidos **lista_atendidos);

/*Funcao que busca o paciente no consultorio pelo nome,
  Recebe como parametros a lista de consultorios, o nome e o digito*/
Paciente* buscar_paciente_por_nome(struct Consultorio* lista_consultorios, char* nome, int digitoUnico); 

/* Funcao que exibe a lista geral, 
  Recebe como parametro a lista*/
void imprimir_gerais(Lista_geral* lista); 
    
/*Funcao que adiciona o paciente ao consultorio por meio do ID,
  Recebe como parametros a lista de consultorio e a lista geral*/
void adicionar_paciente_por_id(struct Consultorio* lista_consultorios,  Lista_geral** lista_geral); 

/*Funcao que edita paciente que esta na lista,
  Recebe como parametros a lista, o nome a ser editado e o dg procurar*/
void editar_paciente(struct Consultorio* lista, char* nome_editar, int dg_procurar);

/*Funcao que remove um paciente do consultorio,
  Recebe como parametros uma lista, o nome e o dg remover*/
void remover_paciente_para_inserir(struct Consultorio* lista, char* nome_remover, int dg_remover);
```

#### *funcoes.h*
```c
/*Funcao do menu principal*/
void menu();

/*Funcao para limpar buffer*/
void limpa_buffer(void);

/*Funcao que remove todos os caracteres que nao sao digitos numericos da string,
  Recebe como parametro uma string*/
void tratamento_de_numero(char *variavel_num); 

/*Funcao que remove todos os caracteres que nao sao letras maiusculas, minusculas ou espaços,
  Recebe como parametro uma string*/
void tratamento_de_palavras(char *palavra_var); 

/*Funcao que transforma a primeira letra em maiuscula e as demais em minusculas,
  Recebe como parametro uma string*/
void string_maiuscula_minuscula(char *palavra_var); 

/*Funcao de tratamento da variavel equipamente para que aceite "." e ":",
  Recebe como parametro uma palavra*/
void tratamento_da_var_equipamentos(char *palavra_var);
```

### Listas Encadeadas

#### Consultorio
- A gestão dinâmica de consultórios médicos por meio de uma lista encadeada representa um avanço significativo em termos de flexibilidade, organização e escalabilidade. Cada nó dessa lista é como um consultório em si, capaz de se adaptar às necessidades da clínica de forma ágil e eficiente.
- A adição de novos consultórios é simplificada, permitindo a expansão da capacidade de atendimento de forma fluida e sem sobressaltos. A gestão da fila de espera é otimizada, garantindo uma distribuição equitativa dos pacientes e reduzindo o tempo de espera, proporcionando uma experiência mais satisfatória tanto para os pacientes quanto para a equipe médica e administrativa.
- As remoções e alterações necessárias são realizadas com precisão e rapidez, mantendo a organização interna da clínica em constante harmonia. Esse sistema oferece não apenas eficiência operacional, mas também uma gestão mais humanizada, onde o foco está no bem-estar dos pacientes e na otimização do trabalho da equipe médica, contribuindo assim para a excelência no atendimento médico.

#### Paciente
- A utilização de uma lista encadeada de pacientes oferece uma abordagem organizada e flexível para a gestão eficiente dos atendimentos nos consultórios médicos. Cada nó dessa estrutura representa um paciente, permitindo uma visão ampla de todos os pacientes em um contexto geral, enquanto também oferece a capacidade de organizá-los por consultório.
- As adições de novos pacientes são feitas de maneira simples e direta, integrando-os à lista geral ou associando-os a um consultório específico, conforme necessário. A gestão da fila de espera é realizada de forma estratégica, garantindo uma distribuição equitativa dos atendimentos e minimizando o tempo de espera dos pacientes.
- As remoções e alterações de pacientes são tratadas de maneira eficiente, mantendo o registro atualizado dos pacientes atendidos e proporcionando uma visão clara do fluxo de atendimentos ao longo do tempo. Esse sistema não apenas organiza os pacientes de forma eficaz, mas também oferece flexibilidade para adaptar-se às demandas variáveis dos consultórios, contribuindo para uma experiência mais ágil e satisfatória tanto para os pacientes quanto para a equipe médica.
***

## Organização do Repositório
``` 
📁 Gerenciamento_de_Clinica_Odontologica
│
└─── bin
        │
        ├──.vscode
        ├──.gitignore
        ├──desktop.ini
│
└─── include
        │
        ├──consultorio.h
        ├──funcoes.h
        ├──paciente.h
│
└─── resources
        │
        ├──consultorios_e_pacientes.txt
        ├──lista_atendidos.txt
│
└─── src
        │
        ├──consultorio.c
        ├──funcoes.c
        ├──main.c
        ├──paciente.c
│
└───test
        │
        ├──consultorio.c
        ├──consultorio.h
        ├──consultorio.o
        ├──funcoes.c
        ├──funcoes.h
        ├──funcoes.o
        ├──main.c
        ├──main.exe
        ├──main.o
        ├──paciente.c
        ├──paciente.h
        ├──paciente.o
│
└───README.md
```

## Compilação e Execução do projeto
### Pré-Requisitos
Certifique-se de que você possui um compilador C instalado. Recomendamos o uso do [GCC](https://gcc.gnu.org/) para compilar o código.

### Compilação do código


### Execução do código
