#include "contapoupanca.h"

ContaBancaria::ContaBancaria(int numero, double saldo) {
    this->numero = numero;
    this->saldo = saldo;
}

int ContaBancaria::getNumero() { return this->numero; }

double ContaBancaria::getSaldo() { return this->saldo; }

void ContaBancaria::sacar(double valor, bool silencioso) {
    this->saldo -= std::abs(valor);
    if (!silencioso) {
        std::cout << "Saque no valor de R$ " << valor
                  << " efetuado com sucesso!\n";
        std::cout << "Novo saldo: R$ " << this->saldo << "\n";
    }
}

void ContaBancaria::depositar(double valor, bool silencioso) {
    this->saldo += valor;

    if (!silencioso) {
        std::cout << "Depósito no valor de R$ " << valor
                  << " efetuado com sucesso!\n";
        std::cout << "Novo saldo: R$ " << this->saldo << "\n";
    }
}

void ContaBancaria::mostrarDados() {
    std::cout << "ContaBancaria::mostrarDados()\n";
}