/**
 * @file Ficha.h
 * @brief Definição da estrutura FICHA para armazenar nome e ID de uma pessoa.
 * 
 * Este arquivo contém a definição da estrutura FICHA, usada para armazenar informações sobre uma pessoa, incluindo o nome e o ID único.
 */

#ifndef FICHA_H
#define FICHA_H

/**
 * @struct FICHA
 * @brief Estrutura que representa uma ficha com nome e ID.
 * 
 * Esta estrutura armazena o nome e o identificador único de uma pessoa.
 */
typedef struct{
  /**
   * @var FICHA::nome
   * @brief Nome da pessoa.
   * 
   * Este campo armazena o nome da pessoa com um tamanho máximo de 15 caracteres, já que o último caractere é reservado para o terminador nulo.
   */
  char nome[16];
  
  /**
   * @var FICHA::id
   * @brief Identificador único da pessoa.
   * 
   * Este campo armazena o identificador único da pessoa, representado como um número inteiro não negativo.
   */
  unsigned id;
} FICHA;

#endif // FICHA_H
