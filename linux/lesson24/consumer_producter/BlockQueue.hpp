#pragma once

#include <iostream>
#include <queue>

namespace ns_blockqueue
{
    template <class T>
    class BlockQueue
    {
    private:
        std::queue<T> bq; // 阻塞队列
        int cap;          // 队列的元素上限
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