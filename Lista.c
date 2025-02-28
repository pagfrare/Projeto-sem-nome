//
// Created by pagfr on 25/02/2025.
//
#include "Lista.h"
#include "Carta.h"

int inicia_lista(LISTA *p){
  p = (LISTA *)malloc(sizeof(LISTA));
  if (p == NULL) { // Verifica se o ponteiro p não é nulo
    printf("Erro\n");
    return 0;
  }
  p->sentinela = (PONTEIRO)malloc(sizeof(ITEM));
  if (p->sentinela == NULL) {
    printf("Erro\n");
    return 0;
  }
  p->sentinela->proximo = p->sentinela;
  p->sentinela->anterior = p->sentinela;
  p->tamanho = 0;
  return 1; //sucesso
}
int adiciona_cpf(LISTA *p, CARTA c){ //A carta é sempre inserida no final da mao (lista)
  PONTEIRO novo = (PONTEIRO)malloc(sizeof(ITEM));
  if (novo == NULL) {
    printf("Erro\n");
    return 0; // caso de erro
  }
  novo->proximo = p->sentinela;
  novo->anterior = p->sentinela->anterior;
  p->sentinela->anterior = novo;
  p->tamanho++;
 return 1; //caso de sucesso
}
int consulta(LISTA *p, ITERADOR it, FICHAS f){
  for (; it != p->sentinela; it->posicao = it->posicao->proximo){
    if (it->posicao->dado->cpf == f->cpf){
      it->posicao->anterior->proximo = it->posicao->proximo;
      it->posicao->proximo = it->posicao->anterior;
      free(it->posicao);
      return 1; // Caso o cpf seja achado, remove e retorna 1
    }
  }
  return 0; // caso não exista
}
void ini_iterador(LISTA *p, ITERADOR i){
  i->estrutura = p;
  i->posicao = p->sentinela->proximo
} // sempre inicia o iterador apontando pro primeiro elemebnto da lista
int tamanho (LISTA *p){
  return p->tamanho;
}