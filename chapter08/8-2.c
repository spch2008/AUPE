#include <stdlib.h>
#include <unistd.h>

static void f1(void), f2(void);

int
main(int argc, char *argv[])
{
    f1();
    f2();
    _exit(0);
}

static void
f1()
{
    pid_t pid;
    
    if ((pid = vfork()) < 0)
        perror("vfork error");
}

static void
f2()
{
    char buf[1000];
    int i;
    
    for (i = 0; i < sizeof(buf); i++)
        buf[i] = 0;
}