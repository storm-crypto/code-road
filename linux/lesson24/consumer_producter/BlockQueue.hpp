#pragma once

#include <iostream>
#include <queue>
#include <pthread.h>

namespace ns_blockqueue
{
    template <class T>
    class BlockQueue
    {
    private:
        std::queue<T> _bq;    // 阻塞队列
        int _cap;             // 队列的元素上限
        pthread_mutex_t _mtx; // 保护临界资源的锁

        pthread_cond_t _is_full;  // _bq满的，消费者在该条件变量下等待
        pthread_cond_t _is_empty; //_bq空的，生产者在该条件变量下等待

    public:
        BlockQueue()
        {
        }
        ~BlockQueue()
        {
        }

    public:
        void Push()
        {
            // 向队列中放数据，生产函数
        }
        void Pop()
        {
            // 从队列中拿数据，消费函数
        }
    };
}