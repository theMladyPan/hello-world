#include <iostream>
#include <thread>
#include <queue>

//using Nilakantha series:
//π = 3 + 4/(2*3*4) - 4/(4*5*6) + 4/(6*7*8) - 4/(8*9*10) + 4/(10*11*12) - 4/(12*13*14)
//π = 3 + sum( 4*(-1^i) / ((i)*(i+1)*(i+2)) ) for i€<2,inf)

//function to calculate next iteration
double element(uint32_t i) {
  


}

uint8 int main(int argc, char const ** argv) {
  std::queue<double> register;
  std::list<std::thread> threads;

  std::vector<string> args;
	const std::string exe_name = argv[0];
	args.assign(argv+1, argv+argc);

  uint8_t cpu_count, dec_places;

	for(vector<string>::iterator it = args.begin();it!=args.end();it++){ //iterate throught all arguments
		if(*it=="-c" || *it == "--cpu_count"){
			cpu_count = atoi((*(++it)).c_str());
			}

		else if(*it=="-p" || *it == "--precision"){
			*dec_places = atoi((*(++it)).c_str());
			}
		else{
			cerr<<"Invalid argument: "<<*it<<endl;
			return 1;
			}
		}

  return 0;
}
