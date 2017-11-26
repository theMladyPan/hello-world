#include <iostream>
#include <thread>
#include <chrono>

void a(){
	for(int i=0;i<1000;i++){
		std::cout << 1;// << std::endl;
		}
	}
void b(){
	for(int i=0;i<1000;i++){
		std::cout << 2;// << std::endl;
		}
	}

int main(int argc, char ** argv){
	std::thread  first(a), second(b);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	first.join();
	second.join();
	return 0;
	}
