/*
============================================================================
Name : 10.c
Author : Swarnendu Sekhar Das
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
              bytes (use lseek) and write again 10 bytes.
                a. check the return value of lseek
                b. open the file with od and check the empty spaces in between the data.

Date: 31st Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fldes = open("test_file.txt", O_RDWR | O_CREAT, 0777);
        
	char data[10] = "SSD__IIITB";
	write(fldes, data, 10);
	int offset = lseek(fldes, 10, SEEK_CUR);
	printf("%d\n", offset);
	write(fldes, data, 10);
	offset = lseek(fldes, 0, SEEK_CUR);
	printf("%d\n", offset);

	return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 10.c -o 10
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./10
20
30
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ od -c test_file.txt
0000000   S   S   D   _   _   I   I   I   T   B  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   S   S   D   _   _   I   I   I   T   B
0000036
*/