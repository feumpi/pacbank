### Universidade Federal do Espírito Santo

### INF09324 Programação Aplicada de Computadores 2021/1

### Trabalho final

### Aluno: 2020205193 Felipe Pereira Umpierre

### Professor: Rodrigo Martins de Siqueira Barbosa

---

# Sobre o programa

O programa é um sistema de banco com funcionamento em dois modos. Em modo interativo, o usuário pode criar contas correntes, contas poupancas, remover contas e gerar um relatório de todas as contas. Para cada conta, também pode emitir um relatório individual, fazer saques, depósitos ou transferências para outras contas, considerando algumas particularidades de cada tipo.

Em modo não interativo, o programa executa criando algumas contas e executando algumas operações entre elas por conta própria, e emitindo um relatório para cada no final.

# Compatibilidade

O programa foi testado e funcionou como esperado primariamente em ambiente Linux `5.14.10-1-MANJARO` e compilado com `gcc 11.1.0`.

# Como utilizar este programa

## Compilar

Este programa conta com um _Makefile_ para facilitar a sua vida! (eu ouvi um ponto extra?)

Use o comando **make** para compilar automaticamente todo o código-fonte e gerar os executáveis `interativo` e `executavel`:

```
> make

g++ -c banco.cpp
g++ -c contabancaria.cpp
g++ -c contacorrente.cpp
g++ -c contapoupanca.cpp
g++ -c executavel.cpp
g++ -c main.cpp
g++ -c main2.cpp
g++ -c menu.cpp
g++ -c relatorio.cpp
g++ banco.o contabancaria.o contacorrente.o contapoupanca.o main2.o menu.o -o interativo
g++ banco.o contabancaria.o contacorrente.o contapoupanca.o executavel.o main.o relatorio.o -o executavel
```

_Ou execute os comandos do output manualmente, se necessário_

## Executar

Em modo interativo:

```
./interativo
```

Em modo executável:

```
./executavel
```

### Modo executavel

Em modo executável, o programa executa e imprime na tela algumas operações pré-definidas:

```
Conta poupança (123) criada com saldo inicial de R$ 0.00 e limite no valor de R$ 1000.00

Conta corrente (456) criada com saldo inicial de R$ 0.00 e taxa de operação no valor de R$ 5.00


Depósito no valor de R$ 500.00 efetuado com sucesso!
Novo saldo: R$ 500.00

Taxa de operação aplicada: R$ 5.00
Depósito no valor de R$ 1200.00 efetuado com sucesso!
Novo saldo: R$ 1195.00


Saldo insuficiente. Usando limite emergencial para completar a operação.
Saque no valor de R$ 1500.00 efetuado com sucesso!
Novo saldo: R$ -1000.00

Taxa de operação aplicada: R$ 5.00
Saque no valor de R$ 1000.00 efetuado com sucesso!
Novo saldo: R$ 190.00


~~~( conta 123 )~~~
Tipo: conta poupança
Saldo: R$ -1000.00
Limite: R$ 1000.00


~~~( conta 456 )~~~
Tipo: conta corrente
Saldo: R$ 190.00
Taxa de operação: R$ 5.00
```

Em modo interativo, um menu é exibido exibido repetidamente até que a opção **finalizar** seja selecionada:

```
#############################
#          PACBANK          #
#############################
Bem-vindo ao Pacbank!


=====[ MENU PRINCIPAL ]=====

Opções:
1. Criar conta
2. Selecionar conta
3. Remover conta
4. Gerar relatório geral
5. Finalizar

Digite uma opção:
```

Na opção **1. Criar conta**, escolha o tipo de conta e digite as informações solicitadas:

```
=====[ CRIAR CONTA ]=====

Selecione o tipo de conta a ser criada:
1. Conta corrente
2. Conta poupança

Digite uma opção (0 = cancelar): 1

Criando uma nova conta corrente
Número da conta (0 = cancelar): 123
Saldo inicial (R$): 500
Taxa de operação (R$): 3.5
Conta corrente (123) criada com saldo inicial de R$ 500.00 e taxa de operação no valor de R$ 3.50
Conta 123 adicionada ao banco.
```

Sempre que for informado, é possível cancelar a operação (e retornar ao menu principal) digitando 0 como opção.

Ao informar um valor inválido, como um número negativo, um novo será solicitado:

```
Criando uma nova conta corrente
Número da conta (0 = cancelar): -30
O número da conta não pode ser negativo.

Número da conta (0 = cancelar):
```

Na opção **2. Selecionar conta**, digite o número da conta desejada para entrar no menu da conta:

```
Digite o número da conta desejada (0 = cancelar): 123


=====[ MENU DA CONTA ]=====
Conta selecionada: 123

Opções:
1. Depositar
2. Sacar
3. Transferir
4. Gerar relatório individual
5. Retornar ao menu principal

Digite uma opção:
```

#### Menu da conta

Na opção **2. Sacar**, digite o valor do saque, que pode ser concluido ou não de acordo com o saldo. Na conta corrente, considere que deve haver saldo também para a taxa de operação. Na poupança, o saldo pode ficar negativo até o valor de -limite.

```
=====[ SACAR ]=====

Digite o valor do saque (R$) (0 = cancelar): 50

Taxa de operação aplicada: R$ 3.50
Saque no valor de R$ 50.00 efetuado com sucesso!
Novo saldo: R$ 446.50
```

Na opção **2. Depositar**, digite o valor do depósito. Na conta corrente, considere que o valor da taxa de operação também será cobrado, e pode ser impossível fazer o depósito caso o saldo resultante fique negativo:

```
=====[ DEPOSITAR ]=====

Digite o valor a ser depositado (R$) (0 = cancelar): 3

Saldo insuficiente. Considere a taxa de operação no valor de R$ 3.50
```

Na opção **3. Transferir**, digite o valor da conta de destino e o valor do depósito. Para contas correntes envolvidas na transferência, será cobrado delas a taxa de operação referente a um saque ou a um depósito.

```
=====[ TRANSFERIR ]=====

Digite o número da conta de destino (0 = cancelar): 456
Não é possível transferir para si mesmo. Escolha outra conta.

Digite o número da conta de destino (0 = cancelar): 123
Digite o valor a ser transferido (0 = cancelar): 500

Transferência de R$ 500.00 para a conta 123 bem-sucedida!

Novo saldo na conta de origem: R$ 500.00
Novo saldo na conta de destino: R$ 496.50
```

_Observe que não é possível fazer uma transferência para si mesmo._

Na opção **4. Gerar relatório individual**, as informações sobre a própria conta são exibidas:

```
=====[ RELATÓRIO INDIVIDUAL ]=====

~~~( conta 456 )~~~
Tipo: conta poupança
Saldo: R$ 500.00
Limite: R$ 2000.00
```

Na opção **5. Retornar ao menu principal**, as opções do primeiro menu são exibidas novamente.

```
=====[ MENU PRINCIPAL ]=====

Opções:
1. Criar conta
2. Selecionar conta
3. Remover conta
4. Gerar relatório geral
5. Finalizar
```

### Menu principal

Na opção **3. Remover conta**, digite o número de uma conta existente para ser removida:

```
=====[ REMOVER CONTA ]=====

Digite o número da conta a ser removida (0 = cancelar): 666
Conta 666 removida do banco.
```

Na opção **4. Gerar relatório geral**, as informações de todas as contas serão exibidas:

```
=====[ RELATÓRIO GERAL ]=====

~~~( conta 123 )~~~
Tipo: conta corrente
Saldo: R$ 496.50
Taxa de operação: R$ 3.50

~~~( conta 456 )~~~
Tipo: conta poupança
Saldo: R$ 500.00
Limite: R$ 2000.00
```

Na opção **5. Finalizar**, o programa limpa a memória e encerra:

```
Digite uma opção: 5


Finalizando o programa...

Removendo todas as contas da memória...
```
