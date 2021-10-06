#ifndef BANCO_H
#define BANCO_H

#include <vector>

#include "contabancaria.h"
#include "imprimivel.h"

/*
Crie uma classe Banco que possui um std::vector de contas bancárias e implemente
os métodos inserir, remover e procurarConta. O primeiro e o segundo recebem um
objeto ContaBancaria(que pode ser corrente ou poupança) e o insere e remove no
vetor, respectivamente. O terceiro recebe um inteiro como parâmetro
representando o número da conta e retorna um objeto conta bancária, caso essa
conta exista no vetor, ou null, caso contrário.

Faça a classe Banco herdar da classe Imprimível, onde a implementação de
método consiste em executar método mostrar dados de cada conta.
*/

class Banco : public Imprimivel {
 public:
  void inserir(ContaBancaria conta);
  void remover(ContaBancaria conta);
  ContaBancaria* procurarConta(int numero);

  void mostrarDados();

 protected:
  std::vector<ContaBancaria> contas;
};

#endif