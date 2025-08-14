typedef struct Paciente {
    char nome[100];
    char CPF[11];
    char endereço[100];
    int tipoCaso; 
    // 0 = emergência
    // 1 = consulta
    struct Paciente* proxPaciente;
} Paciente;

typedef struct Queue {
    Paciente* inicio;
    Paciente* fim;
} Queue;

Queue* initialize_queue();
int queue_exists(Queue *queue);
int queue_is_empty(Queue *queue);
int adiciona_fila_atendimento_medico(Queue *queue, int item);
int remove_item(Queue *queue);
void select_item(Queue *queue, int position);
int get_queue_size(Queue *queue);
void print_queue(Queue *queue);