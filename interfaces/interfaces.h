#ifndef INTERFACES_H
#define INTERFACES_H

// ___________________________________ Pré Cadastro ___________________________________
#define MAX_PACIENTES_PRE_CADASTRO 200

typedef struct PacienteCadastro {
    char nome[100];
    char CPF[16];
    char endereco[100];
} PacienteCadastro;

typedef struct Triagem {
    PacienteCadastro *paciente;
    char dataNascPaciente[11];
    char avaEstadoSaude[100];
    int prioridade;
    // 3 = Vermelho = emergência, 
    // 2 = Amarelo = urgente,
    // 1 = Verde = não urgente. 
    char sintomas[100];
} Triagem;

typedef struct FilaCadastro {
    PacienteCadastro pacientes[MAX_PACIENTES_PRE_CADASTRO];
    int size;
    int inicio;
    int final;
} FilaCadastro;

// ___________________________________ Fila Atendimento ___________________________________
typedef struct PacienteFilaAtendimento {
    PacienteCadastro pacienteDadosPadrao;
    int tipoAtendimento; 
    struct PacienteFilaAtendimento* proxPaciente;
} PacienteFilaAtendimento;

typedef struct FilaAtendimento {
    PacienteFilaAtendimento* inicio;
    PacienteFilaAtendimento* fim;
} FilaAtendimento;

#endif