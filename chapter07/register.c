#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int main()
{
    register int rval = 1;
    int aval = 2;    

    int tmp = 3;
    rval += tmp;
    aval += tmp;
    
    setjmp(buf);    

    printf("%d, %d\n", rval, aval);
    return 0;
}
