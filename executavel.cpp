#include "executavel.h"

Executavel::Executavel() {
    ContaPoupanca poupanca(123, 0, 1000);
    ContaCorrente corrente(456, 0, 5);

    poupanca.depositar(500);
    corrente.depositar(1200);

    poupanca.sacar(1500);
    corrente.sacar(1000);

    Relatorio relatorio;

    relatorio.gerarRelatorio(&poupanca);
    relatorio.gerarRelatorio(&corrente);
}