#define TAM_PILHA 3

typedef struct PacienteInternado {
    char nome[100]; 
    char dieta[100];
    char medicaçoesDeRotina[100];
    char tratamento[100];
    struct No *proxPaciente;
} PacienteInternado;

typedef struct Pilha {
    PacienteInternado *topo;
} Pilha;

Pilha* inicializaPilha();
int pilhaVazia(Pilha *p);
void empilha(Pilha *p, int valor);
int desempilha(Pilha *p);
void imprimePilha(Pilha *p);
Pilha* liberaPilha(Pilha *p);