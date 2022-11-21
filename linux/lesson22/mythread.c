#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_run(void * args)
{
    while (1)
    {
        printf("new thread id : 0x%x\n", pthread_self());
        sleep(2);
    }
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, thread_run, (void *)"new thread");
    while (1)
    {
        printf("main thread id : 0x%x\n", pthread_self());
        sleep(1);
    }
}

// pthread_t g_id;

// void *thread_run(void *args)
// {
//     pthread_detach(pthread_self()); // 线程分离
//     int num = *(int*)args;
//     while (1)
//     {
//         printf("我是新线程[%d], 我的线程id是%lu\n", num, pthread_self());
//         sleep(2);
//         break;
//         // pthread_cancel(g_id);
//         // break;
//         // 野指针问题，会出现segmentaion fault
//         // if (num == 3) 
//         // {
//         //     printf("thread number : %d quit\n", num);
//         //     int* p = NULL;
//         //     *p = 1000;
//         // }
//     }

//     return (void *)111;

//     // pthread_exit(123);
// }

// #define NUM 1

// int main()
// {
//     g_id = pthread_self();
//     pthread_t tid[NUM];
//     int i;
//     for (i = 0; i < NUM; i++)
//     {
//         pthread_create(tid + i, NULL, thread_run, (void*)&i);
//         sleep(1);
//     }

//     //sleep(20);

//     printf("wait sub thread...\n");
//     sleep(1);

//     printf("cancel sub thread...\n");
//     //pthread_cancel(tid[0]);


//     void *status = NULL;
    

//     int ret = 0;
//     for (i = 0; i < NUM; i++)
//     {
//         ret = pthread_join(tid[0], &status);
//     }
    

//     printf("ret : %d, status: %d\n", ret, (int)status);

//     // while (1)
//     // {
//     //     printf("我是主线程, 我自己的thread id是: %lu\n", pthread_self());
//     //     printf("###################### begin ###########################\n");
//     //     for (i = 0; i < 5; i++)
//     //     {
//     //         printf("我创建的线程[%d]是: %lu\n", i, tid[i]);
//     //     }
//     //     printf("###################### end ###########################\n");
        
//     //     sleep(1);
//     // }

//     return 0;
// }