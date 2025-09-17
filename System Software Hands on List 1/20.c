/*
============================================================================
Name : 20.c
Author : Swarnendu Sekhar Das
Description : Find out the priority of your running program. Modify the priority with nice command.

Date: 2nd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{   
    int priority = getpriority(PRIO_PROCESS, 0);
    printf("Current priority is:%d\n",priority);

    int new_priority;
    new_priority = nice(7);
    setpriority(PRIO_PROCESS, 0, new_priority);

    priority = getpriority(PRIO_PROCESS, 0);
    printf("Modified new priority of the process is: %d\n", priority);
    
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 20.c -o 20
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./20
Current priority is:0
Modified new priority of the process is: 7
*/