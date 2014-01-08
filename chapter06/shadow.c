#include <shadow.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
    struct spwd *result;

    while ((result = getspent()) != NULL) {
        printf("name : %s ", result->sp_namp);
        printf("pwd : %s\n", result->sp_pwdp);
    }
}
