#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signo)
{
    switch(signo)
    {
        case 2:
            printf("hello bit, get a signal: %d\n", signo);
            break;
        case 3:
            printf("hello world, get a signal: %d\n", signo);
            break;
        case 9:
            printf("hello ..., get a signal: %d\n", signo);
            break;
        default:
            printf("get signo: %d\n", signo);
            break;
    }
    exit(1);
}

int main()
{
    // 将所有的信号都进程捕捉
    int sig = 1;
    for (; sig < 32; sig++)
    {
        signal(sig, handler);
    }

    while (1)
    {
        int *p = NULL;
        p = (int*)100; // 会出现段错误，导致进程奔溃
        *p = 100;
        printf("hello bit\n");
        sleep(1);
    }
    return 0;
}