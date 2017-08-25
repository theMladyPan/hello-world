#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <random>

#endif

double randNr(){	
  using namespace std;
  double randomNumber;
  random_device randDev;
  mt19937 mersenne(randDev());

  randomNumber = (mersenne()/10000000000.0);
  return randomNumber;
}
