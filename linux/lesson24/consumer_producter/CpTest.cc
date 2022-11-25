#include "BlockQueue.hpp"
#include "Task.hpp"
#include <time.h>
#include <cstdlib>
#include <unistd.h>

using namespace ns_blockqueue;
using namespace ns_task;

void *consumer(void *args)
{
    // 获取到阻塞队列这个公共资源(交易场所)
    BlockQueue<Task> *bq = (BlockQueue<Task> *)args;
    while (true)
    {
        Task t;
        bq->Pop(&t); // 这里完成了任务消费的第一步
        t.Run();
        // sleep(2);
        // int data = 0;
        // bq->Pop(&data);

        // std::cout << "消费者消费了一个数据:" << data << std::endl;
    }
}

void *producter(void *args)
{
    BlockQueue<Task> *bq = (BlockQueue<Task> *)args;
    std::string ops = "+-*/%";
    while (true)
    {
        // 1. 制造数据，生产者的数据(task)从哪里来？
        int x = rand() % 20 + 1;
        int y = rand() % 10 + 1;
        char op = ops[rand() % 5];
        Task t(x, y, op);
        bq->Push(t);
        sleep(1);
        // sleep(2);
        //  1. 制造数据
        // int data = rand() % 20 + 1;
        // std::cout << "生产者生产数据：" << data << std::endl;
        // bq->Push(data);
    }
}

int main()
{
    srand((long long)time(nullptr));
    BlockQueue<Task> *bq = new BlockQueue<Task>();

    pthread_t c, p; // 创建消费者、生产者线程
    pthread_create(&c, nullptr, consumer, (void *)bq);
    pthread_create(&p, nullptr, producter, (void *)bq);

    pthread_join(c, nullptr);
    pthread_join(p, nullptr);

    return 0;
}