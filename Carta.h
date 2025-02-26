//
// Created by pagfr on 25/02/2025.
//

#ifndef CARTA_H
#define CARTA_H
typedef struct CARTA{
  int idcor, numero, idefeito; //define ids para cor, efeito e guarda o numero da carta
  // cores: 1 - vermelho, 2 - verde, 3 - amarelo, 4 - azul, 5 - preto
  // efeitos: 1 - bloqueia, 2- +2, 3 - inverte ordem, 4 - +4, 5 - troca a cor
  //Ex: carta troca de cor: numero = -1 (nao tem), idcor = 5, idefeito = 5;
}CARTA;
#endif //CARTA_H
