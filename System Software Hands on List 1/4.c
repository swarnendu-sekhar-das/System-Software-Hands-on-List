/*
============================================================================
Name : 4.c
Author : Swarnendu Sekhar Das
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
		
Date: 30th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    //Opened with O_RDWR
    int file = open("newfile.txt", O_RDWR);
    if(file == -1)
        printf("File open failed");
    else
        printf("File opened successfully (O_RDWR) with file descriptor: %d\n", file);
    
    //Opened with O_EXCL
    int file1 = open("newfile.txt", O_EXCL);
    if(file1 == -1)
        printf("File open failed");
    else
        printf("File opened successfully (O_EXCL) with file descriptor: %d\n", file1);
    
    return 0;
}

/*
sswarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 4.c -o 4
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./4
File opened successfully (O_RDWR) with file descriptor: 3
File opened successfully (O_EXCL) with file descriptor: 4
*/