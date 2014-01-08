#include <unistd.h>

int
main(int argc, char *argv[])
{
    pid_t pid;
    
    if ((pid = fork()) < 0) {
        perror("error");
        
    } else if (pid == 0) {
        if (execlp("testinterp", "testinterp",
                  "myarg1", "MY ARG2", (char*)0) < 0)
            perror("execl error\n");
        
    }
    
    if (waitpid(pid, NULL, 0) < 0)
        perror("waitpid error\n");
    return 0;
}