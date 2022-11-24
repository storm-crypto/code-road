#include "BlockQueue.hpp"
#include <time.h>
#include <cstdlib>
#include <unistd.h>

using namespace ns_blockqueue;

void *consumer(void *args)
{
    // 获取到阻塞队列这个公共资源(交易场所)
    BlockQueue<int> *bq = (BlockQueue<int> *)args;
    while (true)
    {
        sleep(2);
        int data = 0;
        bq->Pop(&data);

        std::cout << "消费者消费了一个数据:" << data << std::endl;
    }
}

void *producter(void *args)
{
    BlockQueue<int> *bq = (BlockQueue<int> *)args;
    while (true)
    {
        // sleep(2);
        //  1. 制造数据
        int data = rand() % 20 + 1;
        std::cout << "生产者生产数据：" << data << std::endl;
        bq->Push(data);
    }
}

int main()
{
    srand((long long)time(nullptr));
    BlockQueue<int> *bq = new BlockQueue<int>();

    pthread_t c, p; // 创建消费者、生产者线程
    pthread_create(&c, nullptr, consumer, (void *)bq);
    pthread_create(&p, nullptr, producter, (void *)bq);

    pthread_join(c, nullptr);
    pthread_join(p, nullptr);

    return 0;
}