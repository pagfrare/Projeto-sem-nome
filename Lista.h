//
// Created by pagfr on 25/02/2025.
//

#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct node {
  	char nome [15];
    int cpf;
    struct node *proximo, *anterior;
} ITEM;
typedef ITEM *PONTEIRO;
typedef struct {
    PONTEIRO sentinela;
    int tamanho;
} LISTA;

#endif //LISTA_H
