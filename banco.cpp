#include "banco.h"

void Banco::inserir(ContaBancaria* conta) { this->contas.push_back(conta); }

void Banco::mostrarDados() {
    // Chama a implementação de mostrarDados para todas as contas do vetor, com
    // um separador em baixo
    for (auto conta : this->contas) {
        conta->mostrarDados();
    }
}

ContaBancaria* Banco::procurarConta(int numero) {
    for (auto conta : this->contas) {
        // Retorna o ponteiro da conta, se o número for o correspondente
        if (conta->getNumero() == numero) return conta;
    }
    // Ponteiro nulo se não encontrado
    return NULL;
}

void Banco::remover(ContaBancaria* conta) {
    // Encontra a posição da conta no vetor (um iterador para a posição dela)
    auto posicao = std::find(this->contas.begin(), this->contas.end(), conta);

    // Se a conta existe (iterador diferente de std::vector::end)
    if (posicao != this->contas.end()) {
        // Apaga a posição encontrada do vetor
        this->contas.erase(posicao);

        // Depois de remover o ponteiro do vetor, remove também a conta da heap
        delete conta;
    }
}

Banco::~Banco() {
    std::cout << "Removendo todas as contas da memória...\n";

    // Libera todas as contas alocadas na heap
    for (auto conta : this->contas) {
        delete conta;
    }
    // Limpa o vetor de contas
    this->contas.clear();
}