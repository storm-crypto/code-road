#include "BlockQueue.hpp"

using namespace ns_blockqueue;

void *consumer(void *args)
{
    // 获取到阻塞队列这个公共资源(交易场所)
    BlockQueue<int> *bq = (BlockQueue<int> *)args;
    while (true)
    {
        bq->Pop();
    }
}

void *producter(void *args)
{
    BlockQueue<int> *bq = (BlockQueue<int> *)args;
    while (true)
    {
        bq->Push();
    }
}

int main()
{
    BlockQueue<int> *bq = new BlockQueue<int>();

    pthread_t c, p; // 创建消费者、生产者线程
    pthread_create(&c, nullptr, consumer, (void *)bq);
    pthread_create(&p, nullptr, producter, (void *)bq);

    pthread_join(c, nullptr);
    pthread_join(p, nullptr);

    return 0;
}