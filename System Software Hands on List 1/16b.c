/*
============================================================================
Name : 16b.c
Author : Swarnendu Sekhar Das
Description : Write a program to perform mandatory locking.
                a. Implement write lock
                b. Implement read lock

Date: 31st Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fldes = open("test.txt", O_RDONLY);

    struct flock f = {F_RDLCK,0,0,0,0};
    fcntl(fldes, F_SETLKW, &f);

    printf("File Locked.\nTo unlock file press 1\n");
    char c = getchar();
    if(c)
        f.l_type = F_UNLCK; 
        fcntl(fldes, F_SETLKW, &f);
        printf("File Unlocked");

    return 0; 
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 16b.c -o 16b
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./16b
File Locked.
To unlock file press 1
1
File Unlocked
*/