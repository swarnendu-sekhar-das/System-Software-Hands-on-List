/*
============================================================================
Name : 24.c
Author : Swarnendu Sekhar Das
Description : Write a program to create an orphan process.

Date: 2nd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        printf("Child PID %d, Parent PID %d\n", getpid(), getppid());
        sleep(5); 
        printf("Child's new parent PID: %d (init)\n", getppid());
    } 
    else if (pid > 0) {
        printf("Parent PID %d exits\n", getpid());
    } 
    else {
        printf("Fork not successful\n");
    }
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 24.c -o 24
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./24
Parent PID 5467 exits
Child PID 5468, Parent PID 5467
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ Child's new parent PID: 2435 (init)
*/