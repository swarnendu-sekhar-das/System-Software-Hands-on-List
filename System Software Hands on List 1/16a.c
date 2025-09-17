/*
============================================================================
Name : 16a.c
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
    int fldes = open("test.txt", O_WRONLY);

    struct flock f = {F_WRLCK,0,0,0,0};
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
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 16a.c -o 16a
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./16a
File Locked.
To unlock file press 1
1
File Unlocked
*/