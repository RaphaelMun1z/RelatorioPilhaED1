#define TAM_PILHA 100

typedef struct RegistroAtendimento {
    int horaInicio; 
    int horaTermino; 
    double cidDiagPac;
} Log;

typedef struct Pilha {
    Log logs[TAM_PILHA];
    int topo;
} Pilha;

void inicializar_pilha_registro_atendimento(Pilha *p);
int pilha_cheia_registro_atendimento(Pilha *p);
int pilha_vazia_registro_atendimento(Pilha *p);
void adicionar_registro_atendimento(Pilha *p, int valor);
int remover_registro_atendimento(Pilha *p);
void imprimir_pilha_registro_atendimento(Pilha *p);