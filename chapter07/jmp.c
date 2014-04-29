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

    if (setjmp(jmpbuffer) == 1)
    {
        printf("g = %d, a = %d, r = %d, v = %d, s = %d\n",
                gloval, autval, regval, volval, staval);
        exit(0);
    }
//    else
//    {
//        printf("setjmp set\n");
//        exit(0);
//    }

    gloval = 20;
    autval = 21;
    regval = 22;
    volval = 23;
    staval = 24;

    f1();
    
}

