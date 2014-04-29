#include <stdio.h>
#include <string.h>

int main()
{
    char *s = "Hello";
    
    int val = printf("%s\n", s);
    printf("%d\n", strlen(s));

    val = printf("%d\n", 4000);
    printf("%d\n", val);
}
