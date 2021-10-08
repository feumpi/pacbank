#include "contapoupanca.h"

ContaPoupanca::ContaPoupanca(int numero, double saldo, double limite)
    : ContaBancaria(numero, saldo) {
    this->limite = limite;
}

void ContaPoupanca::sacar(double valor) {}

void ContaPoupanca::mostrarDados() {
    std::cout << "Número: " << this->numero << std::endl;
    std::cout << "Tipo: conta poupança" << std::endl;
    std::cout << "Saldo: R$ " << this->saldo << std::endl;
    std::cout << "Limite: R$ " << this->limite << std::endl;
}
