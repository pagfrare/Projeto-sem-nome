//
// Created by pagfr on 25/02/2025.
//
#include "Fila.h"

FILA *inicia_fila(FILA *p) {
  p = (FILA *)malloc(sizeof(FILA));
  p->tamanho = 0;
  p->max = 4;
  p->fichas = (FICHA *)malloc(p->max * sizeof(FICHA));
  if (p->fichas == NULL) {
    printf("Erro ao alocar memoria");
  }
  int primeiro = 0;
  int ultimo = 0;
  return p; // caso bem sucedido
}
int aumenta_fila(FILA *p) {
  FICHA *novo = (FICHA *)malloc(2 * p->max * sizeof(FICHA));
  if (novo == NULL) {
    printf("Erro ao alocar memoria");
    return 0;
  }
  int i, j;
  for (i = 0, j = p->primeiro; i < p->ultimo; i++, j++) {
    novo[i] = p->fichas[j];
  }
  p->primeiro = 0;
  free(p->fichas);
  p->fichas = novo;
  p->max *= 2;
  return 1;
}
FICHA remover_ini(FILA *p) {
  FICHA temp = p->fichas[p->primeiro];
  p->primeiro++;
  return temp;
}
void destruir_fila(FILA *p) { free(p->fichas); }
void insere_fila(FILA *p, FICHA f) {
  p->fichas[p->ultimo] = f;
  p->ultimo++;
  p->tamanho++;
}
int fila_vazia(FILA *p) {
  if (p->tamanho == 0 || p->primeiro == p->ultimo) {
    return 1;
  }
  return 0;
}
int fila_cheia(FILA *p) {
  if (p->tamanho == p->max) {
    return 1;
  } else {
    return 0;
  }
}
