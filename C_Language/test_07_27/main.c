#include <assert.h>
#include <stdio.h>
#include <string.h>

// strtok函数的使用
//int main()
//{
//    char arr[] = "zpengwei@yeah.net.hehe";
//    char buf[50] = {0};
//    strcpy(buf, arr);
//
//    const char* sep = "@.";
//    char* str = NULL;
//    for (str = strtok(buf, sep); str != NULL; str = strtok(NULL, sep))
//    {
//        printf("%s\n", str);
//    }
//
//    return 0;
//}

//void* my_memcpy(void* dest, const void* src, size_t count)
//{
//    assert(dest && src);
//    void* ret = dest;
//    while (count--)
//    {
//        *(char*)dest = *(char*)src;
//        dest = (char*)dest + 1;
//        src = (char*)src + 1;
//    }
//    return ret;
//}
//
//int main()
//{
//    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int arr2[5] = {0};
//    my_memcpy(arr2, arr1, 20);
//
//    return 0;
//}

// memmove函数的实现
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//    assert(dest && src);
//    void* ret = dest;
//    if (dest < src)
//    {
//        // src从前往后拷贝
//        while (count--)
//        {
//            *(char*)dest = *(char*)src;
//            dest = (char*)dest + 1;
//            src = (char*)src + 1;
//        }
//
//    }
//    else
//    {
//        // src从后往前拷贝
//        while (count--)
//        {
//            *((char*)dest + count) = *((char*)src + count);
//
//        }
//    }
//
//    return ret;
//}
//
//int main()
//{
//    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//    my_memmove(arr1, arr1 + 2, 20);
//
//    int i = 0;
//    int sz = sizeof (arr1) / sizeof (arr1[0]);
//
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr1[i]);
//    }
//}

//int main()
//{
//    int arr1[] = {1, 2, 3, 4, 5};
//
//    memset(arr1, 0, 20);
//
//    int sz = sizeof (arr1) / sizeof(arr1[0]);
//
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr1[i]);
//    }
//}

//enum Sex
//{
//    MALE,
//    FEMALE,
//    SECRET
//};
//
//int main()
//{
//    enum Sex s = MALE;
//    enum Sex s1 = FEMALE;
//    return 0;
//}

// 练习：判断大小端存储
int check_sys()
{
    union Un
    {
        char c;
        int i;
    }u;
    u.i = 1;
    return u.c;
}

int main()
{
    if (1 == check_sys())
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
    return 0;
}