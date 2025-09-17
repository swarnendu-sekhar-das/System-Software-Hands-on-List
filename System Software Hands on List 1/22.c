/*
============================================================================
Name : 22.c
Author : Swarnendu Sekhar Das
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
              parent processes. Check output of the file.

Date: 2nd Sep, 2025.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>   
#include<wait.h>        

int main(void){
    int fldes;
    fldes = open ("22.txt", O_WRONLY | O_CREAT , 0744);
    if(!fork())
        write(fldes, "Child process wrote \n", 22);
    else
        write(fldes, "Parent process wrote \n", 23);
        
wait(0);

}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 22.c -o 22
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./22

Parent process wrote 
Child process wrote 

*/