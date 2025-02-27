//
// Created by pagfr on 26/02/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Lista.h"
#include "Fila.h"
#define MAX_CPF 11

int CalcDigVerificador(char cpf[], int pos){
  int soma = 0;
  int peso = pos + 1;
  for (int i = 0; i < pos; i++) {
    soma += (cpf[i] - '0') * peso--;
  }
  int digito = (soma * 10) % 11;
  return (digito == 10 || digito == 11) ? 0 : digito;
}

int validarCPF(char cpf[]){
  //Verificar se o CPF tem 11 caracteres
  if (strlen(cpf) != 11) {
    return 0;
  }

  //Verificar se todos os caracteres são dígitos
  for (int i = 0; i < 11; i++){
    if (!isdigit(cpf[i])){
      return 0;
    }
  }

  int digito1 = CalcDigVerificador(cpf, 9);
  int digito2 = CalcDigVerificador(cpf, 10);

  return(cpf[9] - '0' == digito1 && cpf[10] - '0' == digito2);
}

int main(){
  LISTA *lista_cadastros;
  FILA  *fila_cadastro,*fila_sem;

  char cpf[11];
  scanf("%s",cpf);






  return 0;
}
