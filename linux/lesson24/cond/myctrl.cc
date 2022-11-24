#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mtx;
pthread_cond_t cond;

// ctrl 控制work线程，让他定期运行
void *ctrl(void *args)
{
    std::string name = (char *)args;
    while (true)
    {
        std::cout << "master say: begin work" << std::endl;
        // 唤醒条件变量下等待的一个线程，是哪一个线程呢？
        // 在cond等待队列里等待的第一个线程
        // pthread_cond_signal(&cond);
        // 唤醒所有线程
        pthread_cond_broadcast(&cond);
        sleep(1);
    }
}

void *work(void *args)
{
    int number = *(int *)args;
    delete (int *)args;

    while (true)
    {
        // 此处我们的mutex不用，暂时先这样写，后面再解释
        pthread_cond_wait(&cond, &mtx);
        std::cout << "worker: " << number << " is working ..." << std::endl;
    }
}

int main()
{
#define NUM 3

    pthread_mutex_init(&mtx, nullptr);
    pthread_cond_init(&cond, nullptr);

    pthread_t master;
    pthread_t worker[NUM];
    pthread_create(&master, nullptr, ctrl, (void *)"boss");
    for (int i = 0; i < NUM; i++)
    {
        int *number = new int(i);
        pthread_create(worker + i, nullptr, work, number);
    }

    for (int i = 0; i < NUM; i++)
    {
        pthread_join(worker[i], nullptr);
    }

    pthread_join(master, nullptr);

    pthread_mutex_destroy(&mtx);
    pthread_cond_destroy(&cond);

    return 0;
}