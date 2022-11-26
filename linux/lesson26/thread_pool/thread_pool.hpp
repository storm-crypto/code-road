#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <unistd.h>

namespace ns_threadpool
{
    const int g_num = 5;
    template <class T>
    class ThreadPool
    {
    private:
        int _num;
        std::queue<T> _task_queue;

    public:
        ThreadPool(int num = g_num)
            : _num(num)
        {
        }
        // 在类中要让线程执行类内方法是不可行的
        // 必须要让线程执行静态方法
        static void *Rountine(void *args)
        {
            pthread_detach(pthread_self());
            while (true)
            {
                std::cout << "thread running..." << std::endl;
                sleep(1);
            }
        }
        // 初始化一批线程出来
        void InitThreadPool()
        {
            pthread_t tid;
            for (int i = 0; i < _num; i++)
            {
                pthread_create(&tid, nullptr, Rountine, nullptr);
            }
        }
        ~ThreadPool()
        {
        }
    };
}