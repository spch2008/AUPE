#include <signal.h>
#include <stdio.h>

static void sig_usr(int);


int
main(int argc, char *argv[])
{
    if (signal(SIGINT, sig_usr) == SIG_ERR)
        perror("cannot catch SIGINT");

    for ( ; ; )
        pause();
}

static void
sig_usr(int signo)
{
    if (signo == SIGINT)
        printf("received sigint\n");
    else
        printf("received signal %d\n", signo);
}
