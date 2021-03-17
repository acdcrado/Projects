output: main.o ts.o 
	g++ -std=c++14 main.o ts.o 

main.o: main.cpp ts.h functions.h doctest.h
	g++ -c -std=c++14 main.cpp

ts.o: ts.h ts.cpp
	g++ -c -std=c++11 ts.cpp

