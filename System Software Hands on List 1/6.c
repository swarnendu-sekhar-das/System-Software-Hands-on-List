/*
============================================================================
Name : 6.c
Author : Swarnendu Sekhar Das
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
		
Date: 30th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[1024];
    int n;
    n = read(0, buffer, 1024);       // read from STDIN (fd = 0)
    write(1, buffer, n);            // write to STDOUT (fd = 1)

    return 0;
}



/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 6.c -o 6
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./6
Swarnendu 
Swarnendu 

*/