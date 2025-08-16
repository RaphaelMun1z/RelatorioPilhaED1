#include "../interfaces/interfaces.h"

void inicializar_fila_pre_cadastro(FilaCadastro *fila);
int fila_vazia_pre_cadastro(FilaCadastro *fila);
int fila_cheia_pre_cadastro(FilaCadastro *fila);
int obter_tamanho_fila_pre_cadastro(FilaCadastro *fila);
void cadastrar_paciente_fila_pre_cadastro(FilaCadastro *fila, PacienteCadastro pacienteDados);
void remover_paciente_fila_pre_cadastro(FilaCadastro *fila);
PacienteCadastro* consultar_via_cpf_fila_pre_cadastro(FilaCadastro *fila, char cpf[11]);
void imprime_fila_pre_cadastro(FilaCadastro *fila);