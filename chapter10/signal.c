#include <signal.h>
#include <stdio.h>

static void sig_usr(int);


int
main(int argc, char *argv[])
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
        perror("cannot catch SIGUSER1");

    for ( ; ; )
        pause();
}

static void
sig_usr(int signo)
{
    if (signo == SIGUSR1)
        printf("received siguser1\n");
    else
        printf("received signal %d\n", signo);
}
