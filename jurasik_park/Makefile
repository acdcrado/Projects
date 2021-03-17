output: main.o dinosaur.o cages.o zoo.o
	g++ -std=c++14 main.o dinosaur.o cages.o zoo.o

main.o: main.cpp dinosaur.h cages.h zoo.h functions.h
	g++ -c -std=c++14 main.cpp

dinosaur.o: dinosaur.h dinosaur.cpp
	g++ -c -std=c++11 dinosaur.cpp

cages.o: cages.h cages.cpp
	g++ -c -std=c++11 cages.cpp

zoo.o: zoo.h zoo.cpp
	g++ -c -std=c++11 zoo.cpp
