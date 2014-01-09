#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 20
#define DEF_PAGER "/bin/more"

int
main(int argc, char *argv[])
{
    pid_t pid;
    int fd[2];
    FILE *fp;
    char line[MAXLINE];
    char *pager, *arg0;
    
    if ((fp = fopen("/home/spch2008/story", "r")) == NULL) {
        perror("fopen error!\n");
        exit(1);
    }

    if (pipe(fd) < 0) {
        perror("pipe error!\n");
        exit(1);
    }

    if ((pid = fork()) < 0) {
        perror("fork error!\n");
        exit(1);

    } else if (pid > 0) {
        close(fd[0]);

        while (fgets(line, MAXLINE, fp) != NULL) {
            write(fd[1], line, strlen(line));
        }
        close(fd[1]);      
   
        if (waitpid(pid, NULL, 0) < 0) {
            perror("waitpid error!\n");
        }
 
        exit(0);       

    } else {
        close(fd[1]);
        if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO) {
            perror("dup2 error!\n");
            exit(1);
        }

        if ((pager = getenv("PAGER")) == NULL) {
            pager = DEF_PAGER;
        }

        if ((arg0 = strrchr(pager, '/')) != NULL) {
            arg0++;

        } else {
            arg0 = pager;
        }

        if (execl(pager, arg0, (char*)0) < 0) {
            perror("execl error!\n");
            exit(1);
        }
    }

    return 0;
}
