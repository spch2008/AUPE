#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    struct flock lock;
    int fd, res;
    pid_t pid;
    
    fd = open("/home/spch2008/test", O_RDWR);
    
    lock.l_type   = F_RDLCK;
    lock.l_start  = 0;
    lock.l_whence = SEEK_SET;
    lock.l_len    = 0;   
    lock.l_pid    = -1;    
    res = fcntl(fd, F_SETLK, &lock);
    
    pid = fork();
    if (pid == 0) {
        res = fcntl(fd, F_GETLK, &lock);
        printf("pid = %d\n", lock.l_pid);
        if (lock.l_type == F_UNLCK) {
            printf("%d\n", 1122);
        }
        
    } else {
        printf("pid = %d\n", getpid()); 
    }
    
    return 0;
}
