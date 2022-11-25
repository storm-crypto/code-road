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
        sem_t _blank_sem;
        // 消费者关心数据资源
        sem_t _data_sem;

        int _c_step; // 表示消费者的位置
        int _p_step; // 表示生产者的位置

    public:
        RingQueue(int cap = g_cap_default)
            : _cap = cap,
              _ring_queue(cap)
        {
            sem_init(&_blank_sem, 0, cap);
            sem_init(&_data_sem, 0, 0); // 数据信号量的初始值为0
            _c_step = _p_step = 0;
        }
        ~RingQueue()
        {
            sem_destroy(&_blank_sem);
            sem_destroy(&_data_sem);
        }

    public:
        // 目前高优先级的先实现单生产和单消费
        void Push(const T &in)
        {
            // 生产接口
            sem_wait(&_blank_sem); // P操作
            // 可以生产了，可是往哪个位置生产呢？
            _ring_queue[_p_step] = in;
            sem_post(&_data_sem); // V操作

            _p_step++;
            _p_step %= _cap;
        }
        void Pop(T *out)
        {
            // 消费接口
            sem_wait(&_data_sem);
            *out = _ring_queue[_c_step];
            sem_post(&_blank_sem);

            _c_step++;
            _c_step %= _cap;
        }
    };
}