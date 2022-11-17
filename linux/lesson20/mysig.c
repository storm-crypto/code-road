#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// 显示pending表
void show_pending(sigset_t *set)
{
    printf("cur pending:");
    int i = 1;
    for (; i <= 31; i++)
    {
        if (sigismember(set, i)){
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    printf("\n");
}

int main()
{
    // 虽然sigset_t是一个位图结构，但是不同的OS实现是不一样的，不能让用户直接修改该变量
    // 需要使用特定的函数

    // set是要给变量，保存在用户栈上
    // sigset_t是不能直接进行|那些操作的

    sigset_t iset, oset;

    sigemptyset(&iset);
    sigemptyset(&oset);

    sigaddset(&iset, 2);

    // 1. 设置当前进程的屏蔽字
    // 2. 获取当前进程的屏蔽字
    sigprocmask(SIG_SETMASK, &iset, & oset);
    
    sigset_t pending;
    while (1)
    {
        sigemptyset(&pending); // 初始化为全0

        sigpending(&pending); // 获取pending表

        show_pending(&pending);

        sleep(1);
    }

    return 0;
}