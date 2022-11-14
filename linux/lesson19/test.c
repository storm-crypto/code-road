#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

// kill命令的使用手册，当参数不够的时候会显示这个手册
static void Usage(const char *proc)
{
    printf("Usage:\n\t %s signo who \n", proc);
}

// .mytest signo who
int main(int argc, char *argv[])
{
    while (1)
    {
        printf("I am a process\n");
        sleep(3);

        raise(8);
    }
    return 0;
}

// void handler(int signo)
// {
//     switch(signo)
//     {
//         case 2:
//             printf("hello bit, get a signal: %d\n", signo);
//             break;
//         case 3:
//             printf("hello world, get a signal: %d\n", signo);
//             break;
//         case 9:
//             printf("hello ..., get a signal: %d\n", signo);
//             break;
//         default:
//             printf("get signo: %d\n", signo);
//             break;
//     }
//     exit(1);
// }

// int main()
// {
//     // 将所有的信号都进程捕捉
//     // int sig = 1;
//     // for (; sig < 32; sig++)
//     // {
//     //     signal(sig, handler);
//     // }

//     while (1)
//     {
//         int p = 10;
//         p /= 0; 
//         printf("hello bit\n");
//         sleep(1);
//     }
//     return 0;
// }