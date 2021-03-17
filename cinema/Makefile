output: main.o tickets.o events.o auditorium.o theatre.o
	g++ -std=c++14 main.o tickets.o events.o auditorium.o theatre.o

main.o: main.cpp tickets.h events.h auditorium.h functions.h theatre.h
	g++ -c -std=c++14 main.cpp

tickets.o: tickets.h tickets.cpp
	g++ -c -std=c++11 tickets.cpp

events.o: events.h events.cpp
	g++ -c -std=c++11 events.cpp

auditorium.o: auditorium.h auditorium.cpp
	g++ -c -std=c++11 auditorium.cpp

theatre.o: theatre.h theatre.cpp
	g++ -c -std=c++11 theatre.cpp
