#include <iostream>
#include "input.h"
#include "../random/randlib.h"

#define pi 3.1416

void add1(int *var){ //pass by address
	*var=*var+1;
}
void ref1(int& var){ //pass by reference
	var=var+1;
}

void print(char *array){
	std::cout << array << std::endl;
}

double add(double& A, double& B){
	return A+B;                            	
}
double multiply(double& A, double& B){
	return A*B;
}

int main(){
	using namespace std;
	/*char zoznam[5] {'c','b','c'};
	//char list[1000000] {};
	//print(list);
	print(zoznam);	
	char a{42};
	print(&a);
	
	  */
	    
	//cout << add(3.14,2.71);
	
	long i=1;
	
	while(i>0){
		i++;
	} 
	cout << i-1 << endl;
	                         	
	/*
	const double gravity (9.81);
	int x;
	cout << "Address of x: " << &x << "kB" <<  endl;
	//inputFunc(x);   
	#ifdef pi
	cout << "Value of x+pi: " << x+pi << endl;
	#endif

	#ifndef pi
	cout << "Value of x: " << x << endl;
	#endif

	char a;
	
	for(int i=0;i<10;i++){
		cin >> a;
		cout << a << endl;
		}

	cout << a << " + 2 is: " << a+2 << endl;
	cout << "Which is: " << static_cast<char>(a+2) << endl;

	cout << "sizeof char:\t" << sizeof(a) << "b" << endl;
	cout << "sizeof int:\t" << sizeof(x) << "b" << endl;
	cout << "ASCII of " << a << " is: " << static_cast<int>(a) << endl;
	cout << "Gravity constant: " << gravity << endl;
  
  for(int i=0;i<10;i++){
    cout << randNr() <<endl;
  }                 */
  
  /*
  int a{1};
  for(int i=0;i<300000000;i++){
		add1(&a);		
	}
	cout << a << endl;*/
	
	
  
	return 0;
}
