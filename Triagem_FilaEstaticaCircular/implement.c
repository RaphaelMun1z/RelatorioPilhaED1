#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"

void inicializar_fila_triagem(FilaTriagem *fila) {
    printf("Inicializando a fila de triagem...\n");
    fila->inicio = 0;
    fila->final = 0;
    fila->size = 0;
}

int fila_vazia_triagem(FilaTriagem *fila){
    return fila->size == 0;
}

int fila_cheia_triagem(FilaTriagem *fila){
    return fila->size == MAX_PACIENTES_TRIAGEM;
}

int obter_tamanho_fila_triagem(FilaTriagem *fila){
    return fila->size;
}

void cadastrar_paciente_fila_triagem(FilaTriagem *fila, Triagem pacienteTriagem){
    if (fila_cheia_triagem(fila)) {
        return;
    }
    
    fila->triagens[fila->final] = pacienteTriagem;
    fila->final = (fila->final + 1) % MAX_PACIENTES_TRIAGEM;
    fila->size++;
}

void remover_paciente_fila_triagem(FilaTriagem *fila){
    if (fila_vazia_triagem(fila)) {
        return;
    }
    
    Triagem paciente_removido = fila->triagens[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_PACIENTES_TRIAGEM;
    fila->size--;
    printf("\nPaciente %s removido da fila de triagem.\n", paciente_removido.paciente->nome);
}

Triagem* consultar_via_cpf_fila_triagem(FilaTriagem *fila, char cpf[]){
    if (fila_vazia_triagem(fila)) {
        printf("\nA fila está vazia. Nenhum paciente cadastrado.\n");
        return NULL;
    }
    
    int pacienteAtual = fila->inicio;
    for (int ii = 0; ii < fila->size; ii++) {
        if (strcmp(fila->triagens[pacienteAtual].paciente->CPF, cpf) == 0) {
            return &fila->triagens[pacienteAtual];
        }
        pacienteAtual = (pacienteAtual + 1) % MAX_PACIENTES_TRIAGEM;
    }

    printf("\nPaciente com CPF %s não encontrado na fila da triagem.\n", cpf);
    return NULL;
}

Triagem* consultar_via_nome_fila_triagem(FilaTriagem *fila, char nome[]){
    if (fila_vazia_triagem(fila)) {
        printf("\nA fila está vazia. Nenhum paciente cadastrado.\n");
        return NULL;
    }
    
    int pacienteAtual = fila->inicio;
    for (int ii = 0; ii < fila->size; ii++) {
        if (strcmp(fila->triagens[pacienteAtual].paciente->nome, nome) == 0) {
            return &fila->triagens[pacienteAtual];
        }
        pacienteAtual = (pacienteAtual + 1) % MAX_PACIENTES_TRIAGEM;
    }

    printf("\nPaciente com nome %s não encontrado na fila da triagem.\n", nome);
    return NULL;
}

void imprime_fila_triagem(FilaTriagem *fila){
    if (fila_vazia_triagem(fila)) {
        printf("\nFila: [ ] (vazia)\n");
        return;
    }
    
    printf("\n--- ESTADO ATUAL DA FILA ---\n");
    printf("Indices: Inicio=%d | Fim=%d | Quantidade=%d\n", fila->inicio, fila->final, fila->size);
    printf("FilaTriagem: [ ");
    
    int pacienteAtual = fila->inicio;
    for (int i = 0; i < fila->size; i++) {
        printf("Nome: %s ", fila->triagens[pacienteAtual].paciente->nome);
        pacienteAtual = (pacienteAtual + 1) % MAX_PACIENTES_TRIAGEM;
    }
    printf("]\n---------------------------\n");
}
