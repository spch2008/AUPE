#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>


static void sig_pipe(int);

int
main(int argc, char *argv[])
{
    int fd[2];
    char buf[20];    
    
    if (signal(SIGPIPE, sig_pipe) < 0) {
        perror("signal error!\n");
        exit(0);
    }

    if (pipe(fd) < 0) {
        perror("create pipe error !\n");
        exit(0);

    }
    
    close(fd[0]);
     
    strcpy(buf, "hello world");
    write(fd[1], buf, strlen(buf));
    
    //memset(buf, 0, sizeof(buf));
    //read(fd[0], buf, sizeof(buf));
    //printf("read data : %s\n", buf);


    return 0;
}

static void 
sig_pipe(int sig)
{
    printf("caught SIGPIPE\n");
}
