#include "../interfaces/interfaces.h"

void avaliacao_internacao(Triagem *triagemPaciente, PilhaPacientesInternados *pilhaPacientesInternados);

PilhaPacientesInternados* inicializar_pilha_pacientes_internados();
int pilha_vazia_pacientes_internados(PilhaPacientesInternados *p);
void adicionar_pacientes_internados(PilhaPacientesInternados *p, PacienteInternado dadosPacienteInternado);
void remover_pacientes_internados(PilhaPacientesInternados *p);
int obter_tamanho_pilha_pacientes_internados(PilhaPacientesInternados *p);
void imprimer_pilha_pacientes_internados(PilhaPacientesInternados *p);
PilhaPacientesInternados* liberar_pilha_pacientes_internados(PilhaPacientesInternados *p);