#include <iostream>

template <typename T>

void print(T *param){
	using namespace std;
	cout << "Passed param: " << *param << endl << "Address: " << (void *)param << endl;
}

template <typename T>
T get(T *param){
	using namespace std;
	cout << "type in parameter: ";
	cin>>*param;
	return *param;
}

int main(int argc, char ** argv){
	using namespace std;

	int cislo = 10;
	//char *string = new char;
	char *string = "idiotkokoko";

	//print(&cislo);
	//get(&cislo);
	//print(&cislo);
	//string++;

	//cout<< "Char: "<<*string<<endl<<"Addr: "<<(void *)string<<endl;
	do{
		print(string++);
		}while(*string!='\0');
	cout << endl;

	return 0;
}

