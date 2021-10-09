output: banco.o contabancaria.o contacorrente.o contapoupanca.o executavel.o main.o main2.o menu.o relatorio.o
	g++ banco.o contabancaria.o contacorrente.o contapoupanca.o main2.o menu.o -o interativo
	g++ banco.o contabancaria.o contacorrente.o contapoupanca.o executavel.o main.o relatorio.o -o executavel

banco.o: banco.cpp 
	g++ -c banco.cpp

contabancaria.o: contabancaria.cpp 
	g++ -c contabancaria.cpp

contacorrente.o: contacorrente.cpp 
	g++ -c contacorrente.cpp

contapoupanca.o: contapoupanca.cpp 
	g++ -c contapoupanca.cpp

relatorio.o: relatorio.cpp 
	g++ -c relatorio.cpp

main.o: main.cpp
	g++ -c main.cpp

main2.o: main2.cpp 
	g++ -c main2.cpp

menu.o: menu.cpp 
	g++ -c menu.cpp

executavel.o: executavel.cpp 
	g++ -c executavel.cpp

clean:
	rm *.o interativo executavel