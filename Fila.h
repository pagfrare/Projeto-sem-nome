/**
 * @file Fila.h
 * @brief Definição da estrutura e operações para a fila de fichas.
 * @author pagfr
 * @date 25/02/2025
 */

#ifndef FILA_H
#define FILA_H

#include "Ficha.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura que representa uma fila de fichas.
 */
typedef struct {
  FICHA *fichas; /**< Vetor dinâmico para armazenar as fichas. */
  int primeiro; /**< Índice do primeiro elemento da fila. */
  int ultimo; /**< Índice do último elemento da fila. */
  int tamanho; /**< Quantidade atual de elementos na fila. */
  int max; /**< Capacidade máxima da fila. */
} FILA;

/**
 * @brief Inicializa uma nova fila.
 * @param p Ponteiro para a fila.
 * @return FILA* Ponteiro para a fila inicializada.
 */
FILA *inicia_fila(FILA *p);

/**
 * @brief Aumenta a capacidade da fila.
 * @param p Ponteiro para a fila.
 * @return int Retorna 1 se bem-sucedido, 0 em caso de erro.
 */
int aumenta_fila(FILA *p);

/**
 * @brief Remove e retorna o primeiro elemento da fila.
 * @param p Ponteiro para a fila.
 * @return FICHA A ficha removida.
 */
FICHA remover_ini(FILA *p);

/**
 * @brief Libera a memória ocupada pela fila.
 * @param p Ponteiro para a fila.
 */
void destruir_fila(FILA *p);

/**
 * @brief Insere uma ficha na fila.
 * @param p Ponteiro para a fila.
 * @param f Estrutura FICHA a ser inserida.
 */
void insere_fila(FILA *p, FICHA f);

/**
 * @brief Verifica se a fila está vazia.
 * @param p Ponteiro para a fila.
 * @return int Retorna 1 se estiver vazia, 0 caso contrário.
 */
int fila_vazia(FILA *p);

/**
 * @brief Verifica se a fila está cheia.
 * @param p Ponteiro para a fila.
 * @return int Retorna 1 se estiver cheia, 0 caso contrário.
 */
int fila_cheia(FILA *p);

#endif // FILA_H