#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void *thr_fn(void *);
static void printids(const char *);

int
main(int argc, char *argv[])
{
    int res;
    pthread_t tid;
    
    res = pthread_create(&tid, NULL, thr_fn, NULL);
    if (res == -1) {
        perror("can not create thread!\n");
        exit(1);
    }
    
    res = pthread_create(&tid, NULL, thr_fn, NULL);
    if (res == -1) {
        perror("can not create thread!\n");
        exit(1);
    }
    
    printids("main thread:");
    
    sleep(100);
    return 0;
}


static void
printids(const char *s)
{
    pid_t pid;
    pthread_t tid;
    
    pid = getpid();
    tid = pthread_self();
    
    printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid,
           (unsigned int)tid, (unsigned int)tid);
}

static void *
thr_fn(void *arg)
{
    printids("new thread: ");
    sleep(100);
    return ((void*)0);
}