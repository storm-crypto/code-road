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
        break;
        // 野指针问题，会出现segmentaion fault
        // if (num == 3) 
        // {
        //     printf("thread number : %d quit\n", num);
        //     int* p = NULL;
        //     *p = 1000;
        // }
    }

    return (void*)111;
}

#define NUM 1

int main()
{
    pthread_t tid[NUM];
    int i;
    for (i = 0; i < NUM; i++)
    {
        pthread_create(tid + i, NULL, thread_run, (void*)&i);
        sleep(1);
    }
    void *status = NULL;
    
    pthread_join(tid[0], &status);

    printf("ret : %d\n", (int)status);

    // while (1)
    // {
    //     printf("我是主线程, 我自己的thread id是: %lu\n", pthread_self());
    //     printf("###################### begin ###########################\n");
    //     for (i = 0; i < 5; i++)
    //     {
    //         printf("我创建的线程[%d]是: %lu\n", i, tid[i]);
    //     }
    //     printf("###################### end ###########################\n");
        
    //     sleep(1);
    // }

    return 0;
}