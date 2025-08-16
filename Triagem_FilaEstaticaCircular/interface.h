#include "../interfaces/interfaces.h"

void inicializar_fila_triagem(FilaTriagem *fila);
int fila_vazia_triagem(FilaTriagem *fila);
int fila_cheia_triagem(FilaTriagem *fila);
int obter_tamanho_fila_triagem(FilaTriagem *fila);
void cadastrar_paciente_fila_triagem(FilaTriagem *fila, Triagem pacienteTriagem);
void remover_paciente_fila_triagem(FilaTriagem *fila);
Triagem* consultar_via_cpf_fila_triagem(FilaTriagem *fila, char cpf[]);
Triagem* consultar_via_nome_fila_triagem(FilaTriagem *fila, char nome[]);
void imprime_fila_triagem(FilaTriagem *fila);