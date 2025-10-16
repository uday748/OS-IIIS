#include <iostream>
#include <pthread.h>  
#include <unistd.h>   

using namespace std;


void* myThreadFunction(void* arg) {
    int num = *((int*)arg); 
    cout << "Hello from thread! Argument = " << num << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Thread is running: " << i+1 << endl;
        sleep(1); 
    }
    return NULL;
}

int main() {
    pthread_t thread;
    int arg = 10;

    
    if(pthread_create(&thread, NULL, myThreadFunction, &arg) != 0) {
        cerr << "Failed to create thread" << endl;
        return 1;
    }

    pthread_join(thread, NULL);

    cout << "Thread finished execution." << endl;

    return 0;
}

