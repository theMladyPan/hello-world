#include <iostream>
#include <stdlib.h>

long fib(long n){
	if(n>1){
		return n+fib(n-1);	
	}else if(n==1){
		return n+1;
	}else{
		return 0;
	}
}

int main(int argc, char *argv[]){
	using namespace std;
	long n;
	
	if(argc>1){
		n=atoi(argv[1]);	
	}else{
		cout << "input nr.: ";
		cin >> n;
	}
	long out;
	for(int i=0;i<10000;i++){
		out=fib(n);
	}
	cout << fib(n) << endl;
	
	return 0;
}