#include <iostream>
#include <math.h>

void tlac_chybu(const char* chyba){
	std::cerr << "Error: "<< chyba << std::endl;
}

int main(int argc, char* argv[]){

	using namespace std;
	cout << "Zadaj číslo: ";
	double d;
	cin >> d;

	try{
		if(d<0.0)throw "Číslo nesmie byť negatívne.";
		cout << d << "^0.5=" << sqrt(d) << endl;
	}catch (const char* strException){
		tlac_chybu(strException);
	}catch (...){
		//caught something unpredictable
	}
	return 0;
}
