#include <stdio.h>
#include <unistd.h>   
#include <sys/types.h> 

int main() {
    pid_t pid;

    printf("Before fork\n");

    pid = fork();  

    if (pid < 0) {
    
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        
        printf("This is the child process.\n");
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
    }
    else {

        printf("This is the parent process.\n");
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
    }

    printf("This line is executed by both parent and child.\n");
    return 0;
}

