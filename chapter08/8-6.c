#include <unistd.h>

int
main(int argc, char *argv[])
{
    pid_t pid;
    
    if ((pid = fork()) < 0) {
        perror("fork error");
        
    } else if (pid == 0) {
        _exit(0);
        
    }
    
    sleep(1);
    
    system("ps aux | grep Z");
    
    return 0;
}