/**
 * @file main.c
 * @brief Programa principal para gerenciamento de filas e listas de cadastro.
 * @author pagfr
 * @date 26/02/2025
 */

#include "Ficha.h"
#include "Fila.h"
#include "Lista.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função principal do programa.
 * 
 * Gerencia filas e listas de cadastro, permitindo adicionar IDs à fila,
 * chamar pessoas da fila e cadastrar novos IDs na lista.
 * 
 * @return int Retorna 0 ao finalizar a execução.
 */
int main() {
  ITERADOR iterador;
  LISTA *lista_cadastros = inicia_lista(lista_cadastros);
  FILA *fila_cadastro = inicia_fila(fila_cadastro),
       *fila_sem = inicia_fila(fila_sem);
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
      /**
       * @brief Caso 1 - Adiciona uma pessoa à fila.
       */
    case 1:
      printf("Insira o nome e o ID: \n");
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
      /**
       * @brief Caso 2 - Remove uma pessoa da fila e a exibe.
       */
    case 2:
      if (n % 3 == 2) {
        if (fila_vazia(fila_sem)) {
          if (fila_vazia(fila_cadastro)) {
            printf("Fila vazia\n");
          } else {
            printf("%s\n", remover_ini(fila_cadastro).nome);
          }
        }
        printf("%s\n", remover_ini(fila_sem).nome);
      } else {
        if (fila_vazia(fila_cadastro)) {
          if (fila_vazia(fila_sem)) {
            printf("Fila vazia\n");
          } else {
            printf("%s\n", remover_ini(fila_sem).nome);
          }
        } else {
          printf("%s\n", remover_ini(fila_cadastro).nome);
        }
      }
      n++;
      break;
      /**
       * @brief Caso 3 - Cadastra um novo ID na lista.
       */
    case 3:
      printf("Digite o ID a ser cadastrado\n");
      scanf(" %d", &fichas.id);
      adiciona_id(lista_cadastros, fichas);
      break;
      /**
       * @brief Caso -1 - Finaliza o programa e libera memória.
       */
    case -1:
      destruir_fila(fila_sem);
      destruir_fila(fila_cadastro);
      destruir_lista(lista_cadastros);
      return 0;
      break;
    }
  }
  return 0;
}
