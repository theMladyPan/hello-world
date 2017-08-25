#include <iostream>

void memory_leak(){
	int *leak = new int;
}

void dynAlMem(){
	int *i = new int;
	delete i;
}

void statAlMem(){
 	int i;
}

int main(int argc, char *argv[]){            
  using namespace std;

	/*if(argc>1){
		cout<<argv[1]<<endl;
	}

	int *premenna = new int;
	cout << *premenna<<endl;
	
	delete premenna;
	
	cout << *premenna << endl;
	            */
	/*      
	for(int i=0;i<1000000;i++){
		statAlMem();
	}  */    
	
	int *a = new int[100000000];
	
	
	
	return 0;
}