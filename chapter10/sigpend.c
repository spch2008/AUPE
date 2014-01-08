#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

static void sig_quit(int);

int
main(int argc, char *argv[])
{
    sigset_t newmask, oldmask, pendmask;

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        perror("SIG_BLOCK ERROR\n");

    sleep(10);

    if (sigpending(&pendmask) < 0)
        perror("SIG_PEND ERROR\n");
    if (sigismember(&pendmask, SIGQUIT))
        printf("\nSIGQUIT pending\n");

    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        perror("SIG_SETMASK ERROR\n");
    printf("SIGQUIT unblocked\n");
    
    sleep(5);
    exit(0);
    
}

static void
sig_quit(int signo)
{
   printf("caught SIGQUIT\n");
   if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
       perror("cannot reset SIGQUIT\n");
}
