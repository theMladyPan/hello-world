#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif /* end of include guard: __IOSTREAM__ */

/*
double min l>1: 1+5.55112e-17
double min l: 4.94066e-324
float min l>1: 1+2.98023e-08
float min l: 1.4013e-45
*/

using namespace std;

int main(int argc, char const *argv[]) {
  uint32_t i;
  double d=1,l=2,e=1;

  while(d!=l){
    l=d;
    e/=2;
    d=1+e;
  }

  std::cout << "double min l>1: " << l<<"+" << e << '\n';

  e=1;
  while(e!=0){
    l=e;
    e/=2;
  }
  std::cout << "double min l: " << l<< '\n';

  float df=1,lf=2,ef=1;

  while(df!=lf){
    lf=df;
    ef/=2;
    df=1+ef;
  }

  std::cout << "float min l>1: " << lf<<"+" << ef << '\n';

  ef=1;
  while(ef!=0){
    lf=ef;
    ef/=2;
  }
  std::cout << "float min l: " << lf << '\n';


  return 0;
}
