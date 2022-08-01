#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>

// 模拟实现atoi
//int my_atoi(const char* str)
//{
//    assert(str);
//    int n = 0;
//    while (*str)
//    {
//        n = n * 10 + *str - '0';
//        str++;
//    }
//    return n;
//}

//enum Status
//{
//    VALID,
//    INVALID
//}status = INVALID; // 非法的
//
//int my_atoi(const char* str)
//{
//    int flag = 0;
//    // 空指针
//    assert(str);
//
//    // 字符串为空
//    if (*str == '\0')
//    {
//        return 0;
//    }
//
//    // 前面有空白字符
//    while (isspace(*str))
//    {
//        str++;
//    }
//    // 正负号
//    if (*str == '+')
//    {
//        flag = 1;
//        str++;
//    }
//    else if (*str == '-')
//    {
//        flag = -1;
//        str++;
//    }
//    long long n = 0;
//    // 处理非数字字符
//    while (*str != '\0')
//    {
//        if (isdigit(*str))
//        {
//            n = n * 10 + flag * (*str - '0');
//            if (n < INT_MIN || n > INT_MAX)
//            {
//                n = 0;
//                break;
//            }
//        }
//        else
//        {
//            n = 0;
//            break;
//        }
//        str++;
//    }
//
//    // 字符串合法的情况
//    if (*str == '\0')
//    {
//        status = VALID;
//    }
//    return (int )n;
//}
//
//int main()
//{
//    char arr[20] = "1234";
//    int ret = my_atoi(arr);
//    if (status == VALID)
//        printf("合法转化%d\n", ret);
//    else
//        printf("非法转化:%d\n", ret);
//
//    return 0;
//}

// 用宏实现二进制的奇数位和偶数位进行交换
#define SWAP(num) (num = (((num & 0x55555555) << 1) + ((num & 0xaaaaaaaa) >> 1)))

int main()
{
    int num = 10;
    SWAP(num);
    printf("%d\n", num);

    return 0;
}