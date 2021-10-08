#ifndef CONTA_BANCARIA_H
#define CONTA_BANCARIA_H

enum TiposDeConta { Corrente = 1, Poupanca };

/*
Crie uma classe abstrata ContaBancaria que contém como atributos o número da
conta e o saldo, e como métodos virtuais sacar e depositar que recebem um
parâmetro do tipo double.

Incremente a classe ContaBancaria com o método transferir, que recebe o
parâmetro valor (double) e um objeto ContaBancaria e transfere o valor desejado
da conta atual para cada conta informada. Use os métodos sacar e depositar para
isso.

Dica: Caso vocês tenham dificuldades com o método mostrarDados, devido a este
não estar na ContaBancária, e sim nas classes derivadas, vocês podem contornar
este problema declarando mostrarDados como uma função virtual na classe
ContaBancaria.

*/

class ContaBancaria {
   public:
    ContaBancaria(int numero, double saldo);

    // Getters
    int getNumero();
    double getSaldo();

    // Remove o valor solicitado da conta SEM FAZER VALIDAÇÃO
    virtual void sacar(double valor);

    // Adiciona o valor solicitado à conta
    void depositar(double valor);

    // Saca o valor informado da conta, se disponível, e deposita em outra
    // informada
    void transferir(double valor, ContaBancaria conta);

    virtual void mostrarDados();

   protected:
    int numero;
    double saldo;
};

#endif