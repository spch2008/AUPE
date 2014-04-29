#include <sys/times.h>
#include <stdio.h>
#include <unistd.h>

void f1()
{
    printf("hello world!\n");
}

int main()
{
    struct tms begin;
    struct tms end;

    clock_t s;
    clock_t e;

    s = times(&begin);
   
    int i; 
    for (i = 0; i < 10; i++)
        f1();
    
    e = times(&end);

    printf("real time = %d\n", e - s);

    printf("user time = %d\n", end.tms_utime - begin.tms_utime);
 
    printf("syst time = %d\n", end.tms_stime - begin.tms_stime); 
    
    char *name = getlogin();
    printf("name = %s\n", name);
    
}
