#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "banco.h"
#include "contacorrente.h"
#include "contapoupanca.h"

enum MenuPrincipal {
    CriarConta = 1,
    SelecionarConta,
    RemoverConta,
    RelatorioGeral,
    Finalizar
};

enum MenuConta {
    Depositar = 1,
    Sacar,
    Transferir,
    RelatorioIndividual,
    Retornar
};

/*
Crie uma classe Menu que instancie um banco e ofereça o seguinte menu
para o usuário:

- Criar conta: o usuário informa se é conta poupança ou corrente e os dados da
conta. O objeto correspondente é criado e inserido no banco através do método
inserir. Exibir uma mensagem de sucesso.
- Selecionar conta: o usuário informa o número da conta. Se a conta existir,
mostra o menu abaixo. Caso contrário, mostra mensagem de conta inexistente.
- Remover conta: o usuário informa o número da conta. Se a conta existe, então
ela é excluída e uma mensagem de sucesso é informada. Caso contrário, uma
mensagem de conta inexistente é informada.
- Gerar relatório: mostra os dados de todas as contas cadastradas no banco.
- Finalizar: termina a aplicação.

Se o usuário escolher “Selecionar Conta”, o seguinte menu deve aparecer:

- Depositar: recebe um valor e deposita na conta.
- Sacar: recebe um valor e tenta sacar da conta.
- Transferir: recebe um valor e o número de outra conta. Caso a conta exista,
transfere o valor de uma conta para a outra. Caso contrário, informar mensagem
de conta inexistente.
- Gerar relatório: mostra os dados da conta selecionada. Utilize o método
mostraDados criado anteriormente.
- Retornar ao menu anterior: exibe o menu anterior (opções 1 a 5).
*/

class Menu {
   public:
    Menu();

    //"Telas" do menu principal
    void menuPrincipal(bool exibirOpcoes = true);
    void menuPrincipal_criarConta();
    void menuPrincipal_selecionarConta();
    void menuPrincipal_removerConta();
    void menuPrincipal_relatorioGeral();
    void menuPrincipal_finalizar();

    //"Telas" do menu da conta selecionada
    void menuConta(ContaBancaria* conta, bool exibirOpcoes = true);
    void menuConta_depositar(ContaBancaria* conta);
    void menuConta_sacar(ContaBancaria* conta);
    void menuConta_transferir(ContaBancaria* conta);
    void menuConta_relatorioIndividual(ContaBancaria* conta);
    void menuConta_retornar();

   protected:
    Banco pacbank;
};

#endif