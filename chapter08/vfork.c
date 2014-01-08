#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int global;

int
main(int argc, char *argv[])
{
    int var;
  
    var = 100;
    global = 100;
 
    pid_t pid = vfork();
    if (pid < 0) {
        perror("error");

    } else if (pid == 0) {
        var += 1;
        global += 1;
        exit(0);
    }
    int i;
    i = printf("%d  %d\n", global, var);
    
    char buf[20];
    sprintf (buf,"%d\n", i);

    write (STDOUT_FILENO, buf, strlen(buf));
}
