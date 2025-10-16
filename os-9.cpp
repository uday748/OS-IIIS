#include <iostream>
#include <pthread.h>
#include <unistd.h>  

using namespace std;

void* threadFunc1(void* arg) {
    for(int i = 0; i < 5; i++) {
        cout << "Thread 1 is running: " << i+1 << endl;
        sleep(1);  
    }
    return NULL;
}

void* threadFunc2(void* arg) {
    for(int i = 0; i < 5; i++) {
        cout << "Thread 2 is running: " << i+1 << endl;
        sleep(1); 
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;  


    pthread_create(&t1, NULL, threadFunc1, NULL);
    pthread_create(&t2, NULL, threadFunc2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    cout << "Both threads have finished execution." << endl;

    return 0;
}

