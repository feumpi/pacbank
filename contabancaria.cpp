#include "contapoupanca.h"

ContaBancaria::ContaBancaria(int numero, double saldo) {
    this->numero = numero;
    this->saldo = saldo;
}

int ContaBancaria::getNumero() { return this->numero; }

double ContaBancaria::getSaldo() { return this->saldo; }

void ContaBancaria::sacar(double valor) {
    std::cout << "ContaBancaria::sacar\n";
}

void ContaBancaria::mostrarDados() {
    std::cout << "ContaBancaria::mostrarDados()\n";
}