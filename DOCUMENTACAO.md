### Universidade Federal do Espírito Santo

### INF09324 Programação Aplicada de Computadores 2021/1

### Trabalho final

### Aluno: 2020205193 Felipe Pereira Umpierre

### Professor: Rodrigo Martins de Siqueira Barbosa

---

# Sobre o desenvolvimento deste programa

## Convenções

### Nomes de classes

Para todos os nomes de classes, foi adotada a convenção _PascalCase_, com todas as iniciais de palavras em letra maiúscula.

```cpp
class NomeDaClasse {
    (...)
};
```

### Nomes de variáveis, propriedades e métodos

Para todos os nomes de variáveis, propriedades e métodos, foi adotada a convenção _camelCase_, com a primeira inicial minúscula e todas as iniciais seguintes em letra maiúscula.

Métodos e propriedades da própria classe são sempre usados a partir do ponteiro `this` para evitar ambiguidades.

```cpp
Classe::Classe(int propriedade) {
    this->propriedade = propriedade;
}
```

## Sobre as classes

### Classe ContaBancaria

Representa uma conta bancária básica contendo um número e um saldo, além dos métodos para sacar, depositar e transferir.

### Classe ContaCorrente : ContaBancaria

Herdando as propriedades e métodos de `ContaBancaria`, adiciona uma propriedade `double taxaDeOperacao` que deve ser descontada antes de um saque ou depósito.

Reimplementa os métodos `ContaBancaria::sacar` e `ContaBancaria::depositar` para descontar a taxa e verificar se o saldo final não é negativo antes de chamar a implementação da classe-pai.

### Classe ContaPoupanca : ContaBancaria

Herdando as propriedades e métodos de `ContaBancaria`, adiciona uma propriedade `double limite`, que representa o quanto o saldo pode ficar negativo.

Reimplementa os métodos `ContaBancaria::sacar` e `ContaBancaria::depositar` para verificar se o saldo final não fica mais negativo que `limite * -1` antes de chamar a implementação da classe-pai.

### Classe Banco

Responsável por guardar os ponteiros das contas criadas na heap em `std::vector<ContaBancaria*> contas` e por disponibilizar métodos para inserir ou remover uma conta e para procurar e retornar uma conta a partir do número dela.

### Classe Imprimivel

### Classe Menu

### Classe Relatorio

### Classe Executavel

---

## Fluxo do programa

### Execução

O programa pode ser iniciado de duas formas, a depender da inclusão de `main.cpp` ou `main2.cpp` na compilação.

Usando `main.cpp`, uma sequencia de ações pré-definidas na classe `Executavel` é executada.

Usando `main2.cpp`, o programa exibe um menu interativo onde o usuário pode criar, selecionar e remover contas, além de sacar, depositar, transferir e gerar relatórios.

### Menu principal

A princípio, um objeto `Banco pacbank` é criado e o menu principal é exibido com `Menu::menuPrincipal`, lista as opções disponíveis de 1 a 5 (representadas por `enum MenuPrincipal`) e coleta a entrada do usuário chamando o menu recursivamente (mas sem reexibir as opções) até que uma opção válida seja digitada.

Tendo uma opção válida, a função correspondene, por exemplo `Menu::menuPrincipal_criarConta` é chamada e cuida do processo.

Ao final, `Menu::menuPrincipal` é chamado novamente para aguardar a pŕoxima ação do usuário, até que ele decida sair.

### Finalização do programa

Quando o usuário decide sair (selecionando a última opção do menu principal), o destrutor `Banco::~Banco` é chamado manualmente para limpar a memória e o programa encerrado usando `exit(1)`.

### Criação de contas

O programa coleta os dados da conta (tipo, número, saldo inicial e limite ou taxa de operação) e instancia na heap um objeto `ContaCorrente` ou `ContaPoupanca`, de acordo com o selecionado pelo usuário, e passa o ponteiro desse objeto para `Banco::inserir`, que o guarda no vetor de contas.

### Remoção de contas

O programa coleta o número da conta a ser removida e verifica se ela existe usando `Banco::procurarConta`. Se existir, o ponteiro é passado para `Banco::remover`, que encontra a posição dela no vetor usando `std::find` e então a remove e redimensiona o vetor usando `std::erase`.

### Relatórios

A geração de relatórios é feito na implementação de `Imprimivel::mostrarDados` feita por cada classe. Em `ContaCorrente` e `ContaPoupanca`, o método imprime as informações disponíveis sobre a própria conta. Em `Banco`, é chamado o método `mostrarDados` de cada conta inserida no vetor.

### Menu da conta

Escolhendo a opção de selecionar uma conta, o programa coleta o número da conta, verifica se ela existe com `Banco::procurarConta` e exibe um novo menu com opções referentes à conta selecionada usando `Menu::menuConta`, além da opção de voltar ao principal.

### Saque

Com a conta já selecionada, o programa coleta o valor desejado para o saque. Após verificações próprias das implementações de `ContaCorrente::saque` e `ContaPoupanca::saque`, que levam em conta a taxa de operação, limite e mínimo valor possível para o saldo em cada, o método da classe pai `ContaBancaria::saque` é usado para fazer de fato o saque, se ele for válido.

### Depósito

### Transferência
