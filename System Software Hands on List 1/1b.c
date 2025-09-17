/*
============================================================================
Name : 1b.c
Author : Swarnendu Sekhar Das
Description :   Create the following types of a files using (i) shell command (ii) system call
                    a. soft link (symlink system call)
                    b. hard link (link system call)
                    c. FIFO (mkfifo Library Function or mknod system call)
		
Date: 30th Aug, 2025.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main(){
    int i = link("file2.txt", "hrdlink1.txt");
    if(i == 0)
        printf("Output => hardlink creation successful: %d\n", i);
    else
        printf("Output => hardlink creation failed: %d\n", i);
        
    return 0;
}

 /*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 1b.c -o 1b
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./1b
Output => hardlink creation successful: 0
 */