#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int
main(int argc, char *argv[])
{
    int fd[2], res;
    char buf[20];    
   

    if (pipe(fd) < 0) {
        perror("create pipe error !\n");
        exit(0);

    }
    close(fd[1]);
    //strcpy(buf, "hello world");
    //write(fd[1], buf, strlen(buf));
    
    memset(buf, 0, sizeof(buf));
    res = read(fd[0], buf, sizeof(buf));
    if (res == 0) {
         printf("write fd closed\n");

    } else {
        printf("read data : %s\n", buf);

    }

    return 0;
}

