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
            std::cout << "Opção inválida. Tente novamente.\n";
            menuPrincipal(false);
            break;
    }

    menuPrincipal();
}

void Menu::menuPrincipal_criarConta() {
    std::cout << "Opção escolhida: criar conta\n";

    int tipo = 0, numero;
    double saldoInicial, taxaDeOperacao, limite;

    while (tipo != TiposDeConta::Corrente && tipo != TiposDeConta::Poupanca) {
        std::cout << "Selecione o tipo de conta a ser criada:\n";
        std::cout << "1. Conta corrente\n";
        std::cout << "2. Conta poupança\n";
        std::cout << "Digite uma opção: ";
        std::cin >> tipo;
    }

    std::cout << "Número da conta: ";
    std::cin >> numero;

    std::cout << "Saldo inicial (R$): ";
    std::cin >> saldoInicial;

    if (tipo == TiposDeConta::Poupanca) {
        std::cout << "Taxa de operação (R$): ";
        std::cin >> taxaDeOperacao;

        ContaPoupanca conta(numero, saldoInicial, taxaDeOperacao);
        this->pacbank.inserir(conta);

    } else {
        std::cout << "Limite (R$): ";
        std::cin >> limite;

        ContaCorrente conta(numero, saldoInicial, limite);
        this->pacbank.inserir(conta);
    }
}

void Menu::menuPrincipal_selecionarConta() {
    std::cout << "Opção escolhida: selecionar conta\n";
    menuConta();
}

void Menu::menuPrincipal_removerConta() {
    std::cout << "Opção escolhida: remover conta\n";
}

void Menu::menuPrincipal_relatorioGeral() {
    std::cout << "Opção escolhida: gerar relatório geral\n";
}

void Menu::menuPrincipal_finalizar() {
    std::cout << "Opção escolhida: finalizar\n";
    exit(1);
}

void Menu::menuConta(bool exibirOpcoes) {
    int opcao;

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
            menuConta_depositar();
            break;

        case MenuConta::Sacar:
            menuConta_sacar();
            break;

        case MenuConta::Transferir:
            menuConta_transferir();
            break;

        case MenuConta::RelatorioIndividual:
            menuConta_relatorioIndividual();
            break;

        case MenuConta::Retornar:
            menuConta_retornar();
            break;

        default:
            std::cout << "\nOpção inválida. Tente novamente.\n";
            menuConta(false);
            break;
    }

    menuConta();
}

void Menu::menuConta_depositar() {
    std::cout << "Opção escolhida: depositar\n";
}

void Menu::menuConta_sacar() { std::cout << "Opção escolhida: sacar\n"; }

void Menu::menuConta_transferir() {
    std::cout << "Opção escolhida: transferir\n";
}

void Menu::menuConta_relatorioIndividual() {
    std::cout << "Opção escolhida: gerar relatório individual\n";
}

void Menu::menuConta_retornar() {
    std::cout << "Opção escolhida: retornar ao menu principal\n";
    menuPrincipal();
}