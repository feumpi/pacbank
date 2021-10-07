#ifndef BANCO_H
#define BANCO_H

#include <algorithm>
#include <iostream>
#include <vector>

#include "contabancaria.h"
#include "contacorrente.h"
#include "contapoupanca.h"
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
    // Recebe um ponteiro de conta e insere ele no vetor de contas
    void inserir(ContaBancaria* conta);

    // Recebe um ponteiro de conta e remove ele do vetor de contas, se
    // encontrado
    void remover(ContaBancaria* conta);

    // Recebe um número de conta e retorna o ponteiro da conta correspondente,
    // se existir, ou NULL do contrário
    ContaBancaria* procurarConta(int numero);

    // Chama a implementação de Imprimivel::mostrarDados() para todas as contas
    // do vetor
    void mostrarDados();

    // Remove todas as contas da heap e limpa o vetor de contas
    ~Banco();

   protected:
    std::vector<ContaBancaria*> contas;
};

#endif