//
// Created by pagfr on 25/02/2025.
//
#include "Lista.h"

LISTA *inicia_lista(LISTA *p) {
  p = (LISTA *)malloc(sizeof(LISTA));
  if (p == NULL) { // Verifica se o ponteiro p não é nulo
    printf("Erro\n");
  }
  p->sentinela = (PONTEIRO)malloc(sizeof(ITEM));
  if (p->sentinela == NULL) {
    printf("Erro\n");
  }
  p->sentinela->proximo = p->sentinela;
  p->sentinela->anterior = p->sentinela;
  p->tamanho = 0;
  return p; // sucesso
}
int adiciona_id(LISTA *p,
                FICHA f) { // A carta é sempre inserida no final da mao (lista)
  PONTEIRO novo = (PONTEIRO)malloc(sizeof(ITEM));
  if (novo == NULL) {
    printf("Erro\n");
    return 0; // caso de erro
  }
  novo->proximo = p->sentinela->proximo;
  novo->anterior = p->sentinela;
  p->sentinela->proximo->anterior = novo;
  p->sentinela->proximo = novo;
  novo->dado = f;
  p->sentinela->anterior = novo;
  p->tamanho++;
  return 1; // caso de sucesso
}
int consulta(LISTA *p, FICHA f) {
  ITERADOR it = ini_iterador(p);
  for (; it.posicao != p->sentinela; it.posicao = it.posicao->proximo) {
    if (it.posicao->dado.id == f.id) {
      it.posicao->anterior->proximo = it.posicao->proximo;
      it.posicao->proximo = it.posicao->anterior;
      free(it.posicao);
      return 1; // Caso o id seja achado, remove e retorna 1
    }
  }
  return 0; // caso não exista
}
ITERADOR ini_iterador(LISTA *p) {
  ITERADOR it;
  it.estrutura = p;
  it.posicao = p->sentinela->proximo;
  return it;
} // sempre inicia o iterador apontando pro primeiro elemebnto da lista
int tamanho(LISTA *p) { return p->tamanho; }
int lista_vazia(LISTA *p) {
  if (p->tamanho == 0) {
    return 1;
  }
  return 0;
}