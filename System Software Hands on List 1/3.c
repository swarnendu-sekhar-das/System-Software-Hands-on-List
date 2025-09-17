/*
============================================================================
Name : 3.c
Author : Swarnendu Sekhar Das
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
		
Date: 30th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fldes = creat("newfile.txt", 0766);
    if(fldes == -1)
        printf("File creation failed");
    else
        printf("File created successfully with file descriptor: %d\n", fldes);
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 3.c -o 3
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./3
File created successfully with file descriptor: 3
*/