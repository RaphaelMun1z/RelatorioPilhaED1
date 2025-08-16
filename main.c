#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PreCadastro_FilaEstaticaCircular/interface.h"
#include "Triagem_FilaEstaticaCircular/interface.h"
#include "FilaAtendimento_FilaDinamica/interface.h"
#include "PilhaLogAtendimento_PilhaEstatica/interface.h"
#include "PilhaPacientesInternados_PilhaDinamica/interface.h"
#include "Relatorios/relatorios.c"

void mostraMenu();
void escolheOpcao(int opcao);
void limpa_tela();

void novo_cadastro();
void nova_triagem();
void novo_atendimento_medico();
void nova_internacao();
void gerar_relatorio();

FilaCadastro preCadastroPacientes;
FilaTriagem triagemPacientes;
FilaAtendimento *atendimentoMedico;
PilhaLog pilhaLogs;
PilhaPacientesInternados *pilhaPacientesInternados;

int main(){
    inicializar_fila_pre_cadastro(&preCadastroPacientes);
    inicializar_fila_triagem(&triagemPacientes);
    atendimentoMedico = inicializar_fila_atendimento_medico();
    inicializar_pilha_logs(&pilhaLogs);
    pilhaPacientesInternados = inicializar_pilha_pacientes_internados();
    
    int opcao;
    do {
        mostraMenu();
        
        printf("\nOpção: ");
        scanf("%d", &opcao);
        getchar();
        printf("\n");
        
        escolheOpcao(opcao);
    } while (opcao != 0);
    
    return 0;
}

void mostraMenu(){
    printf("\n=========| MENU |=========\n");
    printf("[0] Sair\n");
    printf("[1] Novo Pré-Cadastro\n");
    printf("[2] Nova Triagem\n");
    printf("[3] Iniciar Atendimento Médico\n");
    printf("[4] Nova Internação\n");
    printf("[5] Gerar Relatórios\n");
    printf("__________________________\n");
}

void escolheOpcao(int opcao){
    switch(opcao){
        case 0: {
            printf("Saindo...\n");
            break;
        }
        case 1: {
            novo_cadastro();
            break;
        }
        case 2: {
            nova_triagem();
            break;
        }
        case 3: {
            novo_atendimento_medico();
            break;
        }
        case 4: {
            nova_internacao();
            break;
        }
        case 5: {
            gerar_relatorio();
            break;
        }
        default: {
            printf("Opção inválida.\n");
            break;
        }
    }
}

void limpa_tela(){
    printf("\n> PRESSIONE ALGUMA TECLA PARA CONTINUAR");
    getchar();
    system("cls");
}

void novo_cadastro(){
    printf("~~~~~~ Pré Cadastro do Paciente ~~~~~~\n");
    
    PacienteCadastro pacienteDados;
    
    printf("Nome do paciente: ");
    fgets(pacienteDados.nome, sizeof(pacienteDados.nome), stdin);
    pacienteDados.nome[strcspn(pacienteDados.nome, "\n")] = '\0';
    
    printf("CPF do paciente: ");
    fgets(pacienteDados.CPF, sizeof(pacienteDados.CPF), stdin);
    pacienteDados.CPF[strcspn(pacienteDados.CPF, "\n")] = '\0';
    
    printf("Endereço do paciente: ");
    fgets(pacienteDados.endereco, sizeof(pacienteDados.endereco), stdin);
    pacienteDados.endereco[strcspn(pacienteDados.endereco, "\n")] = '\0';
    
    cadastrar_paciente_fila_pre_cadastro(&preCadastroPacientes, pacienteDados);
    printf("[Paciente cadastrado com sucesso!]\n");
    
    limpa_tela();
}

void nova_triagem(){
    printf("~~~~~~ Triagem do Paciente ~~~~~~\n");
    
    char cpfBusca[16];
    printf("Informe o CPF do paciente: ");
    fgets(cpfBusca, sizeof(cpfBusca), stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0';
    
    PacienteCadastro *pacienteEncontrado = consultar_via_cpf_fila_pre_cadastro(&preCadastroPacientes, cpfBusca);
    if (pacienteEncontrado != NULL) {
        printf("\n=== Dados do paciente ===\n");
        printf("-> Nome: %s\n", pacienteEncontrado->nome);
        printf("-> CPF: %s\n", pacienteEncontrado->CPF);
        printf("-> Endereço: %s\n", pacienteEncontrado->endereco);
        printf("__________________________________\n\n");
        
        printf("=== Complete os dados ===\n");
        
        char dataNasc[11];
        printf("Data de Nascimento do Paciente (dd/mm/aaaa): ");
        fgets(dataNasc, sizeof(dataNasc), stdin);
        dataNasc[strcspn(dataNasc, "\n")] = '\0';
        getchar();
        
        char estadoSaude[100];
        printf("Avaliação do Estado de Saúde (descrição): ");
        fgets(estadoSaude, sizeof(estadoSaude), stdin);
        estadoSaude[strcspn(estadoSaude, "\n")] = '\0';
        
        int baseDeRisco;
        printf("Base de Risco: \n");
        printf("[1] Verde\n");
        printf("[2] Amarelo\n");
        printf("[3] Vermelho\n");
        printf("Opção escolhida: ");
        scanf("%d", &baseDeRisco);
        getchar();
        printf("\n");
        
        char sintomas[100];
        printf("Sintomas (descrição): ");
        fgets(sintomas, sizeof(sintomas), stdin);
        sintomas[strcspn(sintomas, "\n")] = '\0';
        
        Triagem triagem;
        triagem.paciente = pacienteEncontrado;
        strcpy(triagem.dataNascPaciente, dataNasc);
        strcpy(triagem.avaEstadoSaude, estadoSaude);
        triagem.baseDeRisco = baseDeRisco;
        strcpy(triagem.sintomas, sintomas);
        
        cadastrar_paciente_fila_triagem(&triagemPacientes, triagem);
        printf("[Triagem realizada com sucesso!]\n\n");
    }
    
    limpa_tela();
}

void novo_atendimento_medico(){
    printf("~~~~~~ Atendimento Médico ~~~~~~\n");
    
    char nomePaciente[100];
    printf("Informe o nome do paciente: ");
    fgets(nomePaciente, sizeof(nomePaciente), stdin);
    nomePaciente[strcspn(nomePaciente, "\n")] = '\0';
    
    Triagem *pacientePassouPelaTriagem = consultar_via_nome_fila_triagem(&triagemPacientes, nomePaciente);
    if(pacientePassouPelaTriagem != NULL){
        int tipoAtendimento = 0;
        printf("Tipo de atendimento: \n");
        printf("[0] Consulta\n");
        printf("[1] Emergência\n");
        printf("Opção escolhida: ");
        scanf("%d", &tipoAtendimento);
        getchar();
        printf("\n");
        
        adicionar_fila_atendimento_medico(atendimentoMedico, pacientePassouPelaTriagem, tipoAtendimento, &pilhaLogs);
        printf("\n[Paciente adicionado a fila de atendimento com sucesso!]\n");
    }
    
    limpa_tela();
}

void nova_internacao(){
    printf("~~~~~~ Internação ~~~~~~\n");
    
    char cpfBusca[16];
    printf("Informe o CPF do paciente: ");
    fgets(cpfBusca, sizeof(cpfBusca), stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0';
    
    PacienteFilaAtendimento *pacienteFoiAtendido = obter_paciente_via_cpf_atendimento_medico(atendimentoMedico, cpfBusca);
    if(pacienteFoiAtendido != NULL){
        avaliacao_internacao(&pacienteFoiAtendido->triagemPaciente, pilhaPacientesInternados);
    }
    
    limpa_tela();
}

void gerar_relatorio(){
    printf("~~~~~~ Relatório ~~~~~~\n");
    
    int opcaoRelatorio;
    printf("Escolha o relatório a ser gerado: \n");
    printf("[1] Relatório de pacientes cadastrados\n");
    printf("[2] Relatório de pacientes internados\n");
    scanf("%d", &opcaoRelatorio);
    getchar();
    printf("\n");
    
    switch (opcaoRelatorio)
    {
        case 1:{
            GerarRelatorioTotalPacientesCadastrados(&preCadastroPacientes);
            break;
        }
        case 2:{
            GerarRelatorioTotalPacientesInternados(pilhaPacientesInternados);
            break;
        }
        default:{
            printf("Valor inválido!\n");
            break;
        }
    }
    
    limpa_tela();
}