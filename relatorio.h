#ifndef RELATORIO_H
#define RELATORIO_H

#include "imprimivel.h"

/*
Crie uma classe Relatorio que possui um método gerarRelatorio, que receba um
objeto Imprimível e executa o método mostrarDados do objeto.
*/

class Relatorio {
 public:
  void gerarRelatorio(Imprimivel imprimivel);
};

#endif