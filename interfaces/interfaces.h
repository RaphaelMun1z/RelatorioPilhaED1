#ifndef INTERFACES_H
#define INTERFACES_H

// ___________________________________ Geral ___________________________________
typedef struct Data {
    char dia[3];
    char mes[3];
    char ano[5];
} Data;

typedef struct Horario {
    char hora[3];
    char minuto[3];
    char segundo[5];
} Horario;

// ___________________________________ Pré Cadastro ___________________________________
#define MAX_PACIENTES_PRE_CADASTRO 200
#define MAX_PACIENTES_TRIAGEM 200

typedef struct PacienteCadastro {
    char nome[100];
    char CPF[16];
    char endereco[100];
} PacienteCadastro;

typedef struct Triagem {
    PacienteCadastro *paciente;
    char dataNascPaciente[11];
    char avaEstadoSaude[100];
    int baseDeRisco;
    char sintomas[100];
} Triagem;

typedef struct FilaTriagem {
    Triagem triagens[MAX_PACIENTES_TRIAGEM];
    int size;
    int inicio;
    int final;
} FilaTriagem;

typedef struct FilaCadastro {
    PacienteCadastro pacientes[MAX_PACIENTES_PRE_CADASTRO];
    int size;
    int inicio;
    int final;
} FilaCadastro;

// ___________________________________ Fila Atendimento ___________________________________
typedef struct PacienteFilaAtendimento {
    //PacienteCadastro pacienteDadosPadrao;
    Triagem triagemPaciente;
    int tipoAtendimento; 
    struct PacienteFilaAtendimento* proxPaciente;
} PacienteFilaAtendimento;

typedef struct FilaAtendimento {
    PacienteFilaAtendimento* inicio;
    PacienteFilaAtendimento* fim;
} FilaAtendimento;

// ___________________________________ Pilha LOG ___________________________________
#define TAM_PILHA_LOGS 100

typedef struct NoLog {
    Horario horaInicio; 
    Horario horaTermino; 
    double cidDiagPac;
} NoLog;

typedef struct PilhaLog {
    NoLog logs[TAM_PILHA_LOGS];
    int topo;
} PilhaLog;

// ___________________________________  Pilha Internados ___________________________________
typedef struct PacienteInternado {
    char nome[100]; 
    char dieta[100];
    char medicacoesDeRotina[100];
    char tratamento[100];
    struct PacienteInternado *proxPaciente;
} PacienteInternado;

typedef struct PilhaPacientesInternados {
    PacienteInternado *topo;
} PilhaPacientesInternados;

#endif