#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo)
{
    printf("get a signal: signal no: %d, pid: %d\n", signo, getpid());
}

int main()
{
    // 通过signal注册对2号信号的处理工作，改成我们的自定义动作
    signal(2, handler);

    while (1)
    {
        printf("hello world!, pid: %d\n", getpid());
        sleep(1);
    }

    return 0;
}