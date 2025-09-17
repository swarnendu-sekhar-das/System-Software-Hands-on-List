/*
============================================================================
Name : 27.c
Author : Swarnendu Sekhar Das
Description : Write a program to execute ls -Rl by the following system calls
                a. execl
                b. execlp
                c. execle
                d. execv
                e. execvp

Date: 2nd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
int main(int argc,char *env[])
{
    char *path = "/bin/ls";
    execl(path, path, "-Rl", NULL); //a
    char *path2 = "ls";
    execlp(path2, path2, "-Rl", NULL); //b
    execle(path, path, "-Rl" ,"27c/",NULL, env); //c
    char *argv[] = {path,"-Rl",NULL};
    execv(path, argv); //d
    char *buf[] = {path2, "-Rl", NULL};
    execvp(path2, buf); //e     
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 27.c -o 27
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./27
.:
total 736
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16136 Aug 31 15:22  10
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1336 Aug 31 17:34  10.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16176 Aug 31 16:04  11
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   955 Aug 31 17:33  11.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16040 Aug 31 16:08  12
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1083 Aug 31 17:33  12.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16056 Aug 31 16:19  13
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1233 Aug 31 17:33  13.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16136 Aug 31 16:31  14
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1955 Aug 31 17:33  14.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16024 Aug 31 16:36  15
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  4452 Aug 31 17:33  15.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16176 Aug 31 16:49  16a
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1001 Aug 31 17:32  16a.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16176 Aug 31 16:53  16b
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1001 Aug 31 17:32  16b.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16136 Aug 31 23:57  17a
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   996 Aug 31 22:15  17a.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16264 Aug 31 23:57  17b
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  2480 Aug 31 23:58  17b.c
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  2479 Sep  3 23:13  18
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16032 Sep  3 02:41  19
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   911 Sep  3 02:42  19.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16000 Aug 31 11:25  1a
-rwxr-xr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das  1038 Aug 31 17:35  1a.c
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   602 Aug 31 12:55  1a.sh
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16000 Aug 31 11:28  1b
-rwxr-xr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das  1043 Aug 31 17:35  1b.c
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   593 Aug 31 12:55  1b.sh
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16000 Aug 31 11:31  1c
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1208 Aug 31 17:35  1c.c
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   577 Aug 31 12:55  1c.sh
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 15960 Aug 31 22:01  2
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16096 Sep  3 02:24  20
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1015 Sep  3 02:25  20.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16088 Sep  3 01:58  21
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   910 Sep  3 01:59  21.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16080 Sep  3 02:17  22
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   933 Sep  3 02:17  22.c
-rwxr--r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das    45 Sep  3 02:17  22.txt
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16168 Sep  3 02:32  23
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1034 Sep  3 02:33  23.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16168 Sep  3 23:19  24
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1054 Sep  3 23:21  24.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16040 Sep  3 02:36  25
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   618 Sep  3 02:36  25.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16008 Sep  3 23:55  26
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   647 Sep  4 00:40  26.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16184 Sep  4 00:43  27
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   421 Sep  4 00:43  27.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16080 Sep  3 01:52  28
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1071 Sep  3 01:52  28.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16160 Sep  3 23:54  29
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  2596 Sep  3 23:54  29.c
-rwxr-xr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das  1607 Aug 31 22:02  2.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16000 Aug 31 12:36  3
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16296 Sep  4 00:19  30
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1022 Sep  4 00:33  30.c
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   849 Aug 31 17:34  3.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16000 Aug 31 12:54  4
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1164 Aug 31 17:34  4.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16072 Aug 31 13:07  5
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1265 Aug 31 17:34  5.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16048 Aug 31 14:17  6
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   780 Aug 31 17:34  6.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16136 Aug 31 14:28  7
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   841 Aug 31 17:34  7.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16136 Aug 31 14:41  8
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das   877 Aug 31 17:34  8.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16088 Aug 31 14:51  9
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das  1548 Aug 31 17:34  9.c
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das 16136 Aug 31 16:45  a.out
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das    39 Sep  3 23:28  Exfile.txt
-rw-r--r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das    93 Aug 31 14:28  file1_cpy.txt
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das    93 Aug 31 11:10  file1.txt
-rw-rw-r-- 3 swarnendu-sekhar-das swarnendu-sekhar-das    93 Aug 31 11:11  file2.txt
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das     0 Aug 31 13:07 'File No.- 1.txt'
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das     0 Aug 31 13:07 'File No.- 2.txt'
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das     0 Aug 31 13:07 'File No.- 3.txt'
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das     0 Aug 31 13:07 'File No.- 4.txt'
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das     0 Aug 31 13:07 'File No.- 5.txt'
-rw-rw-r-- 3 swarnendu-sekhar-das swarnendu-sekhar-das    93 Aug 31 11:11  hrdlink1.txt
-rw-rw-r-- 3 swarnendu-sekhar-das swarnendu-sekhar-das    93 Aug 31 11:11  hrdlink.txt
-rwxrw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das     0 Aug 31 12:36  newfile.txt
lrwxrwxrwx 1 swarnendu-sekhar-das swarnendu-sekhar-das     9 Aug 31 11:25  sftlink1.txt -> file1.txt
lrwxrwxrwx 1 swarnendu-sekhar-das swarnendu-sekhar-das     9 Aug 31 11:12  sftlink.txt -> file1.txt
prw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das     0 Aug 31 11:31  ssd_pipe
prw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das     0 Aug 31 11:16  ssdpipe
-rwxrwxr-x 1 swarnendu-sekhar-das swarnendu-sekhar-das    30 Aug 31 15:22  test_file.txt
-rw-rw-r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das    24 Aug 31 16:04  test.txt
-rw-r--r-- 1 swarnendu-sekhar-das swarnendu-sekhar-das     4 Aug 31 23:58  ticket.txt
*/