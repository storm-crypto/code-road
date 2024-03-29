#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int count = 0;

void HandlerAlarm(int signo)
{
    printf("hello: %d\n", count);

    exit(1);
}

int main()
{
    signal(SIGALRM, HandlerAlarm);
    alarm(1);

    while (1)
    {
        count++;
        // printf("hello : %d\n", count++);
    }
}

// // kill命令的使用手册，当参数不够的时候会显示这个手册
// static void Usage(const char *proc)
// {
//     printf("Usage:\n\t %s signo who \n", proc);
// }

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

// // .mytest signo who
// int main(int argc, char *argv[])
// {
//     // 捕获所有信号
//     int sig = 1;
//     for (; sig < 32; sig++)
//     {
//         signal(sig, handler);
//     }

//     int res = alarm(30);
    
//     while (1)
//     {
//         printf("I am a process\n");
//         sleep(1);

//         int res = alarm(0); // 取消闹钟
//         printf("res:%d\n", res);
//     }
//     return 0;
// }

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