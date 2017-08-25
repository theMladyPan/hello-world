all: hw

hw: hw.o input.o randlib.o
	g++ -Wall hw.o input.o randlib.o -o hw
                                       
#randlib.o: randlib.cpp randlib.h
#  g++ -Wall -std=c++11 -c ../random/randlib.cpp
  
input.o: input.cpp input.h
	g++ -Wall -c input.cpp
  
hw.o: hw.cpp input.h
	g++ -Wall -std=c++11 -c hw.cpp
  
