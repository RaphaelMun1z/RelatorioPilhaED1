#include "../interfaces/interfaces.h"

void inicializar_pilha_logs(PilhaLog *p);
int pilha_cheia_logs(PilhaLog *p);
int pilha_vazia_logs(PilhaLog *p);
void adicionar_log(PilhaLog *p, NoLog novoLog);
void remover_log(PilhaLog *p);
void imprimer_pilha_logs(PilhaLog *p);