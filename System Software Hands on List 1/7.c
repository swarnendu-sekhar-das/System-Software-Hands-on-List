/*
============================================================================
Name : 7.c
Author : Swarnendu Sekhar Das
Description : Write a program to copy file1 into file2 ($cp file1 file2).

Date: 30th Aug, 2025.
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
int main() {
    char buffer[1024];
    int rd = open("file1.txt", O_RDONLY);
    int crt = creat("file1_cpy.txt", 0644);
    int size = read(rd, buffer, 1024);
    write(crt, buffer, size);

    return 0;
}




/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 7.c -o 7
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./7
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ls
file1.txt  file1_cpy.txt 
*/