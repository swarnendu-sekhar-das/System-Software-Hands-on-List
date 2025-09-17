/*
============================================================================
Name : 30.c
Author : Swarnendu Sekhar Das
Description : Write a program to run a script at a specific time using a Daemon process.

Date: 2nd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>

int main() {
    
    int PID;
    PID = fork();
    if (PID < 0) {
        exit(EXIT_FAILURE);
    }
    if (PID > 0) {
        exit(EXIT_SUCCESS);
    }
    umask(0);
    if (setsid() < 0) {
        exit(EXIT_FAILURE);
    }
    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    
    openlog("daemon-log", LOG_PID, LOG_DAEMON);
    while (1) {
        syslog(LOG_NOTICE, "Daemon process is executing !");
        sleep(5);
    }
    closelog();

    return EXIT_SUCCESS;
}