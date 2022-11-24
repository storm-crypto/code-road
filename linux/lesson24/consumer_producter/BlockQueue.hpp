#pragma once

#include <iostream>
#include <queue>
#include <pthread.h>

namespace ns_blockqueue
{
    const int default_cap = 5;

    template <class T>
    class BlockQueue
    {
    private:
        std::queue<T> _bq;    // 阻塞队列
        int _cap;             // 队列的元素上限
        pthread_mutex_t _mtx; // 保护临界资源的锁

        pthread_cond_t _is_full;  // _bq满的，消费者在该条件变量下等待
        pthread_cond_t _is_empty; //_bq空的，生产者在该条件变量下等待

    private:
        bool IsFull()
        {
            return _bq.size() == _cap;
        }

        bool IsEmpty()
        {
            return _bq.size() == 0;
        }

        void LockQueue()
        {
            pthread_mutex_lock(&_mtx);
        }

        void UnlockQueue()
        {
            pthread_mutex_unlock(&_mtx);
        }

        void ProducterWait()
        {
            // 1. 调用的时候，会首先自动释放_mtx，然后再挂起自己
            // 2. 返回的时候，会首先自动竞争锁，获取到锁之后，才能返回
            pthread_cond_wait(&_is_empty, &_mtx);
        }

        void ConsumerWait()
        {
            // 1. 调用的时候，会首先自动释放_mtx，然后再挂起自己
            // 2. 返回的时候，会首先自动竞争锁，获取到锁之后，才能返回
            pthread_cond_wait(&_is_full, &_mtx);
        }

        void WakeupComsumer()
        {
            pthread_cond_signal(&_is_full);
        }

        void WakeupProducter()
        {
            pthread_cond_signal(&_is_empty);
        }

    public:
        BlockQueue(int cap = default_cap)
            : _cap(cap)
        {
            pthread_mutex_init(&_mtx, nullptr);
            pthread_cond_init(&_is_empty, nullptr);
            pthread_cond_init(&_is_full, nullptr);
        }
        ~BlockQueue()
        {
            pthread_mutex_destroy(&_mtx);
            pthread_cond_destroy(&_is_empty);
            pthread_cond_destroy(&_is_full);
        }

    public:
        // const &：输入型参数
        // *：输出型参数
        // &：输入输出型参数
        void Push(const T &in)
        {
            LockQueue();
            if (IsFull())
            {
                // 等待，把线程挂起的时候，自己是有锁的
                ProducterWait();
            }
            // 向队列中放数据，生产函数
            _bq.push(in);

            // 唤醒consumer
            WakeupConsumer();
            UnlockQueue();
        }
        void Pop(T *out)
        {
            LockQueue();
            // 从队列中拿数据，消费函数
            if (IsEmpty())
            {
                // 无法消费
                ConsumerWait();
            }
            *out = _bq.front();
            _bq.pop();

            // 唤醒生产者
            WakeupProducter();

            UnlockQueue();
        }
    };
}