/*
============================================================================
Name : 19.c
Author : Swarnendu Sekhar Das
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.

Date: 2nd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc(void)
{
  unsigned long long dst;
  __asm__ __volatile__ ("rdtsc" : "=A"(dst));
  
}
void main()
{
    int start = rdtsc();
    printf("The process PID is: %d\n", getpid());
    int end = rdtsc();
    printf("Time taken is : %d ns\n", (end - start));
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 19.c -o 19
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./19
The process PID is: 13281
Time taken is : 255524 ns
*/