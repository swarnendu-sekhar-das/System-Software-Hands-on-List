/*
============================================================================
Name : 12.c
Author : Swarnendu Sekhar Das
Description : Write a program to find out the opening mode of a file. Use fcntl.

Date: 31st Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("test_file.txt", O_RDWR);

    int fmode = fcntl(fd, F_GETFL);
    printf("%d\n", fmode);

    int am = fmode & O_ACCMODE;
    printf("%d\n", am);

    switch (am)
    {
    case O_RDWR:
        printf("File Mode: read and write mode");
        break;
    case O_WRONLY:
        printf("File Mode: write only mode");
        break;
    case O_RDONLY:
        printf("File Mode: read only mode");
        break;
    default:
        break;
    }
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 12.c -o 12
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./12
32770
2
File Mode: read and write mode
*/