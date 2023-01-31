#include <iostream>
#include <string>
#include <cerrno>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const uint16_t port = 8080;

int main()
{
    // 1. 创建套接字，打开网络文件
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        std::cerr << "socket create error: " << errno << std::endl;
        return 1;
    }

    // 2. 给该服务器绑定端口和ip(特殊处理)

    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(port); // 此处的端口号，是我们计算机上的变量，是主机序列
    // a. 需要将人识别的点分十进制，字符串风格IP地址，转成4字节整数IP
    // b. 也要考虑大小端
    // in_addr_t inet_addr(const char *cp); 能完成上面ab两个工作

    // 坑：
    // 云服务器，不允许用户直接bind公网IP，另外，实际正常编写的时候，我们也不会指明IP
    // local.sin_addr.s_addr = inet_addr("43.2.2.2"); // 点分十进制，字符串风格
    // INADDR_ANY:如果你bind的是确定的IP(主机），意味着只有发到该IP主机上的数据，才会
    // 交给你的网络进程， 但是一般服务器可能有多张网卡，配置多个IP，我们需要的不是
    // 某个IP上面的数据，我们需要的是，所有发送到该主机，发送到该端口的数据！
    local.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&local, sizeof(local)) < 0)
    {
        std::cerr << "bind error: " << errno << std::endl;
        return 2;
    }

    // 3. 提供服务
    bool quit = false;
#define NUM 1024
    char buffer[NUM];
    while (!quit)
    {
        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);

        recvfrom(sock, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&peer, &len);

        std::cout << "client# " << buffer << std::endl;

        std::string echo_hello = "hello";
        sendto(sock, echo_hello.c_str(), echo_hello.size(), 0, (struct sockaddr *)&peer, len);
    }

    return 0;
}