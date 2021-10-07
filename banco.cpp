#include "banco.h"

void Banco::inserir(ContaBancaria* conta) {
    this->contas.push_back(conta);
    std::cout << "Conta criada com sucesso!\n";
}

void Banco::mostrarDados() {
    std::cout << "====================\n";
    for (auto conta : this->contas) {
        conta->mostrarDados();
        std::cout << "====================\n";
    }
}

Banco::~Banco() {
    std::cout << "Removendo contas da memória...\n";
    for (auto conta : this->contas) {
        delete conta;
    }
    this->contas.clear();
}