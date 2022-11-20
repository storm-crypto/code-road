#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_run(void *args)
{
    while (1)
    {
        // printf("我是新线程[%s], 我的线程id是%lu\n", (char*)args, pthread_self());
        sleep(3);
    }
}

int main()
{
    pthread_t tid[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        pthread_create(tid + i, NULL, thread_run, (void *)"new thread");
    }
    

    while (1)
    {
        printf("我是主线程, 我自己的thread id是: %lu\n", pthread_self());
        printf("######################begin###########################\n");
        for (i = 0; i < 5; i++)
        {
            printf("我创建的线程[%d]是: %lu\n", i, tid[i]);
        }
        printf("######################end###########################\n");
        
        sleep(1);
    }

    return 0;
}