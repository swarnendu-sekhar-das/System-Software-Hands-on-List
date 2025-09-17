/*
============================================================================
Name : 25.c
Author : Swarnendu Sekhar Das
Description : Write a program to create three child processes. The parent should wait for a particular child (use
              waitpid system call).

Date: 2nd Sep, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
   int i,j,k;
   
   if(!(i = fork())){
      printf("Child 1 PID: %d running...\n", getpid());
      sleep(2);
   }
   else if(!(j = fork())){
      printf("Child 2 PID: %d running...\n", getpid());
      sleep(2);
   }
   else if(!(k = fork())){
      printf("Child 3 PID: %d running...\n", getpid());
      sleep(2);
   }
   
   printf("Parent PID: %d waiting for Child 2 (PID: %d)...\n", getpid(), j);
   waitpid(j,NULL,0);
   printf("Child Process 2 finished.\n");

   return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 25.c -o 25
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./25
Child 1 PID: 10928 running...
Parent PID: 10927 waiting for Child 2 (PID: 10929)...
Child 2 PID: 10929 running...
Child 3 PID: 10930 running...
Parent PID: 10928 waiting for Child 2 (PID: 32767)...
Child Process 2 finished.
Parent PID: 10929 waiting for Child 2 (PID: 0)...
Child Process 2 finished.
Parent PID: 10930 waiting for Child 2 (PID: 10929)...
Child Process 2 finished.
Child Process 2 finished.
*/