#pragma once

#include <iostream>
#include <vector>
#include <semaphore.h>
#include <pthread.h>

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

        pthread_mutex_t _c_mtx; // 消费者的锁
        pthread_mutex_t _p_mtx; // 生产者的锁

    public:
        RingQueue(int cap = g_cap_default)
            : _cap(cap),
              _ring_queue(cap)
        {
            sem_init(&_blank_sem, 0, cap);
            sem_init(&_data_sem, 0, 0); // 数据信号量的初始值为0
            _c_step = _p_step = 0;

            pthread_mutex_init(&_c_mtx, nullptr);
            pthread_mutex_init(&_p_mtx, nullptr);
        }
        ~RingQueue()
        {
            sem_destroy(&_blank_sem);
            sem_destroy(&_data_sem);

            pthread_mutex_destroy(&_c_mtx);
            pthread_mutex_destroy(&_p_mtx);
        }

    public:
        // 目前高优先级的先实现单生产和单消费
        // 多生产者多消费者的优势不在这里，而在于并发的获取和处理任务
        void Push(const T &in)
        {
            // 生产接口
            sem_wait(&_blank_sem); // P操作
            pthread_mutex_lock(&_p_mtx);
            // 可以生产了，可是往哪个位置生产呢？
            _ring_queue[_p_step] = in;

            // 它也变成了临界资源
            _p_step++;
            _p_step %= _cap;
            pthread_mutex_unlock(&_p_mtx);

            sem_post(&_data_sem); // V操作
        }
        void Pop(T *out)
        {
            // 消费接口
            sem_wait(&_data_sem);
            pthread_mutex_lock(&_c_mtx);
            *out = _ring_queue[_c_step];

            _c_step++;
            _c_step %= _cap;
            pthread_mutex_unlock(&_c_mtx);

            sem_post(&_blank_sem);
        }
    };
}