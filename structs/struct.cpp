#include <iostream>

struct Krabica{
	int x=0;
	int y=0;
	int z=0;
};

int main(){
	Krabica box1;
	box1.x=10;box1.y=15;box1.z=20;
	std::cout <<box1.x<<std::endl;
	return 0;
}
