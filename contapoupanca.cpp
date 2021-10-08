#include "contapoupanca.h"

ContaPoupanca::ContaPoupanca(int numero, double saldo, double limite)
    : ContaBancaria(numero, saldo) {
    this->limite = limite;
}

void ContaPoupanca::sacar(double valor) {
    // Garante que o valor não é negativo
    valor = std::abs(valor);

    // Se o saldo após substrair o valor não ficar negativo além do limite
    if ((this->saldo - valor) >= this->limite * -1) {
        if (this->saldo < valor)
            std::cout << "Saldo insuficiente. Usando limite emergencial para "
                         "completar a operação.\n";

        ContaBancaria::sacar(valor);
    } else {
        std::cout
            << "Saldo e limite insuficientes. Sua poupança pode exceder o "
               "saldo em até R$ "
            << this->limite << "\n";
    }
}

void ContaPoupanca::mostrarDados() {
    std::cout << "Número: " << this->numero << std::endl;
    std::cout << "Tipo: conta poupança" << std::endl;
    std::cout << "Saldo: R$ " << this->saldo << std::endl;
    std::cout << "Limite: R$ " << this->limite << std::endl;
}
