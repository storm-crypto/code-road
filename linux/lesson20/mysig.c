#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    sigset_t iset, oset;

    sigemptyset(&iset);
    sigemptyset(&oset);

    sigaddset(&iset, 2);

    // 1. 设置当前进程的屏蔽字
    // 2. 获取当前进程的屏蔽字
    sigprocmask(SIG_SETMASK, &iset, & oset);

    while (1)
    {
        printf("hello bit!\n");
        sleep(1);
    }

    return 0;
}