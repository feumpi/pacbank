#include "contacorrente.h"

ContaCorrente::ContaCorrente(int numero, double saldo, double taxaDeOperacao)
    : ContaBancaria(numero, saldo) {
    this->taxaDeOperacao = taxaDeOperacao;
}

void ContaCorrente::sacar(double valor) {}

void ContaCorrente::mostrarDados() {
    std::cout << "Número: " << this->numero << std::endl;
    std::cout << "Tipo: conta corrente" << std::endl;
    std::cout << "Saldo: R$ " << this->saldo << std::endl;
    std::cout << "Taxa de operação: R$ " << this->taxaDeOperacao << std::endl;
}
