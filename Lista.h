/**
 * @file Lista.h
 * @brief Definição da estrutura de uma lista duplamente encadeada circular com sentinela.
 * @author pagfr
 * @date 25/02/2025
 */

#ifndef LISTA_H
#define LISTA_H

#include "Ficha.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura que representa um nó da lista.
 */
typedef struct node {
  FICHA dado; /**< Dado armazenado no nó. */
  struct node *proximo, *anterior; /**< Ponteiros para o próximo e anterior nós. */
} ITEM;

typedef ITEM *PONTEIRO;

/**
 * @brief Estrutura que representa a lista duplamente encadeada.
 */
typedef struct {
  PONTEIRO sentinela; /**< Ponteiro para o nó sentinela. */
  int tamanho; /**< Número de elementos na lista. */
} LISTA;

/**
 * @brief Estrutura do iterador para percorrer a lista.
 */
typedef struct {
  PONTEIRO posicao; /**< Posição atual do iterador. */
  LISTA *estrutura; /**< Ponteiro para a lista associada. */
} ITERADOR;

/**
 * @brief Inicializa uma nova lista.
 * @param p Ponteiro para a lista.
 * @return LISTA* Ponteiro para a lista inicializada.
 */
LISTA *inicia_lista(LISTA *p);

/**
 * @brief Adiciona um ID à lista.
 * @param p Ponteiro para a lista.
 * @param c Estrutura do tipo FICHA contendo os dados.
 * @return int Retorna 1 se bem-sucedido, 0 em caso de erro.
 */
int adiciona_id(LISTA *p, FICHA c);

/**
 * @brief Consulta um ID na lista e remove se encontrado.
 * @param p Ponteiro para a lista.
 * @param f Estrutura FICHA com o ID a ser removido.
 * @return int Retorna 1 se encontrou e removeu, 0 caso contrário.
 */
int consulta(LISTA *p, FICHA f);

/**
 * @brief Inicializa um iterador para percorrer a lista.
 * @param p Ponteiro para a lista.
 * @return ITERADOR Iterador inicializado.
 */
ITERADOR ini_iterador(LISTA *p);

/**
 * @brief Retorna o tamanho da lista.
 * @param p Ponteiro para a lista.
 * @return int O número de elementos na lista.
 */
int tamanho(LISTA *p);

/**
 * @brief Verifica se a lista está vazia.
 * @param p Ponteiro para a lista.
 * @return int Retorna 1 se estiver vazia, 0 caso contrário.
 */
int lista_vazia(LISTA *p);

/**
 * @brief Libera toda a memória ocupada pela lista.
 * @param p Ponteiro para a lista.
 */
void destruir_lista(LISTA *p);

/**
 * @brief Remove o primeiro elemento da lista (usado na destruição).
 * @param p Ponteiro para a lista.
 */
void remove_ini_lista(LISTA *p);

#endif // LISTA_H
