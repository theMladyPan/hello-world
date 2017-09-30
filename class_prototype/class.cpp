#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <vector>

class Color{
	private:
		unsigned char R,G,B;

	public:
		Color(unsigned char r=0, unsigned char g=0, unsigned char b=0){
			R=r;
			G=g;
			B=b;
		}

	std::string get_hex(){
		std::ostringstream temp;
		if (R<16) {
			temp <<0;
		}
		temp << std::hex << (int)R;
		if (G<16) {
			temp <<0;
		}
		temp << std::hex << (int)G;
		if (B<16) {
			temp <<0;
		}
		temp << std::hex << (int)B;
		return temp.str();
	}

	void set(unsigned char r, unsigned char g, unsigned char b){
		if(r>=0 && r<256){
			R=r;
		}

		if(g>=0 && g<256){
			G=g;
		}
		if(b>=0 && b<256){
			B=b;
		}
	}
};

int main(int argc, char ** argv){

	Color farba;
	std::string exe_name = argv[0];
	std::vector<std::string> args;
	args.assign(argv+1, argv+argc);

	char R=0,G=0,B=0;

	for(std::vector<std::string>::iterator it = args.begin();it!=args.end();it++){
		if (*it=="-r") {
			R = std::atoi((*(++it)).c_str());
		}else if (*it == "-g") {
			G = std::atoi((*(++it)).c_str());
		}else if (*it == "-b") {
			B = std::atoi((*(++it)).c_str());
		}
	}

	farba.set(R,G,B);
	std::cout << "Farba [RGB]: " << farba.get_hex() << std::endl;

	return 0;
}
