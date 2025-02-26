//
// Created by pagfr on 25/02/2025.
//

#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Ficha.h"
typedef struct {
  FICHA *fichas;
  int primeiro;
  int ultimo;
  int tamanho;
}FILA;

#endif //FILA_h
