#include "comm.h"
#include <string.h>

int main()
{
    // 不需要再创建fifo，只要直接获取即可
    int fd = open(MY_FIFO, O_WRONLY); // 只写
    if (fd < 0){
        perror("open");
        return 1;
    }

    // 业务逻辑
    while (1){
        printf("请输入# ");
        fflush(stdout);
        char buffer[64] = {0};
        // 先把数据从标准输入拿到client进程内部
        ssize_t s = read(0, buffer, sizeof(buffer) - 1);
        if (s > 0)
        {
            buffer[s - 1] = 0; // 解决了遇到\n会自动换行的问题
            printf("%s\n", buffer);

            // 拿到了数据
            write(fd, buffer, strlen(buffer)); // 将输入写入命名管道
        }
    }
    close(fd);

    return 0;
}