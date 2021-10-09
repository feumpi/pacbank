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

Esse programa conta com um _Makefile_ para facilitar a sua vida! (eu ouvi um ponto extra?)

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
