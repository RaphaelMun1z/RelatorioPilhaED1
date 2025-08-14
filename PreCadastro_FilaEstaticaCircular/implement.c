#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void inicializa_fila(Fila* fila) {
    printf("Inicializando a fila...\n");
    fila->inicio = 0;
    fila->final = 0;
    fila->size = 0;
}

int fila_is_empty(Fila *fila){
    return fila->size == 0;
}

int fila_is_full(Fila *fila){
    return fila->size == N;
}

int fila_size(Fila *fila){
    return fila->size;
}

void cadastra_novo_paciente(Fila *fila, Paciente pacienteDados){
    if (fila_is_full(fila)) {
        return;
    }
    
    fila->pacientes[fila->final] = pacienteDados;
    fila->final = (fila->final + 1) % N;
    fila->size++;
    
    printf("Dados do paciente cadastrado:\n");
    printf("Nome: %s\n", pacienteDados.nome);
    printf("CPF: %s\n", pacienteDados.CPF);
    printf("Endereço: %s\n", pacienteDados.endereco);
}

void remove_paciente(Fila *fila){
    if (fila_is_empty(fila)) {
        return;
    }
    
    Paciente paciente_removido = fila->pacientes[fila->inicio];
    fila->inicio = (fila->inicio + 1) % N;
    fila->size--;
    printf("\nPaciente %s removido da fila.\n", paciente_removido.nome);
}

Paciente* consulta_cpf(Fila *fila, char cpf[11]){
    if (fila_is_empty(fila)) {
        printf("\nA fila está vazia. Nenhum paciente cadastrado.\n");
        return NULL;
    }
    
    int pacienteAtual = fila->inicio;
    for (int ii = 0; ii < fila->size; ii++) {
        if (strcmp(fila->pacientes[pacienteAtual].CPF, cpf) == 0) {
            return &fila->pacientes[pacienteAtual];
        }
        pacienteAtual = (pacienteAtual + 1) % N;
    }

    printf("\nPaciente com CPF %s não encontrado na fila.\n", cpf);
    return NULL;
}

void imprime_fila(Fila *fila){
    if (fila_is_empty(fila)) {
        printf("\nFila: [ ] (vazia)\n");
        return;
    }
    
    printf("\n--- ESTADO ATUAL DA FILA ---\n");
    printf("Indices: Inicio=%d | Fim=%d | Quantidade=%d\n", fila->inicio, fila->final, fila->size);
    printf("Fila: [ ");
    
    int pacienteAtual = fila->inicio;
    for (int i = 0; i < fila->size; i++) {
        printf("Nome: %s ", fila->pacientes[pacienteAtual].nome);
        pacienteAtual = (pacienteAtual + 1) % N;
    }
    printf("]\n---------------------------\n");
}
