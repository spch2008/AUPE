#include <stdio.h>
#include <stdlib.h>

static void put(char *);

int
main(int argc, char *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("fork error!\n");
        exit(1);

    } else if (pid == 0) {
        put("output from child!\n");

    } else {
        put("output from father!\n");
    
    }
    exit(0);
}

static void
put(char *str)
{
    char *ptr;
    int c;

    setbuf(stdout, NULL);
    for (ptr = str; (c = *ptr++) != '\0'; )
        putc(c, stdout);
}
