#include <iostream>
#include <thread>

#include <queue>

#include <mutex>

#ifndef __UNISTD_H__
#define __UNISTD_H__
#include <unistd.h> //for sleep
#endif /* end of include guard: __UNISTD_H__ */

#ifndef __MATH_H__
#define __MATH_H__
#include <math.h>
#endif /* end of include guard: __MATH_H__ */


//using Nilakantha series:
//π = 3 + 4/(2*3*4) - 4/(4*5*6) + 4/(6*7*8) - 4/(8*9*10) + 4/(10*11*12) - 4/(12*13*14)
//π = 3 + sum( 4*(-1^i) / ((i)*(i+1)*(i+2)) ) for i€<2,inf)

static uint64_t it=2;

double element(uint32_t i) { //function to calculate next iteration
  //  double min l: 4.94066e-324
  return ( 4*pow(-1,i)/ ((i)*(i+1)*(i+2)) );
}

void worker(std::mutex *mux, std::queue<double> *reg, const double precision){
  uint64_t local_it;

  double e;
  do {
  mux->lock();
  local_it = it;
  it+=1;
  mux->unlock();

  e=element(local_it);
  mux->lock();
  reg->push(e);
  std::cout << "e: "<<e<<", p: "<<precision<< '\n';
  mux->unlock();

} while(abs(e)>precision);
}

int main(int argc, const char ** argv) {
  std::queue<double> *reg = new std::queue<double>;
  std::mutex *mux = new std::mutex;

  std::vector<std::string> args;
	const std::string exe_name = argv[0];
	args.assign(argv+1, argv+argc);

  uint8_t cpu_count=1, dec_places=2;

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
  double precision=1.0/pow(10,dec_places);
  std::cout << "Running calculations with " << (int)cpu_count <<" cores until "<< (double)precision <<" achieved." << '\n';

  std::vector<std::thread> threads;//(cpu_count, std::thread(worker, mux, reg)); //vytvor "cpu_count" vlakien kt. budu vykonavat "worker" s arg. "reg"
  for(uint8_t i=0;i<8;i++){
    threads.push_back(std::thread(worker, mux, reg, precision));
    threads.back().detach();
  }

  if(threads.back().joinable())threads.back().join();
  usleep(1000000); //sleep for 100ms
  std::cout <<"size: "<<threads.size() << '\n';
  std::cout << "iterations:" <<it<< '\n';
  return 0;
}
