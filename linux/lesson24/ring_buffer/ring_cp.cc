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
        std::cout << "消费数据是：" << data << std::endl;
        // sleep(1);
    }
}

void *producter(void *args)
{
    RingQueue<int> *rq = (RingQueue<int> *)args;
    while (true)
    {
        int data = rand() % 20 + 1;
        std::cout << "生产数据是：" << data << std::endl;
        rq->Push(data);
        sleep(1);
    }
}

int main()
{
    srand((long long)time(nullptr));
    RingQueue<int> *rq = new RingQueue<int>();

    pthread_t c, p;
    pthread_create(&c, nullptr, consumer, (void *)rq);
    pthread_create(&p, nullptr, producter, (void *)rq);

    pthread_join(c, nullptr);
    pthread_join(p, nullptr);

    return 0;
}