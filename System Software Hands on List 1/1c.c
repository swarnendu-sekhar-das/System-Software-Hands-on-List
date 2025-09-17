/*
============================================================================
Name : 1c.c
Author : Swarnendu Sekhar Das
Description :   Create the following types of a files using (i) shell command (ii) system call
                    a. soft link (symlink system call)
                    b. hard link (link system call)
                    c. FIFO (mkfifo Library Function or mknod system call)
		
Date: 30th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int i = mkfifo("ssd_pipe", 0666);
    if(i == 0)
        printf("Output => FIFO creation successful: %d\n", i);
    else
        printf("Output => FIFO creation failed: %d\n", i);
        
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 1c.c -o 1c
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./1c
Output => FIFO creation successful: 0
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ls
file2.txt     hrdlink.txt  sftlink1.txt  ssd_pipe
file1.txt  hrdlink1.txt  link1.txt    sftlink.txt   ssdpipe
*/