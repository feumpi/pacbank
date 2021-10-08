#include "contapoupanca.h"

ContaBancaria::ContaBancaria(int numero, double saldo) {
    this->numero = numero;
    this->saldo = saldo;
}

int ContaBancaria::getNumero() { return this->numero; }

double ContaBancaria::getSaldo() { return this->saldo; }

bool ContaBancaria::sacar(double valor, bool silencioso) {
    this->saldo -= std::abs(valor);
    if (!silencioso) {
        std::cout << "Saque no valor de R$ " << std::setprecision(2)
                  << std::fixed << valor << " efetuado com sucesso!\n";
        std::cout << "Novo saldo: R$ " << std::setprecision(2) << std::fixed
                  << this->saldo << "\n";
    }

    return true;
}

bool ContaBancaria::depositar(double valor, bool silencioso) {
    this->saldo += valor;

    if (!silencioso) {
        std::cout << "Depósito no valor de R$ " << std::setprecision(2)
                  << std::fixed << valor << " efetuado com sucesso!\n";
        std::cout << "Novo saldo: R$ " << std::setprecision(2) << std::fixed
                  << this->saldo << "\n";
    }

    return true;
}

void ContaBancaria::transferir(double valor, ContaBancaria* contaDestino) {
    double saldoInicial = this->saldo;

    // Se o saque do valor na própria falhar
    if (!this->sacar(valor, true)) {
        std::cout << "Transferência falhou: saldo insuficiente na conta de "
                     "origem.\n\n";
        return;
    }

    // Se o depósito na conta de destino falhar
    if (!contaDestino->depositar(valor, true)) {
        std::cout << "Transferência falhou: saldo insuficiente na conta de "
                     "destino.\n\n";

        // Restaura o saldo inicial (antes do saque)
        this->saldo = saldoInicial;

        return;
    }

    std::cout << "\nTransferência de R$ " << std::setprecision(2) << std::fixed
              << valor << " para a conta " << contaDestino->getNumero()
              << " bem-sucedida!\n\n";

    std::cout << "Novo saldo origem: " << std::setprecision(2) << std::fixed
              << this->saldo << "\n";

    std::cout << "Novo saldo destino: " << std::setprecision(2) << std::fixed
              << contaDestino->getSaldo() << "\n\n";
}

void ContaBancaria::mostrarDados() {
    std::cout << "ContaBancaria::mostrarDados()\n";
}