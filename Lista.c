/**
 * @file Lista.c
 * @brief Implementação de uma lista duplamente encadeada circular com sentinela.
 * @author pagfr
 * @date 25/02/2025
 */

#include "Lista.h"

/**
 * @brief Inicializa a lista duplamente encadeada com sentinela.
 * @param p Ponteiro para a lista (inicialmente nulo).
 * @return LISTA* Ponteiro para a lista inicializada.
 */
LISTA *inicia_lista(LISTA *p) {
  p = (LISTA *)malloc(sizeof(LISTA));
  if (p == NULL) {
    printf("Erro ao alocar memória\n");
    return NULL;
  }
  p->sentinela = (PONTEIRO)malloc(sizeof(ITEM));
  if (p->sentinela == NULL) {
    printf("Erro ao alocar memória\n");
    free(p);
    return NULL;
  }
  p->sentinela->proximo = p->sentinela;
  p->sentinela->anterior = p->sentinela;
  p->tamanho = 0;
  return p;
}

/**
 * @brief Adiciona um novo ID na lista.
 * @param p Ponteiro para a lista.
 * @param f Estrutura do tipo FICHA contendo os dados.
 * @return int Retorna 1 se bem-sucedido, 0 em caso de erro.
 */
int adiciona_id(LISTA *p, FICHA f) {
  PONTEIRO novo = (PONTEIRO)malloc(sizeof(ITEM));
  if (novo == NULL) {
    printf("Erro ao alocar memória\n");
    return 0;
  }
  novo->proximo = p->sentinela->proximo;
  novo->anterior = p->sentinela;
  p->sentinela->proximo->anterior = novo;
  p->sentinela->proximo = novo;
  novo->dado = f;
  p->sentinela->anterior = novo;
  p->tamanho++;
  return 1;
}

/**
 * @brief Consulta e remove um elemento da lista pelo ID.
 * @param p Ponteiro para a lista.
 * @param f Estrutura FICHA com o ID a ser removido.
 * @return int Retorna 1 se encontrou e removeu, 0 caso contrário.
 */
int consulta(LISTA *p, FICHA f) {
  ITERADOR it = ini_iterador(p);
  for (; it.posicao != p->sentinela; it.posicao = it.posicao->proximo) {
    if (it.posicao->dado.id == f.id) {
      it.posicao->anterior->proximo = it.posicao->proximo;
      it.posicao->proximo->anterior = it.posicao->anterior;
      free(it.posicao);
      p->tamanho--;
      return 1;
    }
  }
  return 0;
}

/**
 * @brief Inicializa um iterador para a lista.
 * @param p Ponteiro para a lista.
 * @return ITERADOR Retorna um iterador inicializado.
 */
ITERADOR ini_iterador(LISTA *p) {
  ITERADOR it;
  it.estrutura = p;
  it.posicao = p->sentinela->proximo;
  return it;
}

/**
 * @brief Retorna o tamanho da lista.
 * @param p Ponteiro para a lista.
 * @return int O número de elementos na lista.
 */
int tamanho(LISTA *p) { return p->tamanho; }

/**
 * @brief Verifica se a lista está vazia.
 * @param p Ponteiro para a lista.
 * @return int Retorna 1 se estiver vazia, 0 caso contrário.
 */
int lista_vazia(LISTA *p) { return (p->tamanho == 0); }

/**
 * @brief Libera a memória ocupada pela lista.
 * @param p Ponteiro para a lista.
 */
void destruir_lista(LISTA *p) {
  while (p->sentinela->proximo != p->sentinela) {
    remove_ini_lista(p);
  }
  free(p->sentinela);
  free(p);
}

/**
 * @brief Remove o primeiro elemento da lista (usado apenas na destruição).
 * @param p Ponteiro para a lista.
 */
void remove_ini_lista(LISTA *p) {
  PONTEIRO apagar = p->sentinela->proximo;
  p->sentinela->proximo = apagar->proximo;
  apagar->proximo->anterior = p->sentinela;
  free(apagar);
  p->tamanho--;
}
