//
// Created by pagfr on 26/02/2025.
//

#include "Ficha.h"
#include "Fila.h"
#include "Lista.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  ITERADOR iterador;
  LISTA *lista_cadastros = inicia_lista(lista_cadastros);
  FILA *fila_cadastro = inicia_fila(fila_cadastro),
       *fila_sem = inicia_fila(fila_sem);
  ;
  FICHA fichas;

  int op = 0, n = 0;
  while (1) {
    printf(
        " 1 - Colocar na fila\n 2 - Chamar Fila\n 3 - Cadastrar\n-1 - Sair\n");
    scanf(" %d", &op);
    if (op > 3 || op < -1 || op == 0) {
      printf("Opcao invalida\n");
      continue;
    }
    switch (op) {
      // Inserir id
    case 1:
      scanf("%s %d", fichas.nome, &fichas.id);
      if (consulta(lista_cadastros, fichas)) {
        if (fila_cheia(fila_cadastro)) {
          aumenta_fila(fila_cadastro);
        }
        insere_fila(fila_cadastro, fichas);
      } else {
        if (fila_cheia(fila_sem)) {
          aumenta_fila(fila_sem);
        }
        insere_fila(fila_sem, fichas);
      }
      break;
      // Libera pessoas da fila
    case 2:
      if (n % 3 == 2) {
        printf("%s\n", remover_ini(fila_sem).nome);
      } else {
        if (fila_vazia(fila_cadastro)) {
          printf("%s\n", remover_ini(fila_sem).nome);
        } else {
          printf("%s\n", remover_ini(fila_cadastro).nome);
        }
      }
      n++;
      break;
    case 3:
      printf("Digite o ID a ser cadastrado\n");
      scanf(" %d", &fichas.id);
      adiciona_id(lista_cadastros, fichas);
      break;
    case -1:
      return 0;
      break;
    }
  }
  return 0;
}