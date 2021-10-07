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

ContaBancaria* Banco::procurarConta(int numero) {
    for (auto conta : this->contas) {
        if (conta->getNumero() == numero) return conta;
    }
    return NULL;
}

void Banco::remover(ContaBancaria* conta) {
    // Encontra a posição da conta no vetor (um iterador para a posição dela)
    std::vector<ContaBancaria*>::iterator posicao =
        std::find(this->contas.begin(), this->contas.end(), conta);

    // Se a conta existe (iterador diferente de std::vector::end)
    if (posicao != this->contas.end()) {
        // Apaga a posição encontrada do vetor
        this->contas.erase(posicao);

        // Depois de remover o ponteiro do vetor, remove também a conta da heap
        delete conta;
    }
}

Banco::~Banco() {
    std::cout << "Removendo contas da memória...\n";
    for (auto conta : this->contas) {
        delete conta;
    }
    this->contas.clear();
}