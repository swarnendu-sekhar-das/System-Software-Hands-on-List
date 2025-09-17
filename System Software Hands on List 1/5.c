/*
============================================================================
Name : 5.c
Author : Swarnendu Sekhar Das
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
		
Date: 30th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fds[5];
    for (int i = 0; i < 5; i++) {
        char fname[25];
        snprintf(fname, sizeof(fname), "File No.- %d.txt", i+1);
        fds[i] = creat(fname, 0666);
        if (fds[i] == -1) {
            printf("File creation not successful !");
        } else {
            printf("File created: %s with fd %d\n", fname, fds[i]);
        }
    }

    while (1) {
        sleep(1);
    }
    return 0;
}


/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 5.c -o 5
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./5
File created: File No.- 1.txt with fd 3
File created: File No.- 2.txt with fd 4
File created: File No.- 3.txt with fd 5
File created: File No.- 4.txt with fd 6
File created: File No.- 5.txt with fd 7
*/