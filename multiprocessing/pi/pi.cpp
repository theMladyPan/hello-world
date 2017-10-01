#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif /* end of include guard: __IOSTREAM__ */

#ifndef __QUEUE__
#define __QUEUE__
#include <queue>
#endif /* end of include guard: __QUEUE__ */


#ifndef __MUTEX__
#define __MUTEX__
#include <mutex>
#endif /* end of include guard: __MUTEX__ */


#ifndef __UNISTD_H__
#define __UNISTD_H__
#include <unistd.h> //for sleep
#endif /* end of include guard: __UNISTD_H__ */

#ifndef __MATH_H__
#define __MATH_H__
#include <math.h>
#endif /* end of include guard: __MATH_H__ */

#ifndef __STRING__
#define __STRING__
#include <string>
#endif /* end of include guard: __STRING__ */

#ifndef __SSTREAM__
#define __SSTREAM__
#include <sstream>
#endif /* end of include guard: __SSTREAM__ */


//using Nilakantha series:
//π = 3 + 4/(2*3*4) - 4/(4*5*6) + 4/(6*7*8) - 4/(8*9*10) + 4/(10*11*12) - 4/(12*13*14)
//π = 3 + sum( 4*(-1^i) / ((i)*(i+1)*(i+2)) ) for i€<2,inf)

static uint64_t *it = new uint64_t(2);

double element(uint64_t i) { //function to calculate next iteration
  //  double min l: 4.94066e-324
  return ( 4*pow(-1,i)/ ((i)*(i+1)*(i+2)) );
}

template <typename T>
const std::string to_string(const T& data)
{
   std::ostringstream conv;
   conv << data;
   return conv.str().c_str();
}

void worker(int fd, const double precision, uint32_t first_it, uint8_t cpu_count){
  uint64_t local_it = first_it;
  FILE *stream;
  stream = fdopen (fd, "w");
  double e;
  do {
    e=element(local_it);
    fprintf (stream, to_string(e).c_str());
    local_it+=cpu_count;
    //std::cout << "e: "<<e<<", p: "<<precision<< '\n';
    } while(abs(e)>precision);
}


int main(int argc, const char ** argv) {
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
  std::vector<std::vector<int>> filedescriptors;
  int fd[2];

  pid_t pid;
  for(int i=0;i<cpu_count;i++){
    pipe(fd);
    filedescriptors.push_back(std::vector<int>());
    filedescriptors.back().push_back(fd[0]);
    filedescriptors.back().push_back(fd[1]);

    pid=fork();
    if(!pid){
      //ako child:
      close(fd[0]); //close input one side of pipe

      worker(fd[1], precision, *it+(uint64_t)i,cpu_count);
      return 0;
    }else{
      close(fd[1]); //close output side of pipe
    }
  }


  long double pi=3;
  char readbuffer[80];
  while(cpu_count){
    for(std::vector<std::vector<int>>::iterator it = filedescriptors.begin();it!=filedescriptors.end();it++){
      read() //tu som skončil
      while ((c = fgetc (stream)) != EOF){
        putchar (c);
      }
      std::cout << "Received: " <<readbuffer<< '\n';
      fclose(stream);
    }
  }
  usleep(1000000); //sleep for 1s

  return 0;
}
