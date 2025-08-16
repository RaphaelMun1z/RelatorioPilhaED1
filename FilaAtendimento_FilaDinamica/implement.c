#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "../PreCadastro_FilaEstaticaCircular/interface.h"

FilaAtendimento* inicializar_fila_atendimento_medico() {
    FilaAtendimento* new_queue = (FilaAtendimento*) malloc(sizeof(FilaAtendimento));
    if(new_queue == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        return NULL;
    }
    
    new_queue->inicio = NULL;
    new_queue->fim = NULL;
    
    return new_queue;
}

int fila_existe_atendimento_medico(FilaAtendimento *fila) {
    return fila != NULL;
}

int fila_vazia_atendimento_medico(FilaAtendimento *fila) {
    if(!fila_existe_atendimento_medico(fila)) {
        printf("A fila não foi inicializada.\n");
        return -1;
    }
    return fila->inicio == NULL;
}

void adicionar_fila_atendimento_medico(FilaAtendimento *fila, PacienteCadastro *pacienteCadastrado, int tipoAtendimento) {
    if(!fila_existe_atendimento_medico(fila)) {
        printf("A fila não foi inicializada, não é possível inserir.\n");
        return;
    }
    
    PacienteFilaAtendimento *no_paciente = (PacienteFilaAtendimento*) malloc(sizeof(PacienteFilaAtendimento));
    if(no_paciente == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        return;
    }
    
    no_paciente->pacienteDadosPadrao = *pacienteCadastrado;
    no_paciente->tipoAtendimento = tipoAtendimento; 
    no_paciente->proxPaciente = NULL;
    
    if(fila->inicio == NULL){
        fila->inicio = no_paciente;
    }else{
        fila->fim->proxPaciente = no_paciente;
    }
    fila->fim = no_paciente;
}

void remover_paciente_fila_atendimento_medico(FilaAtendimento *fila) {
    if(!fila_existe_atendimento_medico(fila)) {
        printf("A fila não foi inicializada, não é possível remover.\n");
        return;
    }
    
    PacienteFilaAtendimento* paciente_inicio = fila->inicio;
    if(fila_vazia_atendimento_medico(fila)) {
        printf("A fila está vazia, não é possível remover.\n");
        return;
    }
    
    fila->inicio = paciente_inicio->proxPaciente;
    paciente_inicio->proxPaciente = NULL;
    
    PacienteFilaAtendimento pacienteRemovido = *(paciente_inicio);
    free(paciente_inicio);
    
    if(fila->inicio == NULL){
        fila->fim = NULL;
    }
    
    printf("PacienteFilaAtendimento %s removido com sucesso!\n", pacienteRemovido.pacienteDadosPadrao.nome);
}

int obter_tamanho_fila_atendimento_medico(FilaAtendimento *fila){
    if(!fila_existe_atendimento_medico(fila)) {
        printf("A fila não foi inicializada, não é possível obter o tamanho.\n");
        return -1;
    }
    
    if(fila_vazia_atendimento_medico(fila)) {
        return 0;
    }
    
    int size = 0;
    PacienteFilaAtendimento* current = fila->inicio;
    while(current != NULL) {
        size++;
        current = current->proxPaciente;
    }
    
    return size;
}

void imprimir_fila_atendimento_medico(FilaAtendimento *fila) {
    if(!fila_existe_atendimento_medico(fila)) {
        printf("A fila não foi inicializada, não é possível imprimir.\n");
        return;
    }
    
    if(fila_vazia_atendimento_medico(fila)) {
        printf("A fila está vazia, não é possível imprimir.\n");
        return;
    }
    
    PacienteFilaAtendimento* pacienteAtual = fila->inicio;
    printf("\nFila: \n");
    while(pacienteAtual != NULL) {
        printf("CPF: %s\n", pacienteAtual->pacienteDadosPadrao.CPF);
        pacienteAtual = pacienteAtual->proxPaciente;
    }
}