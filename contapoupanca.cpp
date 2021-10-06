#include "contapoupanca.h"

ContaPoupanca::ContaPoupanca(int numero, double saldo, double taxaDeOperacao)
    : ContaBancaria(numero, saldo) {
    this->taxaDeOperacao = taxaDeOperacao;
}

void ContaPoupanca::mostrarDados() {}