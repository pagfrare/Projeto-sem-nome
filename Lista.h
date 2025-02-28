//
// Created by pagfr on 25/02/2025.
//

#ifndef LISTA_H
#define LISTA_H

#include "Ficha.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  FICHA dado;
  struct node *proximo, *anterior;
} ITEM;
typedef ITEM *PONTEIRO;
typedef struct {
  PONTEIRO sentinela;
  int tamanho;
} LISTA;

typedef struct {
  PONTEIRO posicao;
  LISTA *estrutura;
} ITERADOR;
LISTA *inicia_lista(LISTA *p);
int adiciona_id(LISTA *p, FICHA c);
int consulta(LISTA *p, FICHA f);
ITERADOR ini_iterador(LISTA *p);
int tamanho(LISTA *p);
int vazia(LISTA *p);
#endif // LISTA_H
