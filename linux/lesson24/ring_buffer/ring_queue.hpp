#pragma once

#include <iostream>
#include <vector>
#include <semaphore.h>

namespace ns_ring_queue
{
    const int g_cap_default = 10;

    template <class T>
    class RingQueue
    {
    private:
        std::vector<T> _ring_queue;
        int _cap;
        // 生产者关心空位置资源
        sem_t _blank_sem_;
        // 消费者关心数据资源
        sem_t _data_sem_;

    public:
        RingQueue(int cap = g_cap_default)
            : _cap = cap,
              _ring_queue(cap)
        {
            sem_init(&_blank_sem_, 0, cap);
            sem_init(&_data_sem_, 0, 0); // 数据信号量的初始值为0
        }
        ~RingQueue()
        {
            sem_destroy(&_blank_sem_);
            sem_destroy(&_data_sem_);
        }

    public:
        void Push(const T &in)
        {
            // 生产接口
        }
        void Pop(T *out)
        {
            // 消费接口
        }
    };
}