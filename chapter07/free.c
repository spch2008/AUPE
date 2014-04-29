#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int*)malloc(10 * sizeof(int));

    char *p = (char*)ptr;
  
    int val = *(p-1);  
    printf("%d\n", val);

    val = *(p-2);
    printf("%d\n", val);

    val = *(p-3);
    printf("%d\n", val);

    val = *(p-4);
    printf("%d\n", val);

    val = *(p-5);
    printf("%d\n", val);

    val = *(p-6);
    printf("%d\n", val);
    
    
}
