#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"
#include "../PilhaPacientesInternados_PilhaDinamica/interface.h"
#include "../Triagem_FilaEstaticaCircular/interface.h"

PilhaPacientesInternados* inicializar_pilha_pacientes_internados(){
    printf("Inicializando a pilha pacientes internados...\n");
    
    PilhaPacientesInternados *p = (PilhaPacientesInternados *) malloc(sizeof(PilhaPacientesInternados));
    if(p == NULL){
        printf("Erro ao alocar memória para a pilha.\n");
        return NULL;
    }
    
    p->topo = NULL;
    return p;
}

int pilha_vazia_pacientes_internados(PilhaPacientesInternados *p){
    if(p->topo == NULL){
        return 1;
    }
    return 0;
}

void adicionar_pacientes_internados(PilhaPacientesInternados *p, PacienteInternado dadosPacienteInternado){
    PacienteInternado *no_novo_paciente_internado = (PacienteInternado *) malloc(sizeof(PacienteInternado));
    if(no_novo_paciente_internado == NULL){
        printf("Erro ao alocar memória para o novo nó.\n");
        return;
    }
    
    no_novo_paciente_internado = &dadosPacienteInternado;
    no_novo_paciente_internado->proxPaciente = p->topo;
    
    p->topo = no_novo_paciente_internado;
    
    printf("\n[Paciente internado com sucesso.]\n");
}

void avaliacao_internacao(Triagem *pacienteTriagem, PilhaPacientesInternados *pilhaPacientesInternados){    
    double B;
    switch (pacienteTriagem->baseDeRisco){
        case 1:{
            B = 5;
            break;
        }
        case 2:{
            B = 10;
            break;
        }
        case 3:{
            B = 30;
            break;
        }
        default:{
            B = 0;
            break;
        }
    }
    
    double P;
    printf("Informe o peso clínico (0 a 1, sendo 1 caso grave): ");
    scanf("%lf", &P);
    
    double F;
    printf("Informe o fator de agravantes: \n");
    printf("[0] Nenhum\n");
    printf("[1] Leve\n");
    printf("[2] Grave\n");
    scanf("%lf", &F);
    getchar();
    printf("\n");
    
    double chance = (B * P) + (F * 5);
    
    int ehParaInternar = chance >= 25 ? 1 : 0;
    
    if(!ehParaInternar){
        printf("[Não há a necessidade de internação!]\n");
        return;
    }
    
    printf("\n=== Dados para internação ===\n");
    PacienteInternado dadosPacienteInternado;
    strcpy(dadosPacienteInternado.nome, pacienteTriagem->paciente->nome);
    
    printf("Informe a dieta do paciente: ");
    fgets(dadosPacienteInternado.dieta, sizeof(dadosPacienteInternado.dieta), stdin);
    dadosPacienteInternado.dieta[strcspn(dadosPacienteInternado.dieta, "\n")] = '\0';
    
    printf("Informe as medicações do paciente: ");
    fgets(dadosPacienteInternado.medicacoesDeRotina, sizeof(dadosPacienteInternado.medicacoesDeRotina), stdin);
    dadosPacienteInternado.medicacoesDeRotina[strcspn(dadosPacienteInternado.medicacoesDeRotina, "\n")] = '\0';
    
    printf("Informe o tratamento do paciente: ");
    fgets(dadosPacienteInternado.tratamento, sizeof(dadosPacienteInternado.tratamento), stdin);
    dadosPacienteInternado.tratamento[strcspn(dadosPacienteInternado.tratamento, "\n")] = '\0';
    
    adicionar_pacientes_internados(pilhaPacientesInternados, dadosPacienteInternado);
}

void remover_pacientes_internados(PilhaPacientesInternados *p){
    if(pilha_vazia_pacientes_internados(p) == 1){
        printf("PilhaPacientesInternados vazia! Não é possível desempilhar.\n");
        return;
    }
    
    PacienteInternado *noDeletado = p->topo;
    
    p->topo = noDeletado->proxPaciente;
    noDeletado->proxPaciente = NULL;
    
    free(noDeletado);
    printf("Paciente removido da internação com sucesso.\n");
}

void imprimer_pilha_pacientes_internados(PilhaPacientesInternados *p){
    if(pilha_vazia_pacientes_internados(p) == 1){
        printf("PilhaPacientesInternados vazia! Não há elementos para imprimir.\n");
        return;
    }
    
    printf("Elementos da pilha:\n");
    PacienteInternado *atual = p->topo;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        atual = atual->proxPaciente;
    }
}

PilhaPacientesInternados* liberar_pilha_pacientes_internados(PilhaPacientesInternados *p){
    if(p == NULL){
        printf("PilhaPacientesInternados ainda não foi inicializada.\n");
        return p;
    }
    
    PacienteInternado *noDeletar;
    while (p->topo != NULL) {
        noDeletar = p->topo;
        p->topo = noDeletar->proxPaciente;
        free(noDeletar);
    }
    
    free(p);
    
    printf("PilhaPacientesInternados liberada com sucesso.\n");
    return NULL;
}