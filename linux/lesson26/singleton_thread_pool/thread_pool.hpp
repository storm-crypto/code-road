#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <unistd.h>
#include <pthread.h>

namespace ns_threadpool
{
    const int g_num = 5;
    template <class T>
    class ThreadPool
    {
    private:
        int _num;
        std::queue<T> _task_queue; // 该成员是一个临界资源

        pthread_mutex_t _mtx;
        pthread_cond_t _cond;

    private:
        ThreadPool(int num = g_num)
            : _num(num)
        {
            pthread_mutex_init(&_mtx, nullptr);
            pthread_cond_init(&_cond, nullptr);
        }
        ThreadPool(const ThreadPool<T> &tp) = delete;

    public:
        void Lock()
        {
            pthread_mutex_lock(&_mtx);
        }
        void Unlock()
        {
            pthread_mutex_unlock(&_mtx);
        }
        // 线程等待
        void Wait()
        {
            pthread_cond_wait(&_cond, &_mtx);
        }
        void Wakeup()
        {
            pthread_cond_signal(&_cond);
        }
        bool IsEmpty()
        {
            return _task_queue.empty();
        }

    public:
        // 在类中要让线程执行类内方法是不可行的
        // 必须要让线程执行静态方法
        static void *Rountine(void *args)
        {
            pthread_detach(pthread_self());
            ThreadPool<T> *tp = (ThreadPool<T> *)args;
            while (true)
            {
                tp->Lock();
                // 判断线程池中的任务队列中是否有任务
                while (tp->IsEmpty())
                {
                    // 任务队列为空，线程该怎么办？
                    // 线程挂起
                    tp->Wait();
                }
                // 该线程队列中一定有任务了
                T t;
                tp->PopTask(&t);
                tp->Unlock();
                // 运行可以放在释放了锁之后再执行
                t.Run();
            }
        }
        // 初始化一批线程出来
        void InitThreadPool()
        {
            pthread_t tid;
            for (int i = 0; i < _num; i++)
            {
                pthread_create(&tid, nullptr, Rountine, (void *)this);
            }
        }
        void PushTask(const T &in)
        {
            Lock();
            _task_queue.push(in);
            Unlock();
            // 唤醒线程
            Wakeup();
        }
        void PopTask(T *out)
        {
            *out = _task_queue.front();
            _task_queue.pop();
        }

        ~ThreadPool()
        {
            pthread_mutex_destroy(&_mtx);
            pthread_cond_destroy(&_cond);
        }
    };
}