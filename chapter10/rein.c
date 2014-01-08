#include <signal.h>
#include <pwd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void
my_alarm(int signo)
{
    struct passwd *rootptr;
    
    printf("in signal handler\n");
    if ((rootptr = getpwnam("root")) == NULL)
        perror("getpwnam(root) error");
    printf("in in \n");
    alarm(1);
}

int
main()
{
    struct passwd *ptr;
    
    signal(SIGALRM, my_alarm);
    alarm(1);
    for ( ; ; ) {
        if ((ptr = getpwnam("nobody")) == NULL)
            perror("getpwname error\n");
        if (strcmp(ptr->pw_name, "nobody") != 0)
            printf("return value corrupted!, pw_name = %s\n", ptr->pw_name);

    }
    return 0;
}
