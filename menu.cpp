#include "menu.h"

Menu::Menu() {
    std::cout << "Bem-vindo ao Pacbank!" << std::endl;

    menuPrincipal();
}

void Menu::menuPrincipal(bool exibirOpcoes) {
    int opcao;

    if (exibirOpcoes) {
        std::cout << "Opções:\n\n";

        std::cout << "1. Criar conta\n";
        std::cout << "2. Selecionar conta\n";
        std::cout << "3. Remover conta\n";
        std::cout << "4. Gerar relatório geral\n";
        std::cout << "5. Finalizar\n\n";
    }

    std::cout << "Digite uma opção: ";
    std::cin >> opcao;

    switch (opcao) {
        case MenuPrincipal::CriarConta:
            menuPrincipal_criarConta();
            break;

        case MenuPrincipal::SelecionarConta:
            menuPrincipal_selecionarConta();
            break;

        case MenuPrincipal::RemoverConta:
            menuPrincipal_removerConta();
            break;

        case MenuPrincipal::RelatorioGeral:
            menuPrincipal_relatorioGeral();
            break;

        case MenuPrincipal::Finalizar:
            menuPrincipal_finalizar();
            break;

        default:
            std::cout << "Opção inválida. Tente novamente.\n\n";
            menuPrincipal(false);
            break;
    }

    menuPrincipal();
}

void Menu::menuPrincipal_criarConta() {
    std::cout << "Opção escolhida: criar conta\n\n";

    int tipo = 0, numero;
    double saldoInicial, taxaDeOperacao, limite;

    while (tipo != TiposDeConta::Corrente && tipo != TiposDeConta::Poupanca) {
        std::cout << "Selecione o tipo de conta a ser criada:\n";
        std::cout << "1. Conta corrente\n";
        std::cout << "2. Conta poupança\n\n";
        std::cout << "Digite uma opção: ";
        std::cin >> tipo;
    }

    std::cout << std::endl;
    std::cout << "Número da conta: ";
    std::cin >> numero;

    std::cout << "Saldo inicial (R$): ";
    std::cin >> saldoInicial;

    if (tipo == TiposDeConta::Poupanca) {
        std::cout << "Limite (R$): ";
        std::cin >> limite;

        this->pacbank.inserir(new ContaPoupanca(numero, saldoInicial, limite));

    } else {
        std::cout << "Taxa de operação (R$): ";
        std::cin >> taxaDeOperacao;

        this->pacbank.inserir(
            new ContaCorrente(numero, saldoInicial, taxaDeOperacao));
    }
}

void Menu::menuPrincipal_selecionarConta() {
    int numero;

    std::cout << "Opção escolhida: selecionar conta\n\n";
    std::cout << "Digite o número da conta desejada: ";
    std::cin >> numero;

    ContaBancaria* conta = this->pacbank.procurarConta(numero);

    if (conta) {
        menuConta(conta);
    } else {
        std::cout
            << "Conta não encontrada. Verifique o número e tente novamente\n";
    }
}

void Menu::menuPrincipal_removerConta() {
    int numero;

    std::cout << "Opção escolhida: remover conta\n\n";

    std::cout << "Digite o número da conta a ser removida: ";
    std::cin >> numero;

    ContaBancaria* conta = this->pacbank.procurarConta(numero);

    if (conta) {
        this->pacbank.remover(conta);
        std::cout << "Conta " << numero << " removida com sucesso.\n";
    } else {
        std::cout
            << "Conta não encontrada. Verifique o número e tente novamente.\n";
    }
}

void Menu::menuPrincipal_relatorioGeral() {
    std::cout << "Opção escolhida: gerar relatório geral\n\n";
    this->pacbank.mostrarDados();
}

void Menu::menuPrincipal_finalizar() {
    std::cout << "Opção escolhida: finalizar\n\n";
    this->pacbank.~Banco();
    exit(1);
}

void Menu::menuConta(ContaBancaria* conta, bool exibirOpcoes) {
    int opcao;

    std::cout << "Conta selecionada: " << conta->getNumero() << "\n\n";

    if (exibirOpcoes) {
        std::cout << "Opções:\n\n";

        std::cout << "1. Depositar\n";
        std::cout << "2. Sacar\n";
        std::cout << "3. Transferir\n";
        std::cout << "4. Gerar relatório individual\n";
        std::cout << "5. Retornar ao menu principal\n\n";
    }

    std::cout << "Digite uma opção: ";
    std::cin >> opcao;

    switch (opcao) {
        case MenuConta::Depositar:
            menuConta_depositar(conta);
            break;

        case MenuConta::Sacar:
            menuConta_sacar(conta);
            break;

        case MenuConta::Transferir:
            menuConta_transferir(conta);
            break;

        case MenuConta::RelatorioIndividual:
            menuConta_relatorioIndividual(conta);
            break;

        case MenuConta::Retornar:
            menuConta_retornar();
            break;

        default:
            std::cout << "\nOpção inválida. Tente novamente.\n\n";
            menuConta(conta, false);
            break;
    }

    menuConta(conta);
}

void Menu::menuConta_depositar(ContaBancaria* conta) {
    double valor;

    std::cout << "Opção escolhida: depositar\n";

    std::cout << "Digite o valor a ser depositado: ";
    std::cin >> valor;

    conta->depositar(valor);
}

void Menu::menuConta_sacar(ContaBancaria* conta) {
    double valor;

    std::cout << "Opção escolhida: sacar\n\n";

    std::cout << "Digite o valor do saque (R$): ";
    std::cin >> valor;

    conta->sacar(valor);
}

void Menu::menuConta_transferir(ContaBancaria* conta) {
    std::cout << "Opção escolhida: transferir\n\n";
}

void Menu::menuConta_relatorioIndividual(ContaBancaria* conta) {
    std::cout << "Opção escolhida: gerar relatório individual\n\n";

    std::cout << "==========\n";
    conta->mostrarDados();
    std::cout << "==========\n";
}

void Menu::menuConta_retornar() {
    std::cout << "Opção escolhida: retornar ao menu principal\n\n";
    menuPrincipal();
}