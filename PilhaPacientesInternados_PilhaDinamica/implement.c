#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

Pilha* inicializaPilha(){
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    if(p == NULL){
        printf("Erro ao alocar memória para a pilha.\n");
        return NULL;
    }

    p->topo = NULL;
    return p;
}

int pilhaVazia(Pilha *p){
    if(p->topo == NULL){
        return 1;
    }
    return 0;
}

void empilha(Pilha *p, int valor){
    PacienteInternado *novoNo = (PacienteInternado *) malloc(sizeof(PacienteInternado));
    if(novoNo == NULL){
        printf("Erro ao alocar memória para o novo nó.\n");
        return;
    }
    novoNo->dado = valor;
    novoNo->proxPaciente = p->topo;
    
    p->topo = novoNo;
    printf("Empilhado com sucesso.\n");
}

int desempilha(Pilha *p){
    if(pilhaVazia(p) == 1){
        printf("Pilha vazia! Não é possível desempilhar.\n");
        return -1;
    }
    
    PacienteInternado *noDeletado = p->topo;
    
    p->topo = noDeletado->proxPaciente;
    noDeletado->proxPaciente = NULL;
    int dado = noDeletado->dado;
    
    free(noDeletado);
    printf("Desempilhado com sucesso.\n");
    return dado;
}

void imprimePilha(Pilha *p){
    if(pilhaVazia(p) == 1){
        printf("Pilha vazia! Não há elementos para imprimir.\n");
        return;
    }
    
    printf("Elementos da pilha:\n");
    PacienteInternado *atual = p->topo;
    while (atual != NULL) {
        printf("| %d |\n", atual->dado);
        atual = atual->proxPaciente;
    }
}

Pilha* liberaPilha(Pilha *p){
    if(p == NULL){
        printf("Pilha ainda não foi inicializada.\n");
        return p;
    }

    PacienteInternado *noDeletar;
    while (p->topo != NULL) {
        noDeletar = p->topo;
        p->topo = noDeletar->proxPaciente;
        free(noDeletar);
    }

    free(p);

    printf("Pilha liberada com sucesso.\n");
    return NULL;
}