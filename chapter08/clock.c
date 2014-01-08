#include <sys/times.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
    struct tms  tmsstart;
    clock_t start;

    start = times(&tmsstart);
    printf("%f\n", start);
}
