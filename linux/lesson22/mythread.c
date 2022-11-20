#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_run(void *args)
{
    int num = *(int*)args;
    while (1)
    {
        printf("我是新线程[%d], 我的线程id是%lu\n", num, pthread_self());
        sleep(10);
        // 野指针问题，会出现segmentaion fault
        if (num == 3) 
        {
            printf("thread number : %d quit\n", num);
            int* p = NULL;
            *p = 1000;
        }
    }
}

int main()
{
    pthread_t tid[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        pthread_create(tid + i, NULL, thread_run, (void*)&i);
        sleep(1);
    }
    

    while (1)
    {
        printf("我是主线程, 我自己的thread id是: %lu\n", pthread_self());
        printf("###################### begin ###########################\n");
        for (i = 0; i < 5; i++)
        {
            printf("我创建的线程[%d]是: %lu\n", i, tid[i]);
        }
        printf("###################### end ###########################\n");
        
        sleep(1);
    }

    return 0;
}