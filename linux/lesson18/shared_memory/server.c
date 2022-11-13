#include "comm.h"
#include <unistd.h>

int main()
{
    key_t key = ftok(PATH_NAME, PROJ_ID);
    if (key < 0)
    {
        perror("ftok");
        return 1;
    }

    int shmid = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0666); // 创建全新的shm，如果和系统已经存在的ID冲突，我们出错返回
    if (shmid < 0)
    {
        perror("shmget");
        return 2;
    }

    printf("key: %u, shmid: %d\n", key, shmid);

    // sleep(1);

    char *mem = (char *)shmat(shmid, NULL, 0);
    printf("attaches shm success\n");
    // sleep(15);

    // 这里就是我后面要进行的通信逻辑
    while (1)
    {
        sleep(1);
        // 这里有没有调用类似pipe or fifo中的read这样的结果呢？
        printf("%s\n", mem); // server认为共享内存里面放的是一个长字符串
    }

    shmdt(mem);
    printf("detaches shm success\n");
    // sleep(5);

    shmctl(shmid, IPC_RMID, NULL); // 销毁共享内存
    printf("key: 0x%x, shmid: %d -> shm delete success\n", key, shmid);

    // sleep(10);

    return 0;
}