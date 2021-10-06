#include "contacorrente.h"

ContaCorrente::ContaCorrente(int numero, double saldo, double limite)
    : ContaBancaria(numero, saldo) {
    this->limite = limite;
}

void ContaCorrente::mostrarDados() {}