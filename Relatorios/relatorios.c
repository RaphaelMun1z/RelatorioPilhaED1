#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../interfaces/interfaces.h"
#include "../PilhaPacientesInternados_PilhaDinamica/interface.h"
#include "../PreCadastro_FilaEstaticaCircular/interface.h"

void GerarRelatorioTotalPacientesCadastrados(FilaCadastro *pacientesCadastrados){
    if(fila_vazia_pre_cadastro(pacientesCadastrados)){
        printf("Não foi possível gerar o relatório. Não há pacientes cadastrados!\n");
        return;
    }
    
    FILE *arquivo = fopen("Relatorios/PacientesCadastrados.txt", "w");
    
    if (arquivo == NULL) {
        printf("[Ocorreu um erro ao tentar abrir o arquivo!]\n");
        return;
    }
    
    fprintf(arquivo, "==============================| RELATORIO DE PACIENTES CADASTRADOS |==============================\n");
    fprintf(arquivo, "%-30s %-20s %-50s\n", "NOME", "CPF", "ENDEREÇO");
    fprintf(arquivo, "--------------------------------------------------------------------------------------------------\n");
    
    int pacienteAtual = pacientesCadastrados->inicio;
    for (int ii = 0; ii < pacientesCadastrados->size; ii++) {
        fprintf(arquivo, "%-30s %-20s %-50s\n", pacientesCadastrados->pacientes[pacienteAtual].nome, pacientesCadastrados->pacientes[pacienteAtual].CPF, pacientesCadastrados->pacientes[pacienteAtual].endereco);            
        pacienteAtual = (pacienteAtual + 1) % MAX_PACIENTES_PRE_CADASTRO;
    }
    
    fprintf(arquivo, "--------------------------------------------------------------------------------------------------\n\n");
    fprintf(arquivo, "Total de pacientes cadastrados: %d\n", pacientesCadastrados->size);
    fprintf(arquivo, "\n==================================================================================================\n");
    
    fclose(arquivo);
    printf("Relatorio gerado com sucesso!\n");
}

void GerarRelatorioTotalPacientesInternados(PilhaPacientesInternados *pacientesInternados){
    if(pacientesInternados == NULL){
        printf("A pilha ainda não foi inicializada!\n");
        return;
    }
    
    if(pilha_vazia_pacientes_internados(pacientesInternados) == 1){
        printf("Não foi possível gerar o relatório. Não há pacientes internados.\n");
        return;
    }
    
    FILE *arquivo = fopen("Relatorios/PacientesInternados.txt", "w");
    
    if (arquivo == NULL) {
        printf("[Ocorreu um erro ao tentar abrir o arquivo!]\n");
        return;
    }
    
    fprintf(arquivo, "================================================| RELATORIO DE PACIENTES CADASTRADOS |================================================\n");
    fprintf(arquivo, "%-30s %-30s %-40s %-40s\n", "NOME", "DIETA", "MEDICAÇÕES", "TRATAMENTO");
    fprintf(arquivo, "--------------------------------------------------------------------------------------------------------------------------------------\n"); 
    
    int quantidadePacientes = 0;
    PacienteInternado *atual = pacientesInternados->topo;
    while (atual != NULL) {
        quantidadePacientes++;
        fprintf(arquivo, "%-30s %-30s %-40s %-40s\n", atual->nome, atual->dieta, atual->medicacoesDeRotina, atual->tratamento);             
        atual = atual->proxPaciente;
    }
    
    fprintf(arquivo, "--------------------------------------------------------------------------------------------------------------------------------------\n\n"); 
    fprintf(arquivo, "Total de pacientes internados: %d\n", quantidadePacientes);
    fprintf(arquivo, "\n======================================================================================================================================\n");
    
    fclose(arquivo);
    printf("Relatorio gerado com sucesso!\n");
}