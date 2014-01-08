#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid  = getpid();
    pid_t ppid = getppid();

    printf("%d\n", pid);
    printf("%d\n", ppid);

    uid_t uid  = getuid();
    uid_t euid = geteuid();
    printf("uid: %d\n", uid);
    printf("euid: %d\n", euid);

    gid_t gid  = getgid();
    gid_t egid = getegid();
    printf("gid : %d\n", gid);
    printf("egid : %d\n", egid);
}
