#include <iostream>
#include <pthread.h>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;

#define NUM_THREADS 5

void * PrintHelloWorld(void *threadis){
    long tid;
    tid=(long)threadis;
    std::cout<<"Hello World Thread ID\n"<<tid<<std::endl;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, i;
    for(int i=0; i<NUM_THREADS;i++){
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
       std::cout<<"main(): creating thread, "<<i<< std::endl;
        rc= pthread_create(&threads[i], NULL, PrintHelloWorld,(void*)i);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        std::cout <<"tomo " <<time_span.count() <<" Segundos\n";
        if(rc){
            std::cout<<"Error:unable to create thread, "<<i<<std::endl;
            exit(-1);
        }
        
        //cout<<"Hello World\n";
    }
    pthread_exit(NULL);
}
