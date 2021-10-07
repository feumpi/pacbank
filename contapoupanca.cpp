#include "contapoupanca.h"

ContaPoupanca::ContaPoupanca(int numero, double saldo, double taxaDeOperacao)
    : ContaBancaria(numero, saldo) {
    this->taxaDeOperacao = taxaDeOperacao;
}

void ContaPoupanca::mostrarDados() {
    std::cout << "Número: " << this->numero << std::endl;
    std::cout << "Tipo: conta poupança" << std::endl;
    std::cout << "Saldo: R$ " << this->saldo << std::endl;
    std::cout << "Taxa de operação: R$ " << this->taxaDeOperacao << std::endl;
}
