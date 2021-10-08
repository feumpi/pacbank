#include "contacorrente.h"

ContaCorrente::ContaCorrente(int numero, double saldo, double taxaDeOperacao)
    : ContaBancaria(numero, saldo) {
    this->taxaDeOperacao = taxaDeOperacao;
}

void ContaCorrente::sacar(double valor) {
    double valorTotal = valor + this->taxaDeOperacao;

    // Se o saldo for >= valor + taxa de operação, desconta a taxa e faz o saque
    if (this->saldo >= valorTotal) {
        this->saldo -= taxaDeOperacao;
        std::cout << "Taxa de operação aplicada: R$ " << this->taxaDeOperacao
                  << "\n";

        ContaBancaria::sacar(valor);
    }

    // Do contrário, não é possível sacar
    else {
        std::cout << "Saldo insuficiente. Considere a taxa de operação no "
                     "valor de R$ "
                  << this->taxaDeOperacao << "\n";
    }
}

void ContaCorrente::mostrarDados() {
    std::cout << "Número: " << this->numero << std::endl;
    std::cout << "Tipo: conta corrente" << std::endl;
    std::cout << "Saldo: R$ " << this->saldo << std::endl;
    std::cout << "Taxa de operação: R$ " << this->taxaDeOperacao << std::endl;
}
