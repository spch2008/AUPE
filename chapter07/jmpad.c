#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf jmpbuffer;
int gloval;

void f2()
{
   longjmp(jmpbuffer, 1);
}

void f1()
{
    printf("f1()\n");

    f2();
}

int main(int argc, char *argv[])
{
    int autval;
    register int regval;
    volatile int volval;
    static   int staval;
    
    gloval = 1;
    autval = 2;
    regval = 3;
    volval = 4;
    staval = 5;

    volatile int i = 0;
    if (setjmp(jmpbuffer) == 1)
    {
        printf("g = %d, a = %d, r = %d, v = %d, s = %d\n",
                gloval, autval, regval, volval, staval);
    }
   

    i++;    
    for ( ; i < 5; i++) {
        gloval += 10;
        autval += 10;
        regval += 10;
        volval += 10;
        staval += 10;
        f1();
    } 
}

