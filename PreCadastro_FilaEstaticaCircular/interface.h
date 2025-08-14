#define N 200

typedef struct Paciente {
    char nome[100];
    char CPF[11];
    char endereco[100];
} Paciente;

typedef struct Triagem {
    Paciente *paciente;
    char dataNascPaciente[11];
    char avaEstadoSaude[100];
    int prioridade;
    // 3 = Vermelho = emergência, 
    // 2 = Amarelo = urgente,
    // 1 = Verde = não urgente. 
    char sintomas[100];
} Triagem;
// Após a triagem, o paciente entra em uma fila para atendimento médico!

typedef struct Fila {
    Paciente pacientes[N];
    int size;
    int inicio;
    int final;
} Fila;

void inicializa_fila(Fila *fila);

int fila_is_empty(Fila *fila);
int fila_is_full(Fila *fila);
int fila_size(Fila *fila);

void cadastra_novo_paciente(Fila *fila, Paciente pacienteDados);
void remove_paciente(Fila *fila);
Paciente* consulta_cpf(Fila *fila, char cpf[11]);

void imprime_fila(Fila *fila);