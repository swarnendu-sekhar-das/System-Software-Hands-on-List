/*
============================================================================
Name : 11.c
Author : Swarnendu Sekhar Das
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
              descriptors and check whether the file is updated properly or not.
                a. use dup
                b. use dup2
                c. use fcntl

Date: 31st Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    
    int fldes1 = open("test.txt", O_WRONLY);
	int fldes2 = dup(fldes1);
	
    char f1[] = "dup()\n";
	
    write(fldes2, &f1, sizeof(f1));
        int fldes3 = dup2(fldes1, 100);
        char f2[] = "dup2()\n";
	
    write(fldes3, &f2, sizeof(f2));
        int fldes4 = fcntl(fldes1, F_DUPFD, 0);
        char f3[] = "fcntl()\n";
	
    write(fldes4,&f3,sizeof(f3));
	
	return 0;
}
