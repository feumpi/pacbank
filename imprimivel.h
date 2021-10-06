#ifndef IMPRIMIVEL_H
#define IMPRIMIVEL_H

/*
Crie uma classe puramente abstrata Imprimivel que declara um método
mostrarDados. Faça as classes ContaCorrente e ContaPoupança herdarem de
Imprimivel e na implementação do método, mostre os atributos de cada conta.
*/

class Imprimivel {
 public:
  virtual void mostrarDados() = 0;
};

#endif