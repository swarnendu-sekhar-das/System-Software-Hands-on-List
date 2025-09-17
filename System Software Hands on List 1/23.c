/*
============================================================================
Name : 23.c
Author : Swarnendu Sekhar Das
Description : Write a program to create a Zombie state of the running program.

Date: 2nd Sep, 2025.
============================================================================
*/

#include <stdlib.h> 
#include<stdio.h>
#include <sys/types.h> 
#include <unistd.h>

int main() 
{ 
	int childPID = fork(); 

	if (childPID > 0) {
	   printf("Sleep Returned: %d\n", sleep(15));
	   printf("Inside Parent PID = %d\n", getpid());
       printf("Child PID = %d\n", childPID);
	}
	 
	else{	
	   printf("Inside Child PID = %d\n", getpid());
           printf("Parent PID = %d\n", getppid());
	   exit(0); 
    }

	return 0; 
} 

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 23.c -o 23
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./23
Inside Child PID = 13066
Parent PID = 13065
Sleep Returned: 0
Inside Parent PID = 13065
Child PID = 13066
*/