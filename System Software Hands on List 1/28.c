/*
============================================================================
Name : 28.c
Author : Swarnendu Sekhar Das
Description : Write a program to get maximum and minimum real time priority.

Date: 2nd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int maxPriorityFIFO = sched_get_priority_max(SCHED_FIFO);
    int minPriorityFIFO = sched_get_priority_min(SCHED_FIFO);
    int maxPriorityRR = sched_get_priority_max(SCHED_RR);
    int minPriorityRR = sched_get_priority_min(SCHED_RR);

    printf("Max priority : %d\n", maxPriorityFIFO);
    printf("Min priority : %d\n", minPriorityFIFO);
    printf("Max priority : %d\n", maxPriorityRR);
    printf("Min priority : %d\n", minPriorityRR);
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 28.c -o 28
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./28
Max priority : 99
Min priority : 1
Max priority : 99
Min priority : 1
*/