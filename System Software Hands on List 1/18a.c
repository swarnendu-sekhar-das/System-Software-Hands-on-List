/*
============================================================================
Name : 18a.c
Author : Swarnendu Sekhar Das
Description : Write a program to perform Record locking.
                a. Implement write lock
                b. Implement read lock
            Create three records in a file. Whenever you access a particular record, first lock it then modify/access
            to avoid race condition.

Date: 31st Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

struct record
{
    int record_id;
    int value;
};

int main()
{
    int fd = open("locktest.txt", O_RDWR | O_CREAT, 0777);
    struct flock wrlock = {F_WRLCK, SEEK_SET, 0, sizeof(struct record), getpid()};
    int record_id;
    printf("Enter record ID:");
    scanf("%d", &record_id);
    if(record_id > 3)printf("Record does not exist !");
    else{
    wrlock.l_start = (record_id-1)*sizeof(struct record);
    wrlock.l_len = sizeof(struct record);
    fcntl(fd, F_SETLKW, &wrlock);
    printf("Record %d is locked !\nEnter key to unlock: \n", record_id);
    getchar();
    getchar();
    wrlock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &wrlock);
    printf("Record %d is unlocked !\n",record_id);
    }
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 18.c -o 18
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 18a.c -o 18a
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 18b.c -o 18b
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./18
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./18a
Enter record ID:1       
Record 1 is locked !
Enter key to unlock: 

Record 1 is unlocked !
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./18b
Enter record ID:3   
Record 3 ID locked ! 
Enter key to unlock:

Record 3 is unlocked !
*/