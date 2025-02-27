//
// Created by pagfr on 25/02/2025.
//
#include "Fila.h"

int inicia_fila(FILA *p){
  p = (FILA *)malloc(sizeof(FILA));
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
  if (novo == NULL) {
    printf("Erro ao alocar memoria");
    return 0;
  }
  int i, j;
  for (i = 0, j = p->primeiro; i < p->ultimo; i++, j++){
    novo[i] = p->fichas[j];
  }
  p->primeiro = 0;
  free(p->fichas);
  p->fichas = novo;
  return 1;
}
int remover_ini (FILA *p){
  int n = p->fichas[p->primeiro].cpf;
  p->primeiro++;
  return n;
}
void destruir_fila (FILA *p){
  free(p->fichas);
}
void insere_fila(FILA *p, int n){
  p->fichas[p->ultimo].cpf = n;
  p->ultimo++;
}
