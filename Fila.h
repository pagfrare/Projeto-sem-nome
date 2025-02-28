//
// Created by pagfr on 25/02/2025.
//

#ifndef FILA_H
#define FILA_H

#include "Ficha.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  FICHA *fichas;
  int primeiro;
  int ultimo;
  int tamanho;
  int max;
} FILA;

FILA *inicia_fila(FILA *p);
int aumenta_fila(FILA *p);
FICHA remover_ini(FILA *p);
void destruir_fila(FILA *p);
void insere_fila(FILA *p, FICHA f);
int fila_vazia(FILA *p);
int fila_cheia(FILA *p);
#endif // FILA_h
