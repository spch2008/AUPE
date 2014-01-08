#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

void
pr_exit(int status)
{
    if (WIFEXITED(status)) {
        printf("normal termination, exit status = %d\n", status);
    
    } else if (WIFSIGNALED(status)) {
        printf("abnormal termination, signal number = %d\n", status);
  
    } else {
        printf("termination, exit code = %s\n", status);
  
    }
}


int
main(int argc, char *argv[])
{
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        perror("fork error!\n");

    } else if (pid == 0) {
        exit(1);

    }

    if (wait(&status) != pid) {
        perror("wait error!\n");
 
    }
    pr_exit(status);

    if ((pid = fork()) < 0) {
        perror("fork error!\n");

    } else if (pid == 0) {
        abort();

    }

    if (wait(&status) != pid) {
        perror("wait error!\n");

    } 
    pr_exit(status);

    if ((pid = fork()) < 0) {
        perror("fork error!\n");

    } else if (pid == 0) {
        status /= 0;

    }

    if (wait(&status) != pid) {
        perror("wait error!\n");

    }
    pr_exit(status);
}
