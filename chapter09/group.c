#include <stdlib.h>

int
main(int argc, char *argv[])
{
    pid_t pid;
    
    if ((pid = fork()) < 0) {
        perror("error\n");

    } else if (pid == 0) {
        while (1)
            sleep(5);

    } else {
        while (1)
            sleep(5);

    }

    return 0;
}
