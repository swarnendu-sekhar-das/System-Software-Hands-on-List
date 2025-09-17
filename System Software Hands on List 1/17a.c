/*
============================================================================
Name : 17a.c
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
    int fldes = open("ticket.txt", O_CREAT | O_WRONLY, 0644);
    if (fldes == -1) {
        printf("File creation failed or file doesn't exist !");
        return 1;
    }
    int ticketnum = 10;
    write(fldes, &ticketnum, sizeof(int));
    close(fldes);
    printf("Ticket file created with %d.\n", ticketnum);
    return 0;
}
/*

*/