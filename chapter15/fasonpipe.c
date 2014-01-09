#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLINE 20

int
main(int argc, char *argv[])
{
    int fd[2], res;
    pid_t pid;
    char line[MAXLINE];

    if (pipe(fd) < 0) {
        perror("pipe error!\n");
        exit(1);
    }

    if ((pid = fork()) < 0) {
        perror("fork error\n");
        exit(1);

    } else if (pid > 0) {
        close(fd[0]);
        write(fd[1], "hello world", 11);

    } else {
        close(fd[1]);
        res = read(fd[0], line, MAXLINE);
        //write(STDOUT_FILENO, line, res);
        printf("%s\n", line);
    }

    return 0;
}
