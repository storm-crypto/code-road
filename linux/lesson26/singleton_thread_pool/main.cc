#include "thread_pool.hpp"
#include "Task.hpp"

#include <ctime>
#include <cstdlib>

using namespace ns_threadpool;
using namespace ns_task;

int main()
{
    // ThreadPool<Task> *tp = new ThreadPool<Task>();
    // tp->InitThreadPool();
    std::cout << "当前没有任务" << std::endl;
    std::cout << "当前没有任务" << std::endl;
    std::cout << "当前没有任务" << std::endl;
    std::cout << "当前没有任务" << std::endl;
    std::cout << "当前没有任务" << std::endl;
    sleep(5);
    srand((long long)time(nullptr));
    while (true)
    {
        // 派发任务
        Task t(rand() % 20 + 1, rand() % 10 + 1, "+-*/%"[rand() % 5]);
        ThreadPool<Task>::GetInstance()->PushTask(t);
        sleep(1);
    }
    return 0;
}