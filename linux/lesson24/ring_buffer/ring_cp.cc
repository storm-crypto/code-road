#include "ring_queue.hpp"
#include <pthread.h>

using namespace ns_ring_queue;

void *consumer(void *args)
{
    RingQueue<int> *rq = (RingQueue<int> *)args;
    while (true)
    {
        // rq->Pop();
    }
}

void *producter(void *args)
{
    RingQueue<int> *rq = (RingQueue<int> *)args;
    while (true)
    {
        // rq->Push();
    }
}

int main()
{
    RingQueue<int> *rq = new RingQueue<int>();

    pthread_t c, p;
    pthread_create(&c, nullptr, consumer, (void *)rq);
    pthread_create(&p, nullptr, producter, (void *)rq);

    pthread_join(c, nullptr);
    pthread_join(p, nullptr);

    return 0;
}