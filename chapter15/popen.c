#include <stdio.h>
#include <stdlib.h>

#define PAGER "${PAGER:-more}"
#define MAXLINE 100

int
main(int argc, char *argv[])
{
    char line[MAXLINE];
    FILE *fin, *fpout;

    if ((fin = fopen("/home/spch2008/story", "r")) == NULL) {
        perror("fopen error!\n");
        exit(1);
    }

    if ((fpout = popen(PAGER, "w")) == NULL) {
        perror("popen error!\n");
        exit(1);
    }

    while (fgets(line, MAXLINE, fin) != NULL) {
        fputs(line, fpout);
    }

    if (pclose(fpout) == -1) {
        perror("pclose error!\n");
    }

    exit(0);
}
