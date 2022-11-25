#pragma once

#include <iostream>
#include <vector>

namespace ns_ring_queue
{
    template <class T>
    class RingQueue
    {
    private:
        std::vector<T> _ring_queue;
        int _cap;

    public:
        RingQueue() {}
        ~RingQueue() {}
    };
}