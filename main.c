#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PreCadastro_FilaEstaticaCircular/interface.h"
#include "FilaAtendimento_FilaDinamica/interface.h"

void mostraMenu();
void escolheOpcao(int opcao);
void limpa_entrada();
void limpa_tela();

void novo_cadastro();
void nova_triagem();
void novo_atendimento_medico();

FilaCadastro preCadastroPacientes;
FilaAtendimento *atendimentoMedico;

int main(){
    inicializar_fila_pre_cadastro(&preCadastroPacientes);
    atendimentoMedico = inicializar_fila_atendimento_medico();
    
    int opcao;
    do {
        mostraMenu();
        
        printf("\nOpção: ");
        scanf("%d", &opcao);
        limpa_entrada();
        printf("\n");
        
        escolheOpcao(opcao);
        limpa_tela();
    } while (opcao != 0);
    
    return 0;
}

void mostraMenu(){
    printf("\n=========| MENU |=========\n");
    printf("[0] Sair\n");
    printf("[1] Novo Cadastro\n");
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
            printf("Opção 04");
            break;
        }
        case 5: {
            printf("Opção 05");
            break;
        }
        default: {
            printf("Opção inválida.\n");
            break;
        }
    }
}

void limpa_entrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void limpa_tela(){
    printf("\n[Pressione alguma tecla para continuar]");
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
    
    limpa_tela();
    cadastrar_paciente_fila_pre_cadastro(&preCadastroPacientes, pacienteDados);
    printf("[Paciente cadastrado com sucesso!]\n");
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
        
        char estadoSaude[100];
        printf("Avaliação do Estado de Saúde (descrição): ");
        fgets(estadoSaude, sizeof(estadoSaude), stdin);
        estadoSaude[strcspn(estadoSaude, "\n")] = '\0';
        
        int prioridade;
        printf("Prioridade: \n");
        printf("[1] Verde\n");
        printf("[2] Amarelo\n");
        printf("[3] Vermelho\n");
        printf("Opção escolhida: ");
        scanf("%d", &prioridade);
        printf("\n");
        
        char sintomas[100];
        printf("Sintomas (descrição): ");
        fgets(sintomas, sizeof(sintomas), stdin);
        sintomas[strcspn(sintomas, "\n")] = '\0';
        
        Triagem triagem;
        triagem.paciente = pacienteEncontrado;
        strcpy(triagem.dataNascPaciente, dataNasc);
        strcpy(triagem.avaEstadoSaude, estadoSaude);
        triagem.prioridade = prioridade;
        strcpy(triagem.sintomas, sintomas);
        
        int tipoAtendimento = 0;
        printf("Tipo de atendimento: \n");
        printf("[0] Consulta\n");
        printf("[1] Emergência\n");
        printf("Opção escolhida: ");
        scanf("%d", &tipoAtendimento);
        printf("\n");
        
        getchar();
        printf("[Triagem realizada com sucesso!]\n");
        limpa_tela();
        
        // Entrar na fila para atendimento médico
        adicionar_fila_atendimento_medico(atendimentoMedico, pacienteEncontrado, tipoAtendimento);
        printf("[Paciente adicionado a fila de atendimento com sucesso!]\n");
    }
}

void novo_atendimento_medico(){
    printf("Atendimento Médico: \n");
    
    
}