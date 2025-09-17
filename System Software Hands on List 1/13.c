/*
============================================================================
Name : 13.c
Author : Swarnendu Sekhar Das
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
              verify whether the data is available within 10 seconds or not (check in $man 2 select).

Date: 31st Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <time.h>

int main()
{
    struct timeval tm;
    fd_set f;
    FD_SET(0, &f);
    tm.tv_sec = 10;
    tm.tv_usec = 0;
    int i = select(1, &f, NULL, NULL, &tm);

    if (i == -1)
    {
        printf("Output not possible");
    }
    else if (i == 0)
    {
        printf("Time Out !");
    }
    else
    {
        printf("Input data entered");
    }

    return 0;
}

/*
Output #1:

swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 13.c -o 13
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./13
SSD
Input data entered

Output #2:

swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./13
Time Out !
*/