#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"
#include "../PreCadastro_FilaEstaticaCircular/interface.h"
#include "../PilhaLogAtendimento_PilhaEstatica/interface.h"

FilaAtendimento* inicializar_fila_atendimento_medico() {
    printf("Inicializando a fila atendimento médico...\n");
    
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

void adicionar_fila_atendimento_medico(FilaAtendimento *fila, Triagem *pacienteTriagem, int tipoAtendimento, PilhaLog *pilhaLogs) {
    if(!fila_existe_atendimento_medico(fila)) {
        printf("A fila não foi inicializada, não é possível inserir.\n");
        return;
    }
    
    PacienteFilaAtendimento *no_paciente = (PacienteFilaAtendimento*) malloc(sizeof(PacienteFilaAtendimento));
    if(no_paciente == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        return;
    }
    
    no_paciente->triagemPaciente = *pacienteTriagem;
    no_paciente->tipoAtendimento = tipoAtendimento; 
    no_paciente->proxPaciente = NULL;
    
    if(fila->inicio == NULL){
        fila->inicio = no_paciente;
    }else{
        fila->fim->proxPaciente = no_paciente;
    }
    fila->fim = no_paciente;
    
    // Gerar LOG
    adicionar_log(pilhaLogs, prepara_novo_log());
}

NoLog prepara_novo_log(){
    printf("~~~ Dados para LOG ~~~\n");
    
    NoLog novoLog;
    
    Horario horaInicio;
    printf("=== Horário início do atendimento ===\n");
    printf("Hora: ");
    fgets(horaInicio.hora, sizeof(horaInicio.hora), stdin);
    horaInicio.hora[strcspn(horaInicio.hora, "\n")] = '\0';
    
    printf("Minuto: ");
    fgets(horaInicio.minuto, sizeof(horaInicio.minuto), stdin);
    horaInicio.minuto[strcspn(horaInicio.minuto, "\n")] = '\0';
    
    printf("Segundo: ");
    fgets(horaInicio.segundo, sizeof(horaInicio.segundo), stdin);
    horaInicio.segundo[strcspn(horaInicio.segundo, "\n")] = '\0';
    
    Horario horaTermino;
    printf("=== Horário término do atendimento ===\n");
    printf("Hora: ");
    fgets(horaTermino.hora, sizeof(horaTermino.hora), stdin);
    horaTermino.hora[strcspn(horaTermino.hora, "\n")] = '\0';
    
    printf("Minuto: ");
    fgets(horaTermino.minuto, sizeof(horaTermino.minuto), stdin);
    horaTermino.minuto[strcspn(horaTermino.minuto, "\n")] = '\0';
    
    printf("Segundo: ");
    fgets(horaTermino.segundo, sizeof(horaTermino.segundo), stdin);
    horaTermino.segundo[strcspn(horaTermino.segundo, "\n")] = '\0';
    
    double cidPaciente = 1.0;
    
    novoLog.horaInicio = horaInicio;
    novoLog.horaTermino = horaTermino;
    novoLog.cidDiagPac = cidPaciente;
    
    return novoLog;
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
    
    printf("PacienteFilaAtendimento %s removido com sucesso!\n", pacienteRemovido.triagemPaciente.paciente->nome);
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
        printf("CPF: %s\n", pacienteAtual->triagemPaciente.paciente->CPF);
        pacienteAtual = pacienteAtual->proxPaciente;
    }
}

PacienteFilaAtendimento* obter_paciente_via_nome_atendimento_medico(FilaAtendimento *fila, char nome[]){
    if(!fila_existe_atendimento_medico(fila)) {
        printf("A fila não foi inicializada, não é possível imprimir.\n");
        return NULL;
    }
    
    if(fila_vazia_atendimento_medico(fila)) {
        printf("A fila está vazia, não é possível imprimir.\n");
        return NULL;
    }
    
    PacienteFilaAtendimento *pacienteAtual = fila->inicio;
    while(pacienteAtual != NULL) {
        if (strcmp(pacienteAtual->triagemPaciente.paciente->nome, nome) == 0) {
            return pacienteAtual;
        }
        pacienteAtual = pacienteAtual->proxPaciente;
    }
    
    printf("\nPaciente com Nome %s não encontrado na fila.\n", nome);
    return NULL;
}

PacienteFilaAtendimento* obter_paciente_via_cpf_atendimento_medico(FilaAtendimento *fila, char cpf[]){
    if(!fila_existe_atendimento_medico(fila)) {
        printf("A fila não foi inicializada, não é possível imprimir.\n");
        return NULL;
    }
    
    if(fila_vazia_atendimento_medico(fila)) {
        printf("A fila está vazia, não é possível imprimir.\n");
        return NULL;
    }
    
    PacienteFilaAtendimento *pacienteAtual = fila->inicio;
    while(pacienteAtual != NULL) {
        if (strcmp(pacienteAtual->triagemPaciente.paciente->CPF, cpf) == 0) {
            return pacienteAtual;
        }
        pacienteAtual = pacienteAtual->proxPaciente;
    }
    
    printf("\nPaciente com CPF %s não encontrado na fila.\n", cpf);
    return NULL;
}