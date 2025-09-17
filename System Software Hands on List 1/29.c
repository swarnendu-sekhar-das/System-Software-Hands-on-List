/*
============================================================================
Name : 29.c
Author : Swarnendu Sekhar Das
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
              SCHED_RR).

Date: 2nd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
  int pid = getpid();
  int current_policy;
  struct sched_param param;
  current_policy = sched_getscheduler(pid);
  
  switch(current_policy) {
     case SCHED_OTHER:
        printf("Current scheduling policy is SCHED_OTHER\n");
        break;
     case SCHED_FIFO:
        printf("Current scheduling policy is SCHED_FIFO\n");
        break;
     case SCHED_RR:
        printf("Current scheduling policy is SCHED_RR\n");
        break;
      default:
        printf("Scheduling policy not known\n");
        break;
    }
    printf("Modifying to new scheduling policy...\n");

    param.sched_priority = 1;
    sched_setscheduler(pid, SCHED_FIFO, &param);
    current_policy = sched_getscheduler(pid);
    
  switch(current_policy) {
     case SCHED_OTHER:
        printf("Current scheduling policy is SCHED_OTHER\n");
        break;
     case SCHED_FIFO:
        printf("Current scheduling policy is SCHED_FIFO\n");
        break;
     case SCHED_RR:
        printf("Current scheduling policy is SCHED_RR\n");
        break;
      default:
        printf("Scheduling policy not known\n");
        break;
    }
    
    printf("Switch to SCHED_RR...\n");

    param.sched_priority = 1;  
    sched_setscheduler(pid, SCHED_RR, &param);
    current_policy = sched_getscheduler(pid);

  switch(current_policy) {
     case SCHED_OTHER:
        printf("Current scheduling policy is SCHED_OTHER\n");
        break;
     case SCHED_FIFO:
        printf("Current scheduling policy is SCHED_FIFO\n");
        break;
     case SCHED_RR:
        printf("Current scheduling policy is SCHED_RR\n");
        break;
      default:
        printf("Scheduling policy not known\n");
        break;
    }

  return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 29.c -o 29
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ sudo ./29
Current scheduling policy is SCHED_OTHER
Modifying to new scheduling policy...
Current scheduling policy is SCHED_FIFO
Switch to SCHED_RR...
Current scheduling policy is SCHED_RR
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ 
*/