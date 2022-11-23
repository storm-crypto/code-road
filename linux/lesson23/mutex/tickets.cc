#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <mutex>

// 抢票逻辑，1000张票，5个线程同时抢

// 对临界区进行加锁
class Ticket
{
private:
    int tickets;
    pthread_mutex_t mtx; // 原生线程库，系统界别
    std::mutex mymtx;    // C++，语言级别

public:
    Ticket()
        : tickets(1000)
    {
        pthread_mutex_init(&mtx, nullptr);
    }

    bool GetTicket()
    {
        bool res = true;
        // pthread_mutex_lock(&mtx);
        mymtx.lock();
        if (tickets > 0)
        {
            usleep(1000);
            std::cout << "我是[" << pthread_self() << "] 我要抢的票是：" << tickets << std::endl;
            tickets--;
            printf("");
        }
        else
        {
            printf("票已经被抢空了\n");
            res = false;
        }
        // pthread_mutex_unlock(&mtx);
        mymtx.unlock();

        return res;
    }

    ~Ticket()
    {
        pthread_mutex_destroy(&mtx);
    }
};

void *ThreadRoutine(void *args)
{

    Ticket *t = (Ticket *)args;

    while (true)
    {
        if (!t->GetTicket())
        {
            break;
        }
    }
}

int main()
{
    Ticket *t = new Ticket();

    pthread_t tid[5];
    for (int i = 0; i < 5; i++)
    {
        int *id = new int(i);
        pthread_create(tid + i, nullptr, ThreadRoutine, (void *)t);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(tid[i], nullptr);
    }

    return 0;
}