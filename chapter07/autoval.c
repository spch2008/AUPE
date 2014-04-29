#include <stdio.h>

int f1(int val)
{
    int *ptr;
    if (val == 0)
    {
        int val;
        val = 5;
        ptr = &val;
    }

    return (*ptr + 1);
}

int main()
{
    int val = f1(3);
    printf("%d\n", val);
}
