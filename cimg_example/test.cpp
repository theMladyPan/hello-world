#define cimg_use_jpeg
#include "CImg.h"
#include <iostream>

using namespace cimg_library;
using namespace std;

int main(int argc, char** argv){
	CImg<unsigned char> * image = new CImg<unsigned char>("img.jpg");
	//cout << image<<endl;
	for(int x=0;x<image->height();x++){
		cout << (int)(*image)(x,0,0,0) << endl;
	}
	return 0;
}
