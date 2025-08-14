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

void inicializaPilha(Pilha *p);
int pilhaCheia(Pilha *p);
int pilhaVazia(Pilha *p);
void empilha(Pilha *p, int valor);
int desempilha(Pilha *p);
void imprimePilha(Pilha *p);