#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void inicializar_pilha_registro_atendimento(Pilha *p){
    for (int ii = 0; ii < TAM_PILHA; ii++){
        p->dados[ii] = 0;
    }
    p->topo = 0;
}

int pilha_cheia_registro_atendimento(Pilha *p){
    if(p->topo == TAM_PILHA){
        return 1;
    }
    return 0;
}

int pilha_vazia_registro_atendimento(Pilha *p){
    if(p->topo == 0){
        return 1;
    }
    return 0;
}

void adicionar_registro_atendimento(Pilha *p, int valor){
    if(pilhaCheia(p) == 1){
        printf("Pilha cheia! Não é possível empilhar.\n");
        return;
    }
    
    p->dados[p->topo] = valor;
    p->topo++;
    printf("Empilhado com sucesso.\n");
}

int remover_registro_atendimento(Pilha *p){
    if(pilhaVazia(p) == 1){
        printf("Pilha vazia! Não é possível desempilhar.\n");
        return -1;
    }
    
    p->topo--;
    printf("Desempilhado com sucesso.\n");
    return p->dados[p->topo];
}

void imprimir_pilha_registro_atendimento(Pilha *p){
    if(pilhaVazia(p) == 1){
        printf("Pilha vazia! Não há elementos para imprimir.\n");
        return;
    }
    
    printf("Elementos da pilha:\n");
    for(int ii = p->topo - 1; ii >= 0; ii--){
        printf("| %d |\n", p->dados[ii]);
    }
}