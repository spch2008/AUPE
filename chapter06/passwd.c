#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    struct passwd *result;
 
    setpwent();
    while ((result = getpwent()) != NULL) {
        printf("name : %s ", result->pw_name);
        printf("pwd : %s\n", result->pw_passwd);
    }
    endpwent();
}
