/*
============================================================================
Name : 14.c
Author : Swarnendu Sekhar Das
Description :   Write a program to find the type of a file.
                  a. Input should be taken from command line.
                  b. program should be able to identify any type of a file.

Date: 31st Aug, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    struct stat status;

    if (argc < 2) {
        fprintf(stderr, "Use: %s <filename>\n", argv[0]);
    }

    if (lstat(argv[1], &status) == -1) {
        printf("Error !\n");
    }

    printf("File type is:                \n");

    switch (status.st_mode & S_IFMT)
    {
    case S_IFBLK:
        printf("block device\n");
        break;
    case S_IFCHR:
        printf("character device\n");
        break;
    case S_IFDIR:
        printf("directory\n");
        break;
    case S_IFIFO:
        printf("FIFO/pipe\n");
        break;
    case S_IFLNK:
        printf("symlink\n");
        break;
    case S_IFREG:
        printf("regular file\n");
        break;
    case S_IFSOCK:
        printf("socket\n");
        break;
    default:
        printf("unknown\n");
        break;
    }
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 14.c -o 14
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./14
Use: ./14 <filename>
Error !
File type is:                
unknown

swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./14 file1.txt
File type is:                
regular file

swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./14 ssdpipe
File type is:                
FIFO/pipe

*/