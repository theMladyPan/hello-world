#include <iostream>
#include <thread>
#include <queue>
#include <mutex>

//using Nilakantha series:
//π = 3 + 4/(2*3*4) - 4/(4*5*6) + 4/(6*7*8) - 4/(8*9*10) + 4/(10*11*12) - 4/(12*13*14)
//π = 3 + sum( 4*(-1^i) / ((i)*(i+1)*(i+2)) ) for i€<2,inf)

static uint64_t it=2;

//function to calculate next iteration
double element(uint32_t i) {
  //  double min l: 4.94066e-324
  return ( 4*(-1^i) / ((i)*(i+1)*(i+2)) );
}

void worker(std::mutex *mux, std::queue<double> *reg){
  uint64_t local_it;

  mux->lock();
  local_it = it;
  it+=1;
  mux->unlock();

  /*
  vyrataj element a vloz do queue

  */
}

int main(int argc, const char ** argv) {
  std::queue<double> *reg = new std::queue<double>;
  std::mutex *mux = new std::mutex;

  std::vector<std::string> args;
	const std::string exe_name = argv[0];
	args.assign(argv+1, argv+argc);

  uint8_t cpu_count, dec_places;

	for(std::vector<std::string>::iterator it = args.begin();it!=args.end();it++){ //iterate throught all arguments
		if(*it=="-c" || *it == "--cpu_count"){
			cpu_count = atoi((*(++it)).c_str());
			}

		else if(*it=="-p" || *it == "--precision"){
			dec_places = atoi((*(++it)).c_str());
			}
		else{
			std::cerr<<"Invalid argument: "<<*it<<std::endl;
			return 1;
			}
		}

  std::vector<std::thread> *threads = new std::vector<std::thread>(cpu_count, std::thread(worker, mux, reg)); //vytvor "cpu_count" vlakien kt. budu vykonavat "worker" s arg. "reg"

  worker(mux, reg);

  std::cout << "it:" <<it<< '\n';

  return 0;
}
