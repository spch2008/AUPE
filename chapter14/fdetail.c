#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
    struct stat statbuf;
    
    int fdin = open("/home/spch2008/test", O_RDWR);
    int res  = fstat(fdin, &statbuf);
 
    printf("size : %d\n", statbuf.st_size);   
    return 0;
}
