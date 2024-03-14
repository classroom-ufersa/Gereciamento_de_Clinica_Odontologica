/*Renomeacao de um tipo estruturado*/
typedef struct paciente Paciente;

/*Funcao que adiciona um paciente,
  Recebe como parametro um ponteiro*/
Paciente coletar_dados_paciente(Paciente *p, Quantidade_pacientes);

/*Funcao que remove um paciente,
  Recebe como parametro um ponteiro*/
void remover_paciente(Paciente *p);

/*Funcao que edita as informacoes de um paciente,
  Recebe como parametros um ponteiro*/
Paciente editar_paciente(Paciente *p, char[Max])

/*Funcao que busca o paciente pelo nome,
  Recebe como parametro um ponteiro*/
void buscar_paciente(Paciente *p);
