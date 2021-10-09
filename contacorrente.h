#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H

#include <iomanip>
#include <iostream>

#include "contabancaria.h"
#include "imprimivel.h"

/*
Crie as classes ContaCorrente e ContaPoupanca que herdam da ContaBancaria. A
primeira possui um atributo taxaDeOperacao que é descontado sempre que um saque
e um depósito são feitos. A segunda possui um atributo limite que dá crédito a
mais para o correntista caso ele precise sacar mais que o saldo. Neste caso, o
saldo pode ficar negativo desde que não ultrapasse o limite. Contudo isso não
pode acontecer na classe ContaCorrente.
*/

class ContaCorrente : public ContaBancaria, public Imprimivel {
   public:
    ContaCorrente(int numero, double saldo, double taxaDeOperacao);

    // Verifica se o valor está disponível, considerando a taxa de operação, e
    // chama ContaBancaria::sacar
    bool sacar(double valor, bool silencioso = false);

    // Verifica se o depósito é possível, considerando a taxa de operação, e
    // chama ontaBancaria::depositar
    bool depositar(double valor, bool silencioso = false);

    void mostrarDados();

   protected:
    double taxaDeOperacao;
};

#endif