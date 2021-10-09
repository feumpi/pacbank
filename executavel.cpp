#include "executavel.h"

Executavel::Executavel() {
    // Cria as contas com saldo inicial zerado
    ContaPoupanca poupanca(123, 0, 1000);
    std::cout << "\n";
    ContaCorrente corrente(456, 0, 5);
    std::cout << "\n\n";

    // Deposita um valor para cada
    poupanca.depositar(500);
    std::cout << "\n";
    corrente.depositar(1200);
    std::cout << "\n\n";

    // Saca um valor para cada, usando o limite na poupança
    poupanca.sacar(1500);
    std::cout << "\n";
    corrente.sacar(1000);
    std::cout << "\n\n";

    // Gera e imprime um relatório para cada conta
    Relatorio relatorio;
    relatorio.gerarRelatorio(&poupanca);
    std::cout << "\n";
    relatorio.gerarRelatorio(&corrente);
}