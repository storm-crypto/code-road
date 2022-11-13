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

    printf("%u\n", key);

    // client这里只需要进行获取即可，不需要创建共享内存
    int shmid = shmget(key, SIZE, IPC_CREAT);
    if (shmid < 0)
    {
        perror("shmget");
        return 1;
    }

    char *mem = (char *)shmat(shmid, NULL, 0);
    // sleep(5);
    printf("client process attaches success!\n");

    // 这个地方就是我们要通信的区域
    // 不断地往共享内存mem中写入字符串
    char c = 'A';
    while (c <= 'Z')
    {
        mem[c - 'A'] = c;
        c++;
        mem[c - 'A'] = 0; // 0表示字符串的结尾
        sleep(2);
    }


    shmdt(mem);
    printf("client process detaches succss\n");
    // sleep(5);
    

    return 0;
}