#include "menu.h"

Menu::Menu() {
    std::cout << "#############################\n";
    std::cout << "#          PACBANK          #\n";
    std::cout << "#############################\n";
    std::cout << "Bem-vindo ao Pacbank!"
              << "\n\n\n";

    menuPrincipal();
}

void Menu::menuPrincipal(bool exibirOpcoes) {
    int opcao;

    if (exibirOpcoes) {
        std::cout << "=====[ MENU PRINCIPAL ]=====\n\n";

        std::cout << "Opções:\n";
        std::cout << "1. Criar conta\n";
        std::cout << "2. Selecionar conta\n";
        std::cout << "3. Remover conta\n";
        std::cout << "4. Gerar relatório geral\n";
        std::cout << "5. Finalizar\n\n";
    }

    std::cout << "Digite uma opção: ";
    std::cin >> opcao;
    std::cout << "\n\n";

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
    std::cout << "=====[ CRIAR CONTA ]=====\n\n";

    int tipo = 0, numero;
    double saldoInicial = -1, taxaDeOperacao = -1, limite = -1;

    while (tipo != TiposDeConta::Corrente && tipo != TiposDeConta::Poupanca) {
        std::cout << "Selecione o tipo de conta a ser criada:\n";
        std::cout << "1. Conta corrente\n";
        std::cout << "2. Conta poupança\n\n";
        std::cout << "Digite uma opção (0 = cancelar): ";
        std::cin >> tipo;
        std::cout << "\n";
        if (tipo == 0) return;
    }

    std::cout << "Criando uma nova conta "
              << (tipo == TiposDeConta::Corrente ? "corrente" : "poupanca")
              << "\n";

    ContaBancaria* contaExistente = NULL;

    // Repete a coleta do número enquanto já existir uma conta com ele
    do {
        std::cout << "Número da conta (0 = cancelar): ";
        std::cin >> numero;
        if (numero == 0) return;
        contaExistente = this->pacbank.procurarConta(numero);

        if (contaExistente)
            std::cout
                << "Já existe uma conta com este número. Escolha outro.\n\n";

        if (numero < 0)
            std::cout << "O número da conta não pode ser negativo.\n\n";
    } while (contaExistente || numero < 0);

    // Repete a coleta do saldo enquanto ele não for >= 0
    do {
        std::cout << "Saldo inicial (R$): ";
        std::cin >> saldoInicial;
        if (saldoInicial < 0)
            std::cout << "Escolha um valor maior ou igual a 0\n\n";
    } while (saldoInicial < 0);

    if (tipo == TiposDeConta::Poupanca) {
        // Repete a coleta do limite enquanto ele não for > 0
        do {
            std::cout << "Limite (R$): ";
            std::cin >> limite;
            if (limite < 0)
                std::cout << "Escolha um valor maior ou igual a 0\n\n";
        } while (limite < 0);

        this->pacbank.inserir(new ContaPoupanca(numero, saldoInicial, limite));

    } else {
        // Repete a coleta da taxa enquanto ela não for > 0
        do {
            std::cout << "Taxa de operação (R$): ";
            std::cin >> taxaDeOperacao;
            if (taxaDeOperacao < 0)
                std::cout << "Escolha um valor maior ou igual a 0\n\n";
        } while (taxaDeOperacao < 0);

        this->pacbank.inserir(
            new ContaCorrente(numero, saldoInicial, taxaDeOperacao));
    }

    std::cout << std::endl;
}

void Menu::menuPrincipal_selecionarConta() {
    int numero;
    ContaBancaria* conta = NULL;

    std::cout << "=====[ SELECIONAR CONTA ]=====\n\n";

    do {
        std::cout << "Digite o número da conta desejada (0 = cancelar): ";
        std::cin >> numero;
        if (numero == 0) return;
        conta = this->pacbank.procurarConta(numero);

        if (!conta)
            std::cout << "Conta não encontrada. Verifique o número e tente "
                         "novamente\n\n";
    } while (!conta);

    std::cout << "\n\n";
    menuConta(conta);
}

void Menu::menuPrincipal_removerConta() {
    int numero;
    ContaBancaria* conta;

    std::cout << "=====[ REMOVER CONTA ]=====\n\n";

    do {
        std::cout << "Digite o número da conta a ser removida (0 = cancelar): ";
        std::cin >> numero;
        if (numero == 0) return;
        conta = this->pacbank.procurarConta(numero);
        if (!conta)
            std::cout << "Conta não encontrada. Verifique o número e tente "
                         "novamente\n\n";
    } while (!conta);

    this->pacbank.remover(conta);
}

void Menu::menuPrincipal_relatorioGeral() {
    std::cout << "=====[ RELATÓRIO GERAL ]=====\n\n";
    this->pacbank.mostrarDados();
}

void Menu::menuPrincipal_finalizar() {
    std::cout << "Finalizando o programa...\n\n";
    this->pacbank.~Banco();
    exit(1);
}

void Menu::menuConta(ContaBancaria* conta, bool exibirOpcoes) {
    int opcao;
    std::cout << "=====[ MENU DA CONTA ]=====\n";
    std::cout << "Conta selecionada: " << conta->getNumero() << "\n\n";

    if (exibirOpcoes) {
        std::cout << "Opções:\n";
        std::cout << "1. Depositar\n";
        std::cout << "2. Sacar\n";
        std::cout << "3. Transferir\n";
        std::cout << "4. Gerar relatório individual\n";
        std::cout << "5. Retornar ao menu principal\n\n";
    }

    std::cout << "Digite uma opção: ";
    std::cin >> opcao;
    std::cout << "\n\n";

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

    std::cout << "=====[ DEPOSITAR ]=====\n\n";

    // Repete a coleta do valor enquanto ele não for > 0
    do {
        std::cout << "Digite o valor a ser depositado (R$) (0 = cancelar): ";
        std::cin >> valor;
        if (valor < 0) std::cout << "Escolha um valor maior que 0.\n\n";
        if (valor == 0) return;
    } while (valor <= 0);

    std::cout << "\n";

    conta->depositar(valor);

    std::cout << "\n\n";
}

void Menu::menuConta_sacar(ContaBancaria* conta) {
    double valor;

    std::cout << "=====[ SACAR ]=====\n\n";

    // Repete a coleta do valor enquanto ele não for > 0
    do {
        std::cout << "Digite o valor do saque (R$) (0 = cancelar): ";
        std::cin >> valor;
        if (valor == 0) return;
        if (valor < 0) std::cout << "Escolha um valor maior que 0.\n\n";
    } while (valor <= 0);

    std::cout << "\n";

    conta->sacar(valor);

    std::cout << "\n\n";
}

void Menu::menuConta_transferir(ContaBancaria* conta) {
    int numero;
    double valor;
    ContaBancaria* contaDestino = NULL;

    std::cout << "=====[ TRANSFERIR ]=====\n\n";

    do {
        std::cout << "Digite o número da conta de destino (0 = cancelar): ";
        std::cin >> numero;
        contaDestino = this->pacbank.procurarConta(numero);
        if (numero == 0) return;

        if (!contaDestino)
            std::cout << "A conta não existe. Verifique o número e tente "
                         "novamente\n\n";

        if (contaDestino == conta) {
            std::cout << "Não é possível transferir para si mesmo. Escolha "
                         "outra conta.\n\n";
            contaDestino = NULL;
        }

    } while (!contaDestino);

    do {
        std::cout << "Digite o valor a ser transferido (0 = cancelar): ";
        std::cin >> valor;
        if (valor == 0) return;
        if (valor < 0) std::cout << "Escolha um valor maior que 0.\n\n";
    } while (valor <= 0);

    conta->transferir(valor, contaDestino);
}

void Menu::menuConta_relatorioIndividual(ContaBancaria* conta) {
    std::cout << "=====[ RELATÓRIO INDIVIDUAL ]=====\n\n";

    conta->mostrarDados();
    std::cout << "\n====================\n\n";
}

void Menu::menuConta_retornar() { menuPrincipal(); }