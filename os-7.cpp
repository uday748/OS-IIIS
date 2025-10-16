#include <iostream>
#include <sys/mman.h>   
#include <sys/stat.h>   
#include <fcntl.h>      
#include <unistd.h>
#include <cstring>      
using namespace std;

int main() {
    const char *shm_name = "/my_shm";  
    const int SIZE = 1024;            
    int shm_fd;
    void *ptr;

    
    shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    if(shm_fd == -1) {
        cerr << "Shared memory creation failed!\n";
        return 1;
    }

    
    ftruncate(shm_fd, SIZE);


    ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if(ptr == MAP_FAILED) {
        cerr << "Memory mapping failed!\n";
        return 1;
    }

    pid_t pid = fork(); 

    if(pid < 0) {
        cerr << "Fork failed!\n";
        return 1;
    }

    if(pid == 0) {
        sleep(1); 
        cout << "Child reads from shared memory: " << (char*)ptr << endl;
    } else {
    
        const char *message = "Hello from Parent!";
        strcpy((char*)ptr, message);
        cout << "Parent wrote to shared memory: " << message << endl;

        wait(NULL);

        shm_unlink(shm_name);
    }

    return 0;
}

