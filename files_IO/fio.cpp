#include <fstream>
#include <iostream>

int main(int argc, char* argv[]){
	using namespace std;
	ofstream subor;
	if(argc==2){subor.open("std.txt");}
	else if(argc==3){subor.open(argv[2]);}
	else{return 1;}

	subor << argv[1] << endl;
	return 0;
}


