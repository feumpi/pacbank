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
            // Volta ao menu sem reimprimir as opções
            menuPrincipal(false);
            break;
    }

    // Volta ao menu depois de concluir a operação anterior
    menuPrincipal();
}

void Menu::menuPrincipal_criarConta() {
    std::cout << "=====[ CRIAR CONTA ]=====\n\n";

    int tipo = 0, numero;
    double saldoInicial = -1, taxaDeOperacao = -1, limite = -1;
    ContaBancaria* contaExistente;

    // Repete a coleta do tipo de conta enquanto for inválido, cancela a
    // operação se for 0
    while (tipo != TiposDeConta::Corrente && tipo != TiposDeConta::Poupanca) {
        std::cout << "Selecione o tipo de conta a ser criada:\n";
        std::cout << "1. Conta corrente\n";
        std::cout << "2. Conta poupança\n\n";

        std::cout << "Digite uma opção (0 = cancelar): ";
        std::cin >> tipo;
        std::cout << "\n";

        if (tipo == 0) return;
    }

    // Imprime o tipo de conta escolhida
    std::cout << "Criando uma nova conta "
              << (tipo == TiposDeConta::Corrente ? "corrente" : "poupanca")
              << "\n";

    // Repete a coleta do número enquanto já existir uma conta com ele ou o
    // número for negativo
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

    // Se for poupança
    if (tipo == TiposDeConta::Poupanca) {
        // Repete a coleta do limite enquanto ele não for >= 0
        do {
            std::cout << "Limite (R$): ";
            std::cin >> limite;
            if (limite < 0)
                std::cout << "Escolha um valor maior ou igual a 0\n\n";
        } while (limite < 0);

        // Cria a poupança na heap usando os dados coletados e insere no banco
        this->pacbank.inserir(new ContaPoupanca(numero, saldoInicial, limite));

    }

    // Se for corrente
    else {
        // Repete a coleta da taxa enquanto ela não for >= 0
        do {
            std::cout << "Taxa de operação (R$): ";
            std::cin >> taxaDeOperacao;
            if (taxaDeOperacao < 0)
                std::cout << "Escolha um valor maior ou igual a 0\n\n";
        } while (taxaDeOperacao < 0);

        // Cria a conta corrente na heap usando os dados coletados e insere no
        // banco
        this->pacbank.inserir(
            new ContaCorrente(numero, saldoInicial, taxaDeOperacao));
    }

    std::cout << std::endl;
}

void Menu::menuPrincipal_selecionarConta() {
    int numero;
    ContaBancaria* conta;

    std::cout << "=====[ SELECIONAR CONTA ]=====\n\n";

    // Repete a coleta do número enquanto não for encontrada, ou cancela a
    // operação se for 0
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

    // Continua para o menu da conta quando encontrada
    menuConta(conta);
}

void Menu::menuPrincipal_removerConta() {
    int numero;
    ContaBancaria* conta;

    std::cout << "=====[ REMOVER CONTA ]=====\n\n";

    // Repete a coleta do número enquanto não encontrada, ou cancela a operação
    // se for 0
    do {
        std::cout << "Digite o número da conta a ser removida (0 = cancelar): ";
        std::cin >> numero;
        if (numero == 0) return;
        conta = this->pacbank.procurarConta(numero);
        if (!conta)
            std::cout << "Conta não encontrada. Verifique o número e tente "
                         "novamente\n\n";
    } while (!conta);

    // Passa a conta a ser removida para o banco
    this->pacbank.remover(conta);
}

void Menu::menuPrincipal_relatorioGeral() {
    std::cout << "=====[ RELATÓRIO GERAL ]=====\n\n";
    this->pacbank.mostrarDados();
}

void Menu::menuPrincipal_finalizar() {
    std::cout << "Finalizando o programa...\n\n";
    // Chama o destrutor do banco manualmente (ignorado pelo exit)
    this->pacbank.~Banco();

    // Encerra o programa
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

            // Volta para o menu da conta sem reexibir as opções
            menuConta(conta, false);
            break;
    }

    // Volta para o menu da conta após concluir a ação anterior
    menuConta(conta);
}

void Menu::menuConta_depositar(ContaBancaria* conta) {
    double valor;

    std::cout << "=====[ DEPOSITAR ]=====\n\n";

    // Repete a coleta do valor enquanto ele não for > 0, ou cancela a operação
    // se for 0
    do {
        std::cout << "Digite o valor a ser depositado (R$) (0 = cancelar): ";
        std::cin >> valor;
        if (valor < 0) std::cout << "Escolha um valor maior que 0.\n\n";
        if (valor == 0) return;
    } while (valor < 0);

    std::cout << "\n";

    // Faz o depósito
    conta->depositar(valor);

    std::cout << "\n\n";
}

void Menu::menuConta_sacar(ContaBancaria* conta) {
    double valor;

    std::cout << "=====[ SACAR ]=====\n\n";

    // Repete a coleta do valor enquanto ele não for > 0, ou cancela a operação
    // se for 0
    do {
        std::cout << "Digite o valor do saque (R$) (0 = cancelar): ";
        std::cin >> valor;
        if (valor == 0) return;
        if (valor < 0) std::cout << "Escolha um valor maior que 0.\n\n";
    } while (valor < 0);

    std::cout << "\n";

    // Faz o saque
    conta->sacar(valor);

    std::cout << "\n\n";
}

void Menu::menuConta_transferir(ContaBancaria* conta) {
    int numero;
    double valor;
    ContaBancaria* contaDestino = NULL;

    std::cout << "=====[ TRANSFERIR ]=====\n\n";

    // Repete a coleta do número enquanto não for encontrada ou for a própria
    // conta atual, ou cancela a operação se for 0
    do {
        std::cout << "Digite o número da conta de destino (0 = cancelar): ";
        std::cin >> numero;
        contaDestino = this->pacbank.procurarConta(numero);
        if (numero == 0) return;

        if (!contaDestino)
            std::cout << "A conta não existe. Verifique o número e tente "
                         "novamente\n\n";

        // Se origem = destino, destino se torna NULL
        if (contaDestino == conta) {
            std::cout << "Não é possível transferir para si mesmo. Escolha "
                         "outra conta.\n\n";
            contaDestino = NULL;
        }

    } while (!contaDestino);

    // Repete a coleta do valor enquanto for negativo, ou cancela a operação se
    // for 0
    do {
        std::cout << "Digite o valor a ser transferido (0 = cancelar): ";
        std::cin >> valor;
        if (valor == 0) return;
        if (valor < 0) std::cout << "Escolha um valor maior que 0.\n\n";
    } while (valor < 0);

    // Faz a transferência
    conta->transferir(valor, contaDestino);
}

void Menu::menuConta_relatorioIndividual(ContaBancaria* conta) {
    std::cout << "=====[ RELATÓRIO INDIVIDUAL ]=====\n\n";
    conta->mostrarDados();
}

void Menu::menuConta_retornar() {
    // Retorna ao menu principal
    menuPrincipal();
}