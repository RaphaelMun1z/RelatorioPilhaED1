#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

Queue* initialize_queue() {
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    if(new_queue == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        return NULL;
    }
    
    new_queue->inicio = NULL;
    new_queue->fim = NULL;
    
    return new_queue;
}

int queue_exists(Queue *queue) {
    return queue != NULL;
}

int queue_is_empty(Queue *queue) {
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada.\n");
        return -1;
    }
    return queue->inicio == NULL;
}

int adiciona_fila_atendimento_medico(Queue *queue, int item) {
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada, não é possível inserir.\n");
        return 0;
    }
    
    Paciente* novo_no = (Paciente*) malloc(sizeof(Paciente));
    if(novo_no == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        return 0;
    }
    
    // novo_no->nome[0] = "";
    // novo_no->CPF[0] = "";
    // novo_no->endereco = "";
    // novo_no->tipoCaso = 0; 
    novo_no->proxPaciente = NULL;
    
    if(queue->inicio == NULL){
        queue->inicio = novo_no;
    }else{
        queue->fim->proxPaciente = novo_no;
    }
    queue->fim = novo_no;
}

int remove_item(Queue *queue) {
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada, não é possível remover.\n");
        return 0;
    }
    
    Paciente* begin_no = queue->inicio;
    if(queue_is_empty(queue)) {
        printf("A fila está vazia, não é possível remover.\n");
        return 0;
    }
    
    queue->inicio = begin_no->proxPaciente;
    begin_no->proxPaciente = NULL;
    int item = begin_no->paciente;
    free(begin_no);
    
    if(queue->inicio == NULL)
    queue->fim = NULL;
    
    return item;
}

void select_item(Queue *queue, int position) {
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada, não é possível consultar.\n");
        return;
    }
    
    if(queue_is_empty(queue)) {
        printf("A fila está vazia, não é possível consultar.\n");
        return;
    }
    
    Paciente* current = queue->inicio;
    int currentPosition = 0;
    while(current != NULL) {
        if(currentPosition == position) {
            printf("Item encontrado: %d\n", current->paciente);
            return;
        }
        current = current->proxPaciente;
    }
    
    printf("Posição não encontrada na fila.\n");
}

int get_queue_size(Queue *queue){
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada, não é possível obter o tamanho.\n");
        return -1;
    }
    
    if(queue_is_empty(queue)) {
        return 0;
    }
    
    int size = 0;
    Paciente* current = queue->inicio;
    while(current != NULL) {
        size++;
        current = current->proxPaciente;
    }
    
    return size;
}

void print_queue(Queue *queue) {
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada, não é possível imprimir.\n");
        return;
    }
    
    if(queue_is_empty(queue)) {
        printf("A fila está vazia, não é possível imprimir.\n");
        return;
    }
    
    Paciente* current = queue->inicio;
    printf("\nFila: \n");
    while(current != NULL) {
        printf("%d\n", current->paciente);
        current = current->proxPaciente;
    }
}