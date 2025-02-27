//
// Created by pagfr on 25/02/2025.
//
#include "Lista.h"
#include "Carta.h"

int inicia_lista(LISTA *p){
  p = (LISTA *)malloc(sizeof(LISTA));// Verifica se o ponteiro p não é nulo
  if (p == NULL) {
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
  return 1; //Retorna 1 caso tudo tenha dado certo
}
int remove_convidado(LISTA *p, CARTA c){ //A carta é sempre inserida no final da mao (lista)
  PONTEIRO novo = (PONTEIRO)malloc(sizeof(ITEM));
  if (novo == NULL) {
    printf("Erro\n");
    return 0; // caso de erro
  }
  novo->proximo = p->sentinela;
  novo->anterior = p->sentinela->anterior;
  p->sentinela->anterior = novo;
 return 1; //caso de sucesso
}
int remove_convidado(LISTA *p, CARTA c){



  return 1;
}
