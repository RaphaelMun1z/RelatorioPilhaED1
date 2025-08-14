#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PreCadastro_FilaEstaticaCircular/interface.h"
#include "FilaAtendimento_FilaDinamica/interface.h"

void mostraMenu();
void escolheOpcao(int opcao);
void limpa_entrada();

Fila preCadastroPacientes;
Fila atendimentoMedico;

int main(){
    inicializa_fila(&preCadastroPacientes);
    
    int opcao;
    
    do {
        mostraMenu();
        printf("\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        limpa_entrada();
        escolheOpcao(opcao);
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
            printf("Pré Cadastro do Paciente: \n");
            
            Paciente pacDados;
            printf("Nome do paciente: ");
            fgets(pacDados.nome, sizeof(pacDados.nome), stdin);
            pacDados.nome[strcspn(pacDados.nome, "\n")] = '\0';
            limpa_entrada();
            
            printf("CPF do paciente: ");
            fgets(pacDados.CPF, sizeof(pacDados.CPF), stdin);
            pacDados.CPF[strcspn(pacDados.CPF, "\n")] = '\0';
            limpa_entrada();
            
            printf("Endereço do paciente: ");
            fgets(pacDados.endereco, sizeof(pacDados.endereco), stdin);
            pacDados.endereco[strcspn(pacDados.endereco, "\n")] = '\0';
            limpa_entrada();
            
            cadastra_novo_paciente(&preCadastroPacientes, pacDados);
            printf("Paciente cadastrado com sucesso!\n");
            break;
        }
        case 2: {
            printf("Triagem do Paciente: \n");

            char cpfBusca[11];
            printf("Informe o CPF do paciente: ");
            fgets(cpfBusca, sizeof(cpfBusca), stdin);
            cpfBusca[strcspn(cpfBusca, "\n")] = '\0';
            limpa_entrada();

            Paciente* pacienteEncontrado = consulta_cpf(&preCadastroPacientes, cpfBusca);
            if (pacienteEncontrado != NULL) {
                printf("Paciente encontrado:\n");
                printf("Nome: %s\n", pacienteEncontrado->nome);
                printf("CPF: %s\n", pacienteEncontrado->CPF);
                printf("Endereço: %s\n", pacienteEncontrado->endereco);
            
                printf("Data de Nascimento do Paciente: ");
                char dataNasc[11];
                fgets(dataNasc, sizeof(dataNasc), stdin);
                dataNasc[strcspn(dataNasc, "\n")] = '\0';
                limpa_entrada();

                printf("Avaliação do Estado de Saúde: ");
                char estadoSaude[100];
                fgets(estadoSaude, sizeof(estadoSaude), stdin);
                estadoSaude[strcspn(estadoSaude, "\n")] = '\0';
                limpa_entrada();

                printf("Prioridade (3 = Vermelho, 2 = Amarelo, 1 = Verde): ");
                int prioridade;
                scanf("%d", &prioridade);
                limpa_entrada();

                printf("Sintomas: ");
                char sintomas[100];
                fgets(sintomas, sizeof(sintomas), stdin);
                sintomas[strcspn(sintomas, "\n")] = '\0';
                limpa_entrada();

                Triagem triagem;
                triagem.paciente = pacienteEncontrado;
                strcpy(triagem.dataNascPaciente, dataNasc);
                strcpy(triagem.avaEstadoSaude, estadoSaude);
                triagem.prioridade = prioridade;
                strcpy(triagem.sintomas, sintomas);

                printf("Triagem realizada com sucesso!\n");
            }
            break;
        }
        case 3: {
            printf("Opção 03");
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