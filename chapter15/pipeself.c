#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int
main(int argc, char *argv[])
{
    int fd[2];
    char buf[20];    
   

    if (pipe(fd) < 0) {
        perror("create pipe error !\n");
        exit(0);

    }
   
    strcpy(buf, "hello world");
    write(fd[1], buf, strlen(buf));
    close(fd[1]);    
    
    memset(buf, 0, sizeof(buf));
    read(fd[0], buf, sizeof(buf));

    printf("read data : %s\n", buf);

    return 0;
}

