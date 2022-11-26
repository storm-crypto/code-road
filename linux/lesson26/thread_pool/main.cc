#include "thread_pool.hpp"

using namespace ns_threadpool;

int main()
{
    ThreadPool<int> *tp = new ThreadPool<int>();
    tp->InitThreadPool();

    while (1)
        ;
    return 0;
}