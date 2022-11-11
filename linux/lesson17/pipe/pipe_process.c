#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int pipefd[2] = {0};
    if (pipe(pipefd) != 0) {
        perror("pipe error");
        return 1;
    }

    printf("pipefd[0]:%d\n", pipefd[0]); // fd=3
    printf("pipefd[1]:%d\n", pipefd[1]); // fd=4

    // 我们想让父进程进行读取，子进程写入
    // pipefd: 0(嘴):读取 1(笔)：写入   
    if (fork() == 0){
        // 子进程 -- 写入
        close(pipefd[0]);

        const char* msg = "hello 比特";
        int count = 0;
        while (1)
        {
            //write(pipefd[1], msg, strlen(msg));
            // sleep(1);
            write(pipefd[1], "a", 1);
            count ++;
            printf("count: %d\n", count);
        }

        exit(0);
    }
    // 父进程 -- 读取
    close(pipefd[1]);
    while (1)
    {
        sleep(3);
        char c = 0;
        read(pipefd[0], &c, 1);
        printf("father take :%c\n", c);
        // 如果read的返回值是0，意味着子进程关闭文件描述符了
        // read的返回值是表示读取了多少个字节
        // ssize_t s = read(pipefd[0], buffer, sizeof (buffer) - 1);
        // if (s == 0){
        //     break;
        // }
        // else if (s > 0)
        // {
        //     buffer[s] = 0;
        //     printf("child say:%s\n", buffer);
        // }
        // else 
        // {
        //     break;
        // }
    }

    return 0;
}