#include "contacorrente.h"

ContaCorrente::ContaCorrente(int numero, double saldo, double limite)
    : ContaBancaria(numero, saldo) {
    this->limite = limite;
}

void ContaCorrente::sacar(double valor) {}

void ContaCorrente::mostrarDados() {
    std::cout << "Número: " << this->numero << std::endl;
    std::cout << "Tipo: conta corrente" << std::endl;
    std::cout << "Saldo: R$ " << this->saldo << std::endl;
    std::cout << "Limite: R$ " << this->limite << std::endl;
}
