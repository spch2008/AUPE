#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
    sigset_t sigset;
    int      errno_save;

    errno_save = errno;
    if (sigprocmask(0, NULL, &sigset))
        perror("sigprocmask error!\n");

    if (sigismember(&sigset, SIGINT))
        printf("sigint\n");
    if (sigismember(&sigset, SIGQUIT))
        printf("sigquit\n");
    

    return 0;
}
