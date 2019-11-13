#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

void * PrintHelloWorld(void *threadis){
    long tid;
    tid=(long)threadis;
    cout<<"Hello World Thread ID"<<tid<<endl;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, i;
    for(int i=0; i<NUM_THREADS;i++){
        cout<<"main(): creating thread, "<<i<< endl;
        rc= pthread_create(&threads[i], NULL, PrintHelloWorld,(void*)i);

        if(rc){
            cout<<"Error:unable to create thread, "<<i<<endl;
            exit(-1);
        }
        
        //cout<<"Hello World\n";
    }
    pthread_exit(NULL);
}