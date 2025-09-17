/*
============================================================================
Name : 21.c
Author : Swarnendu Sekhar Das
Description : Write a program, call fork and print the parent and child process id.

Date: 2nd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        printf("Child Process ID: %d\n", getpid());
    } 
    else if (pid > 0) {
        printf("Parent Process ID: %d, Child Process ID: %d\n", getpid(), pid);
    } 
    else {
        printf("Fork not successful\n");
    }
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 21.c -o 21
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./21
Parent Process ID: 11369, Child Process ID: 11370
Child Process ID: 11370

*/