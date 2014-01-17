#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 10

int
main(int argc, char *argv[])
{
    int fd, res;
    off_t offset;
    char buf[BUF_SIZE];

    fd = open("./story", O_RDWR | O_APPEND);
    if (fd == -1) {
        perror("open error");
        exit(1);
    }

    offset = lseek(fd, 5, SEEK_CUR);
    if (offset == -1) {
        perror("lseek error");
        exit(1);
    }


    res = read(fd, buf, BUF_SIZE);
    if (res == -1) {
        perror("read error");
        exit(1);
    }

    write(STDOUT_FILENO, buf, res);

    offset = lseek(fd, 0, SEEK_CUR);
    if (offset == -1) {
        perror("lseek error");
        exit(1);
    }

    memset(buf, 0, BUF_SIZE);
    strncpy(buf, "my name is puppy", BUF_SIZE);

    res = write(fd, buf, strlen(buf));
    if (res == -1) {
        perror("write error");
        exit(1);
    }

    close(fd);

    return 0;
}
