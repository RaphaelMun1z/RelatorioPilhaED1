#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void inicializar_fila_pre_cadastro(FilaCadastro* fila) {
    printf("Inicializando a fila...\n");
    fila->inicio = 0;
    fila->final = 0;
    fila->size = 0;
}

int fila_vazia_pre_cadastro(FilaCadastro *fila){
    return fila->size == 0;
}

int fila_cheia_pre_cadastro(FilaCadastro *fila){
    return fila->size == MAX_PACIENTES_PRE_CADASTRO;
}

int obter_tamanho_fila_pre_cadastro(FilaCadastro *fila){
    return fila->size;
}

void cadastrar_paciente_fila_pre_cadastro(FilaCadastro *fila, PacienteCadastro pacienteDados){
    if (fila_cheia_pre_cadastro(fila)) {
        return;
    }
    
    fila->pacientes[fila->final] = pacienteDados;
    fila->final = (fila->final + 1) % MAX_PACIENTES_PRE_CADASTRO;
    fila->size++;
    
    printf("\n\n=== Dados do paciente cadastrado ===\n");
    printf("-> Nome: %s\n", pacienteDados.nome);
    printf("-> CPF: %s\n", pacienteDados.CPF);
    printf("-> Endereço: %s\n", pacienteDados.endereco);
    printf("__________________________________\n\n");
}

void remover_paciente_fila_pre_cadastro(FilaCadastro *fila){
    if (fila_vazia_pre_cadastro(fila)) {
        return;
    }
    
    PacienteCadastro paciente_removido = fila->pacientes[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_PACIENTES_PRE_CADASTRO;
    fila->size--;
    printf("\nPaciente %s removido da fila.\n", paciente_removido.nome);
}

PacienteCadastro* consultar_via_cpf_fila_pre_cadastro(FilaCadastro *fila, char cpf[]){
    if (fila_vazia_pre_cadastro(fila)) {
        printf("\nA fila está vazia. Nenhum paciente cadastrado.\n");
        return NULL;
    }
    
    int pacienteAtual = fila->inicio;
    for (int ii = 0; ii < fila->size; ii++) {
        if (strcmp(fila->pacientes[pacienteAtual].CPF, cpf) == 0) {
            return &fila->pacientes[pacienteAtual];
        }
        pacienteAtual = (pacienteAtual + 1) % MAX_PACIENTES_PRE_CADASTRO;
    }

    printf("\nPaciente com CPF %s não encontrado na fila.\n", cpf);
    return NULL;
}

void imprime_fila_pre_cadastro(FilaCadastro *fila){
    if (fila_vazia_pre_cadastro(fila)) {
        printf("\nFila: [ ] (vazia)\n");
        return;
    }
    
    printf("\n--- ESTADO ATUAL DA FILA ---\n");
    printf("Indices: Inicio=%d | Fim=%d | Quantidade=%d\n", fila->inicio, fila->final, fila->size);
    printf("FilaCadastro: [ ");
    
    int pacienteAtual = fila->inicio;
    for (int i = 0; i < fila->size; i++) {
        printf("Nome: %s ", fila->pacientes[pacienteAtual].nome);
        pacienteAtual = (pacienteAtual + 1) % MAX_PACIENTES_PRE_CADASTRO;
    }
    printf("]\n---------------------------\n");
}
