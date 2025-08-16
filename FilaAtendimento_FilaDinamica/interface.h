#include "../interfaces/interfaces.h"

NoLog prepara_novo_log();

FilaAtendimento* inicializar_fila_atendimento_medico();
int fila_existe_atendimento_medico(FilaAtendimento *fila);
int fila_vazia_atendimento_medico(FilaAtendimento *fila);
void adicionar_fila_atendimento_medico(FilaAtendimento *fila, Triagem *pacienteTriagem, int tipoAtendimento, PilhaLog *pilhaLogs);
void remover_paciente_fila_atendimento_medico(FilaAtendimento *fila);
int obter_tamanho_fila_atendimento_medico(FilaAtendimento *fila);
void imprimir_fila_atendimento_medico(FilaAtendimento *fila);
PacienteFilaAtendimento* obter_paciente_via_nome_atendimento_medico(FilaAtendimento *fila, char nome[]);
PacienteFilaAtendimento* obter_paciente_via_cpf_atendimento_medico(FilaAtendimento *fila, char cpf[]);