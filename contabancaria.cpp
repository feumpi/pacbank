#include "contapoupanca.h"

ContaBancaria::ContaBancaria(int numero, double saldo) {
    this->numero = numero;
    this->saldo = saldo;
}

int ContaBancaria::getNumero() { return this->numero; }

double ContaBancaria::getSaldo() { return this->saldo; }

bool ContaBancaria::sacar(double valor, bool silencioso) {
    this->saldo -= valor;

    if (!silencioso) {
        std::cout << "Saque no valor de R$ " << std::setprecision(2)
                  << std::fixed << valor << " efetuado com sucesso!\n";

        std::cout << "Novo saldo: R$ " << std::setprecision(2) << std::fixed
                  << this->saldo << "\n";
    }

    // Sucesso
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

    // Sucesso
    return true;
}

void ContaBancaria::transferir(double valor, ContaBancaria* contaDestino) {
    // Salva o saldo inicial
    double saldoInicial = this->saldo;

    // Se o saque do valor na própria conta falhar
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

    // Sucesso na transferência
    std::cout << "\nTransferência de R$ " << std::setprecision(2) << std::fixed
              << valor << " para a conta " << contaDestino->getNumero()
              << " bem-sucedida!\n\n";

    std::cout << "Novo saldo na conta de origem: R$ " << std::setprecision(2)
              << std::fixed << this->saldo << "\n";

    std::cout << "Novo saldo na conta de destino: R$ " << std::setprecision(2)
              << std::fixed << contaDestino->getSaldo() << "\n\n";
}

void ContaBancaria::mostrarDados() {
    std::cout << "ContaBancaria::mostrarDados()\n";
}