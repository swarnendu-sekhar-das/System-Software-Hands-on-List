/*
============================================================================
Name : 26.c
Author : Swarnendu Sekhar Das
Description : Write a program to execute an executable program.
                a. use some executable program
                b. pass some input to an executable program. (for example execute an executable of $./a.out name)

Date: 2nd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main()
{  
    char* arg[] = {"cat", "Exfile.txt", NULL};
    execv("/bin/cat", arg);
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 26.c -o 26
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./26
Hi this is Swarnendu 

This is my file
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$
*/