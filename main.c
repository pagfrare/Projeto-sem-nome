//
// Created by pagfr on 26/02/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Lista.h"
#include "Fila.h"

int main(){
  ITERADOR *iterador;
  LISTA *lista_cadastros;
  FILA  *fila_cadastro,*fila_sem;

  inicia_fila(fila_cadastro);
  inicia_fila(fila_sem);
  inicia_lista(lista_cadastros);

  int op = 0, id;
  ini_iterador(lista_cadastros, iterador);
  while(1){
    int n = 0;
    switch (op){
    //Inserir id
    case 1: scanf("%s",id);
      if(consulta(lista_cadastros, iterador, id)) {
          insere_fila(fila_cadastro,id);
        }
      else
      {
        insere_fila(fila_sem,id);
      }

    //Libera pessoas da fila
    case 2:
      if (n  % 3 == 0) {
        remover_ini(fila_cadastro);
      }
      if (n % 3 == 1) {
        remover_ini(fila_cadastro);
      }
      if (n % 3 == 2) {
        remover_ini(fila_sem);
      }
      n++;
    }

  }







  return 0;
}
