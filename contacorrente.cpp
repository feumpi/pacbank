#include "contacorrente.h"

ContaCorrente::ContaCorrente(int numero, double saldo, double taxaDeOperacao)
    : ContaBancaria(numero, saldo) {
    this->taxaDeOperacao = taxaDeOperacao;

    std::cout << "Conta corrente (" << this->numero
              << ") criada com saldo inicial de R$ " << std::setprecision(2)
              << std::fixed << this->saldo
              << " e taxa de operação no valor de R$ " << std::fixed
              << this->taxaDeOperacao << "\n";
}

bool ContaCorrente::sacar(double valor, bool silencioso) {
    double valorTotal = valor + this->taxaDeOperacao;

    // Se o saldo for >= valor + taxa de operação, desconta a taxa e faz o saque
    if (this->saldo >= valorTotal) {
        // Aviso de taxa de operação
        if (!silencioso)
            std::cout << "Taxa de operação aplicada: R$ "
                      << std::setprecision(2) << std::fixed
                      << this->taxaDeOperacao << "\n";

        // Saca a taxa de operação (em modo silencioso)
        ContaBancaria::sacar(taxaDeOperacao, true);

        // Saca o valor solicitado (informa o novo saldo pós saque e taxa)
        ContaBancaria::sacar(valor, silencioso);

        return true;
    }

    // Do contrário, não é possível sacar
    if (!silencioso) {
        std::cout << "Saldo insuficiente. Considere a taxa de operação no "
                     "valor de R$ "
                  << std::setprecision(2) << std::fixed << this->taxaDeOperacao
                  << "\n";
    }

    return false;
}

bool ContaCorrente::depositar(double valor, bool silencioso) {
    // Valor após descontar a taxa de operação (pode ser negativo)
    double valorFinal = valor - this->taxaDeOperacao;

    // Se o saldo da conta após depósito e desconto da taxa não ficar negativo
    if ((this->saldo + valorFinal) >= 0) {
        // Aviso de taxa de operação
        if (!silencioso)
            std::cout << "Taxa de operação aplicada: R$ "
                      << std::setprecision(2) << std::fixed
                      << this->taxaDeOperacao << "\n";

        // Saca a taxa de operação (em modo silencioso)
        ContaBancaria::sacar(taxaDeOperacao, true);

        // Deposita o valor solicitado (informa o novo saldo após taxa e
        // depósito)
        ContaBancaria::depositar(valor, silencioso);

        return true;
    }

    // Do contrário, não é possível depositar
    if (!silencioso) {
        std::cout << "Saldo insuficiente. Considere a taxa de operação no "
                     "valor de R$ "
                  << this->taxaDeOperacao << "\n";
    }
    return false;
}

void ContaCorrente::mostrarDados() {
    std::cout << "~~~( conta " << this->numero << " )~~~" << std::endl;
    std::cout << "Tipo: conta corrente" << std::endl;
    std::cout << "Saldo: R$ " << std::setprecision(2) << std::fixed
              << this->saldo << "\n";
    std::cout << "Taxa de operação: R$ " << std::setprecision(2) << std::fixed
              << this->taxaDeOperacao << "\n\n";
}
