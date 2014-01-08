#include <unistd.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
    uid_t uid;
    uid_t euid;

    gid_t gid;
    gid_t egid;

    uid = getuid();
    euid = geteuid();

    gid = getgid();
    egid = getegid();

    printf("uid = %d\n", uid);
    printf("euid = %d\n", euid);
    printf("gid = %d\n", gid);
    printf("egid = %d\n", egid);

    return 0;
}
