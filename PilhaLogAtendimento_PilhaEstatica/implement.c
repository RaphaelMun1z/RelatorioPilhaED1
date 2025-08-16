#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void inicializar_pilha_logs(PilhaLog *p){
    printf("Inicializando a pilha logs...\n");
    
    p->topo = 0;
}

int pilha_cheia_logs(PilhaLog *p){
    if(p->topo == TAM_PILHA_LOGS){
        return 1;
    }
    return 0;
}

int pilha_vazia_logs(PilhaLog *p){
    if(p->topo == 0){
        return 1;
    }
    return 0;
}

void adicionar_log(PilhaLog *p, NoLog novoLog){
    if(pilha_cheia_logs(p) == 1){
        printf("PilhaLog cheia! Não é possível criar log.\n");
        return;
    }
    
    p->logs[p->topo] = novoLog;
    p->topo++;
    printf("\n[Log criado com sucesso!]\n");
}

void remover_log(PilhaLog *p){
    if(pilha_vazia_logs(p) == 1){
        printf("PilhaLog vazia! Não é possível desempilhar.\n");
        return;
    }
    
    p->topo--;
    printf("Desempilhado com sucesso.\n");
}

void imprimer_pilha_logs(PilhaLog *p){
    if(pilha_vazia_logs(p) == 1){
        printf("PilhaLog vazia! Não há elementos para imprimir.\n");
        return;
    }
    
    printf("Elementos da pilha:\n");
    for(int ii = p->topo - 1; ii >= 0; ii--){
        printf("Hora início: %s \n", p->logs[ii].horaInicio.hora);
    }
}