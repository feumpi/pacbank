#include "executavel.h"

Executavel::Executavel() {
    ContaPoupanca poupanca(123, 0, 1000);
    std::cout << "\n";

    ContaCorrente corrente(456, 0, 5);
    std::cout << "\n\n";

    poupanca.depositar(500);
    std::cout << "\n";

    corrente.depositar(1200);
    std::cout << "\n\n";

    poupanca.sacar(1500);
    std::cout << "\n";

    corrente.sacar(1000);
    std::cout << "\n\n";

    Relatorio relatorio;

    relatorio.gerarRelatorio(&poupanca);
    std::cout << "\n";

    relatorio.gerarRelatorio(&corrente);
}