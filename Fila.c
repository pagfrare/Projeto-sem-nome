/**
 * @file Fila.c
 * @brief Implementação das operações para a fila de fichas.
 * @author pagfr
 * @date 25/02/2025
 */

#include "Fila.h"

/**
 * @brief Inicializa uma fila vazia.
 * @param p Ponteiro para a fila.
 * @return FILA* Ponteiro para a fila inicializada.
 */
FILA *inicia_fila(FILA *p) {
  p = (FILA *)malloc(sizeof(FILA));
  p->tamanho = 0;
  p->max = 4;
  p->fichas = (FICHA *)malloc(p->max * sizeof(FICHA));
  if (p->fichas == NULL) {
    printf("Erro ao alocar memoria\n");
  }
  p->primeiro = 0;
  p->ultimo = 0;
  return p;
}

/**
 * @brief Aumenta a capacidade da fila.
 * @param p Ponteiro para a fila.
 * @return int Retorna 1 se bem-sucedido, 0 em caso de erro.
 */
int aumenta_fila(FILA *p) {
  FICHA *novo = (FICHA *)malloc(2 * p->max * sizeof(FICHA));
  if (novo == NULL) {
    printf("Erro ao alocar memoria\n");
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

/**
 * @brief Remove e retorna o primeiro elemento da fila.
 * @param p Ponteiro para a fila.
 * @return FICHA A ficha removida.
 */
FICHA remover_ini(FILA *p) {
  FICHA temp = p->fichas[p->primeiro];
  p->primeiro++;
  return temp;
}

/**
 * @brief Libera a memória ocupada pela fila.
 * @param p Ponteiro para a fila.
 */
void destruir_fila(FILA *p) {
  free(p->fichas);
}

/**
 * @brief Insere uma ficha na fila.
 * @param p Ponteiro para a fila.
 * @param f Estrutura FICHA a ser inserida.
 */
void insere_fila(FILA *p, FICHA f) {
  p->fichas[p->ultimo] = f;
  p->ultimo++;
  p->tamanho++;
}

/**
 * @brief Verifica se a fila está vazia.
 * @param p Ponteiro para a fila.
 * @return int Retorna 1 se estiver vazia, 0 caso contrário.
 */
int fila_vazia(FILA *p) {
  return (p->tamanho == 0 || p->primeiro == p->ultimo);
}

/**
 * @brief Verifica se a fila está cheia.
 * @param p Ponteiro para a fila.
 * @return int Retorna 1 se estiver cheia, 0 caso contrário.
 */
int fila_cheia(FILA *p) {
  return (p->tamanho == p->max);
}
