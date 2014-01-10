#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 20

int
main(int argc, char *argv[])
{
    pid_t pid;
    char line[MAXLINE];
    int res;

    if ((pid = fork()) < 0) {
        exit(1);

    } else if (pid == 0) {
        for ( ; ; ) {
            res = read(STDIN_FILENO, line, MAXLINE);
            if (res == -1) {
                exit(1);
            }
         
            //if (strcmp(line, "son") == 0) {
            //    write(STDOUT_FILENO, "son end!\n", 9);
            //    break;
            //}
            
            write(STDOUT_FILENO, "child : ", 8);
            write(STDOUT_FILENO, line, strlen(line));
            memset(line, 0, MAXLINE);
            //sleep(1);
        }

    } else {
        for ( ; ; ) {
            res = read(STDIN_FILENO, line, MAXLINE);
            if (res == -1) {
                exit(1);
            }

            //if (strcmp(line, "father") == 0) {
             //   write(STDOUT_FILENO, "father end!\n", 12);
             //   break;
            //}
                
            write(STDOUT_FILENO, "fater : ", 8);
            write(STDOUT_FILENO, line, strlen(line)); 
            memset(line, 0, MAXLINE);
            //sleep(1);
        }
        waitpid(pid, NULL, 0);
    }
    exit(0);
}
