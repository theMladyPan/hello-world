all: random

random: random.o randlib.o 
	g++ -Wall -std=c++11 random.o randlib.o -o random

random.o: random.cpp randlib.h
	g++ -Wall -std=c++11 -c random.cpp

randlib.o: randlib.cpp randlib.h
	g++ -Wall -std=c++11 -c randlib.cpp
