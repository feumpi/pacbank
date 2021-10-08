#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H

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

class ContaPoupanca : public ContaBancaria, public Imprimivel {
   public:
    ContaPoupanca(int numero, double saldo, double limite);

    // Verifica se o valor está disponível, considerando o limite, e chama
    // ContaBancaria::sacar
    void sacar(double valor, bool silencioso = false);

    void mostrarDados();

   protected:
    double limite;
};

#endif