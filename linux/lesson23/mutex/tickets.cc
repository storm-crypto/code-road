#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>

// 抢票逻辑，1000张票，5个线程同时抢

int tickets = 1000;

void *ThreadRoutine(void* args)
{
    int id = *(int*)args;
    delete (int*)args;

    while (true)
    {
        if (tickets > 0){
            // 抢票
            usleep(1000);
            std::cout << "我是[" << id << "] 我要抢的票是：" << tickets << std::endl;
            tickets--;
            printf("");
        }
        else{
            // 没有票
            break;
        }

    }
}

int main()
{
    pthread_t tid[5];
    for (int i = 0; i < 5; i++){
        int *id = new int(i);
        pthread_create(tid + i, nullptr, ThreadRoutine, (void *)id);
    }
    
    for (int i = 0; i < 5; i++){
        pthread_join(tid[i], nullptr);
    }
    
    return 0;
}