//
// Created by pagfr on 25/02/2025.
//
#include "Fila.h"

int inicia_fila(FILA *p){
  p->tamanho =  4;
  p->fichas = (FICHA *)malloc(p->tamanho * sizeof(FICHA));
  if (p->fichas == NULL){
    printf("Erro ao alocar memoria");
    return 0; //caso de erro
  }
  int primeiro;
  int ultimo;
  return 1; //caso bem sucedido
}
int aumenta_fila(FILA *p, int n){
  p->tamanho = n;
  FICHA *novo = (FICHA *)malloc(p->tamanho * sizeof(FICHA));
  int i, j;
  for (i = 0, j = p->primeiro; i < p->ultimo; i++, j++){
    novo[i] = p->fichas[j];
  }
  p->primeiro = 0;
  free(p->fichas);
  p->fichas = novo;
  return 1;
}
