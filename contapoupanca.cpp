#include "contapoupanca.h"

ContaPoupanca::ContaPoupanca(int numero, double saldo, double limite)
    : ContaBancaria(numero, saldo) {
    this->limite = limite;

    std::cout << "Conta poupança (" << this->numero
              << ") criada com saldo inicial de R$ " << std::setprecision(2)
              << std::fixed << this->saldo << " e limite no valor de R$ "
              << std::fixed << this->limite << "\n";
}

bool ContaPoupanca::sacar(double valor, bool silencioso) {
    // Se o saldo após subtrair o valor não ficar negativo além do limite
    if ((this->saldo - valor) >= this->limite * -1) {
        // Aviso de uso do limite (saldo negativo)
        if (this->saldo < valor && !silencioso) {
            std::cout << "Saldo insuficiente. Usando limite emergencial para "
                         "completar a operação.\n";
        }

        // Faz o saque do valor solicitado, em modo silencioso ou não
        ContaBancaria::sacar(valor, silencioso);

        // Sucesso
        return true;
    }

    // Do contrário, não é possível sacar
    if (!silencioso) {
        std::cout
            << "Saldo e limite insuficientes. Sua poupança pode exceder o "
               "saldo em até R$ "
            << std::setprecision(2) << std::fixed << this->limite << "\n";
    }

    // Falha
    return false;
}

void ContaPoupanca::mostrarDados() {
    std::cout << "~~~( conta " << this->numero << " )~~~" << std::endl;
    std::cout << "Tipo: conta poupança" << std::endl;
    std::cout << "Saldo: R$ " << std::setprecision(2) << std::fixed
              << this->saldo << std::endl;
    std::cout << "Limite: R$ " << std::setprecision(2) << std::fixed
              << this->limite << "\n\n";
}
