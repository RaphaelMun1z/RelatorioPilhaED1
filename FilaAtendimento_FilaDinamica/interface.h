#include "../interfaces/interfaces.h"

FilaAtendimento* inicializar_fila_atendimento_medico();
int fila_existe_atendimento_medico(FilaAtendimento *fila);
int fila_vazia_atendimento_medico(FilaAtendimento *fila);
void adicionar_fila_atendimento_medico(FilaAtendimento *fila, PacienteCadastro *pacienteCadastrado, int tipoAtendimento);
void remover_paciente_fila_atendimento_medico(FilaAtendimento *fila);
int obter_tamanho_fila_atendimento_medico(FilaAtendimento *fila);
void imprimir_fila_atendimento_medico(FilaAtendimento *fila);