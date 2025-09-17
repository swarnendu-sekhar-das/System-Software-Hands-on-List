/*
============================================================================
Name : 8.c
Author : Swarnendu Sekhar Das
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.

Date: 30th Aug, 2025.
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
int main() {
    char c;
    int fldes = open("file2.txt", O_RDONLY);
    while(read(fldes, &c, 1) != 0)
        write(1, &c, 1);

    close(fldes);

    return 0;    
}




/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 8.c -o 8
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./8
Name - Swarnendu Sekhar Das
Roll Number - MT2025125
Program - MTech in CSE
Institute - IIITB

*/