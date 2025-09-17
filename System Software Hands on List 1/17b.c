/*
============================================================================
Name : 17b.c
Author : Swarnendu Sekhar Das
Description : Write a program to simulate online ticket reservation. Implement write lock.
              Write a program to open a file, store a ticket number and exit. Write a separate program, to
              open the file, implement write lock, read the ticket number, increment the number and print
              the new ticket number then close the file.

Date: 31st Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fldes = open("ticket.txt", O_RDWR);
    if (fldes == -1) {
        printf("File creation failed or file doesn't exist !");
        return 1;
    }

    struct flock l;
    l.l_type = F_WRLCK;
    l.l_whence = SEEK_SET;
    l.l_start = 0;
    l.l_len = 0;

    if (fcntl(fldes, F_SETLKW, &l) == -1) {
        printf("Lock not allowed, already locked !");
        close(fldes);
        return 1;
    }

    int ticket;
    read(fldes, &ticket, sizeof(int));
    ticket++;
    lseek(fldes, 0, SEEK_SET);
    write(fldes, &ticket, sizeof(int));

    printf("New Ticket Number: %d\n", ticket);

    l.l_type = F_UNLCK;
    fcntl(fldes, F_SETLK, &l);
    close(fldes);
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 17a.c -o 17a
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 17b.c -o 17b
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./17a
Ticket file created with 10.
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./17b &
[2] 8326
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ New Ticket Number: 11
./17b &
[3] 8329
[2]   Done                    ./17b
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ New Ticket Number: 12
./17b &
[4] 8331
[3]   Done                    ./17b
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ New Ticket Number: 13
./17b &
[5] 8336
[4]   Done                    ./17b
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ New Ticket Number: 14
./17b &
[6] 8340
[5]   Done                    ./17b
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ New Ticket Number: 15
*/