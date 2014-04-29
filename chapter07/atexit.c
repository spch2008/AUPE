#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void clean1()
{
    printf("clean1\n");
}

static void clean2()
{
    printf("clean2\n");
}

extern char **environ;

int main(int argc, char *argv[])
{
    if (atexit(clean1) != 0)
        printf("atexit error\n");

    if (atexit(clean2) != 0)
        printf("atexit error\n");

//    for (int i = 0; environ[i]; i++)
//        printf("%s\n", environ[i]);
    char *mail = getenv("MAIL");
    printf("mail = %s\n", mail);
    _exit(0);
    return 0;
}
