#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_run(void *args)
{
    while (1)
    {
        printf("我是新线程[%s], 我的线程id是%lu\n", (char*)args, pthread_self());
        sleep(1);
    }
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, thread_run, (void *)"new thread");

    while (1)
    {
        printf("我是主线程, 我创建的线程id是:%lu, 我自己的线程id是: %lu\n", tid, pthread_self());
        sleep(1);
    }

    return 0;
}