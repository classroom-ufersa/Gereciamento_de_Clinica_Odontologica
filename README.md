# Gereciamento de Clinica Odontologica
Projeto de  um sistema na Linguagem C para gerenciamento de uma Clínica Odontológic, que realiza a manipulação de consultórios e clientes.  

- [Introdução](#introduçao)
- [Organização do repositório;](#organização-do-repositório)
- [Execução do projeto;](#execução-do-projeto)
___

## Desenvolvedores
> [Letícia Vieira Gonçalves](https://github.com/LeticiaVieirg)
>
> [Maria Isabelly de Lima Sousa](https://github.com/isabellylimals)

## **Introdução**

A gestão eficiente de uma clínica odontológica é crucial para garantir sua operação sem problemas e a máxima eficácia nos atendimentos aos pacientes. Isso abrange desde a organização dos prontuários até o agendamento de consultas e a administração dos recursos disponíveis. De forma a simplificar todas as operações necessárias para o funcionamento do negócio.

Esse sistema utiliza estruturas de dados como listas encadeadas para organizar as informações dos pacientes, consultórios, históricos de tratamento e outros aspectos relevantes para a clínica. Por meio de uma lista encadeada de consultórios, por exemplo, é possível gerenciar consultórios de forma dinâmica, incluindo adições, gerenciar fila de espera, remoções e alterações conforme a necessidade da clínica.

A utilização de listas encadeadas nesse contexto oferece flexibilidade, organização e escalabilidade, contribuindo para uma experiência mais eficiente tanto para os pacientes quanto para a equipe médica e administrativa.

### **Problemática**
O sistema de gerenciamento para uma clínica odontológica, desenvolvido em Linguagem C, tem como objetivo simplificar as operações cruciais para o funcionamento eficiente do estabelecimento. Ele proporciona funcionalidades como adicionar, excluir, buscar e editar pacientes e consultas, além de listar os pacientes e seus históricos de consultas. Essas funcionalidades são essenciais para garantir uma gestão eficaz e organizada das atividades da clínica odontológica.

## **Descrição**
### Requisitos atendidos

### Atribuições essenciais no projeto
### Atributos Consultório
- [x] Idetificação
- [x] Especialidade
- [x] Equipamentos disponíveis
- [x] Pacientes

### Atributos Pacientes
- [x] Nome
- [x] Idade
- [x] Situação de saúde

### Menu 
- [x] Adicionar consultório
- [x] Remover consultório
- [x] Adicionar paciente
- [x] Remover paciente
- [x] Editar informações do paciente
- [x] Buscar paciente por nome
- [x] Listar conultórios e pacientes atendidos
- [x] Sair


## **Organização do Repositório**

``` 
📁 Gerenciamento_de_Clinica_Odontologica
│
└─── bin
        │
        ├──.gitignore
        ├──desktop.ini
│
└─── include
        │
        ├──consultorio.h
        ├──paciente.h
│
└─── resources
        │
        ├──consultorios_e_pacientes.txt
        ├──consultorios_lista.txt
        ├──lista_atendidos.txt
│
└─── src
        │
        ├──consultorio.c
        ├──main.c
        ├──paciente.c
│
└───test
        │
        ├──consultorio.c
        ├──consultorio.h
        ├──consultorio.o
        ├──main.c
        ├──main.exe
        ├──main.o
        ├──paciente.c
        ├──paciente.h
        ├──paciente.o
│
└───README.md
```

## **Listas Encadeadas**

## **Funções em Paciente** 

## **Funções em Consultorio**

## **Funções em Main**

## Pré-Requisitos:
Certifique-se de que você possui um compilador C instalado. Recomendamos o uso do [GCC](https://gcc.gnu.org/) para compilar o código.

###### Aqui, é válido salientar que as funções implementadas na pasta "consultas" e "paciente" serão chamadas no arquivo main.c, que está fora da pasta.

## Execução do projeto
### Compilação do código:
### Execução do código:
