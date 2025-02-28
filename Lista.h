//
// Created by pagfr on 25/02/2025.
//

#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Ficha.h"

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
  LISTA estrutura;
}ITERADOR;
int inicia_lista(LISTA *p);
int adiciona_cpf(LISTA *p, CARTA c);
int consulta(LISTA *p, ITERADOR it, FICHAS f);
void ini_iterador(LISTA *p, ITERADOR i);
int tamanho (LISTA *p);
#endif //LISTA_H
