#include "ring_queue.hpp"
#include <pthread.h>
#include <time.h>
#include <unistd.h>

using namespace ns_ring_queue;

void *consumer(void *args)
{
    RingQueue<int> *rq = (RingQueue<int> *)args;
    while (true)
    {
        int data = 0;
        rq->Pop(&data);
        std::cout << "消费数据是：" << data << "   我是" << pthread_self() << std::endl;
        // sleep(1);
    }
}

void *producter(void *args)
{
    RingQueue<int> *rq = (RingQueue<int> *)args;
    while (true)
    {
        int data = rand() % 20 + 1;
        std::cout << "生产数据是：" << data << "  我是：" << pthread_self() << std::endl;
        rq->Push(data);
        sleep(1);
    }
}

int main()
{
    srand((long long)time(nullptr));
    RingQueue<int> *rq = new RingQueue<int>();

    pthread_t c0, c1, c2, c3, p0, p1, p2;
    pthread_create(&c0, nullptr, consumer, (void *)rq);
    pthread_create(&c1, nullptr, consumer, (void *)rq);
    pthread_create(&c2, nullptr, consumer, (void *)rq);
    pthread_create(&c3, nullptr, consumer, (void *)rq);

    pthread_create(&p0, nullptr, producter, (void *)rq);
    pthread_create(&p1, nullptr, producter, (void *)rq);
    pthread_create(&p2, nullptr, producter, (void *)rq);

    pthread_join(c0, nullptr);
    pthread_join(c1, nullptr);
    pthread_join(c2, nullptr);
    pthread_join(c3, nullptr);

    pthread_join(p0, nullptr);
    pthread_join(p1, nullptr);
    pthread_join(p2, nullptr);

    return 0;
}