#include <stdio.h>
#include <ctype.h>

#define MAXLINE 20

int
main(int argc, char *argv[])
{
    int c;
/*   
    while ((c = getchar()) != EOF) {
        if (isupper(c))
            c = tolower(c);

        if (putchar(c) == EOF)
            perror("put error!\n");

        if (c == '\n')
            fflush(stdout);        
    }   
  */
    char line[MAXLINE];
    for ( ; ; ) {
        fgets(line, MAXLINE, stdin);
        fputs("not main:", stdout);
        fputs(line, stdout);
        fputs("\n", stdout);
    }   
  
    return 0;
}
