#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(int argc, char ** argv){
	vector<string> args;
	string exe_name = argv[0];
	args.assign(argv+1, argv+argc);
	char znak = '#';
	bool verbose=0;
	unsigned int width = 10, height = 10;

	for(vector<string>::iterator it = args.begin();it!=args.end();it++){
		if(*it=="-w"){
			width = atoi((*(++it)).c_str());
			}
		else if(*it=="-h"){
			height = atoi((*(++it)).c_str());
			}
		else if(*it=="-c"){
			znak = (*(++it)).c_str()[0];
			}
		else if(*it=="-v"){
			verbose=1;
			}
		else{
			cerr<<"Invalid argument: "<<*it<<endl;
			return 1;
			}
		}

	if(verbose){
		cout<<"W: "<<width<<", "<<znak<<", H: "<<height<<endl;
	}


	return 0;
}
