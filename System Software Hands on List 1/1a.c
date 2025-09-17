/*
============================================================================
Name : 1a.c
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
    int i = symlink("file1.txt", "sftlink1.txt");
    if(i == 0)
        printf("Output => softlink creation successful: %d\n", i);
    else
        printf("Output => softlink creation failed: %d\n", i);

    return 0;
}

 /*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 1a.c -o 1a
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./1a
Output => softlink creation successful: 0
 */