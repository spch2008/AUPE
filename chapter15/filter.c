#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 20

int
main(int argc, char *argv[])
{
    char line[MAXLINE];
    FILE *fpin;

    if ((fpin = popen("./lower", "r")) == NULL) {
        perror("popen error!\n");
        exit(1);
    }

    for ( ; ; ) {
        fgets(line, MAXLINE, stdin);
        fputs("main:", stdout);
        fputs(line, stdout);
        fputs("\n", stdout);
     /*   fputs("prompt> ", stdout);
        fflush(stdout);
        fgets(line, MAXLINE, stdin);
        fputs(line, stdout);
        if (fgets(line, MAXLINE, fpin) == NULL)
            break;
        if (fputs(line, stdout) == EOF)
            perror("fputs error to pipe"); */
    }
  
    if (pclose(fpin) == -1)
        perror("pclose error!\n");
  
    putchar('\n');
    exit(0);
    
}
