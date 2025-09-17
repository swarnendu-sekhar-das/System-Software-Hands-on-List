/*
============================================================================
Name : 9.c
Author : Swarnendu Sekhar Das
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change

Date: 31st Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {

    struct stat sts;

    stat("file2.txt", &sts);
    printf("Inode: %lu\n", sts.st_ino);
    printf("No. of hard links: %lu\n", sts.st_nlink);
    printf("UID: %u\n", sts.st_uid);
    printf("GID: %u\n", sts.st_gid);
    printf("Size: %ld bytes\n", sts.st_size);
    printf("Block size: %ld\n", sts.st_blksize);
    printf("No. of blocks: %ld\n", sts.st_blocks);
    printf("Last access time: %s", ctime(&sts.st_atime));
    printf("Last modification time: %s", ctime(&sts.st_mtime));
    printf("Last status change time: %s", ctime(&sts.st_ctime));

    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 9.c -o 9
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./9
Inode: 3958239
No. of hard links: 3
UID: 1000
GID: 1000
Size: 93 bytes
Block size: 4096
No. of blocks: 8
Last access time: Sun Aug 31 14:41:25 2025
Last modification time: Sun Aug 31 11:11:29 2025
Last status change time: Sun Aug 31 11:39:54 2025

*/