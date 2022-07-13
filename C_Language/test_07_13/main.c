#include <assert.h>
#include <stdio.h>

//int main()
//{
//    int n = 0;
//    //scanf("%d", &n);
//
//    // 求n的阶乘
//    // 1~n的数字
//    int i = 0;
//    int ret = 1;
//    int sum = 0;
//    for (n = 1; n <= 3; n++)
//    {
//        ret = 1;
//        for (i = 1; i <= n; i++)
//        {
//            ret *= i;
//        }
//        sum += ret;
//    }
//
//    return 0;
//}

//int main()
//{
//    int sum = 0;
//
//    int ret = 1;
//    int n = 0;
//    for (n = 1; n <= 3; n++)
//    {
//        ret *= n;
//        sum += ret;
//    }
//    printf("%d\n", sum);
//
//    return 0;
//}
//
//int main() {
//    int i = 0;
//    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    for (i = 0; i <= 12; i++) {
//        arr[i] = 0;
//        printf("hehe\n");
//    }
//    return 0;
//}

// 模拟实现库函数：strcpy

//void my_strcpy(char* dest, char* src)
//{
//    while (*src != '\0')
//    {
//        *dest = *src;
//        dest++;
//        src++;
//    }
//    *dest = *src;
//}

//void my_strcpy(char* dest, char* src)
//{
//    while (*src != '\0')
//    {
//        *dest++ = *src++;
//    }
//    *dest = *src;
//}

// 大师级代码
//void my_strcpy(char* dest, char* src)
//{
//    while (*dest++ = *src++)
//    {
//        ;
//    }
//}

//void my_strcpy(char* dest, char* src)
//{
//    assert(dest != NULL); // 断言:括号里面条件为假，就会断言
//    assert(src != NULL);
//    assert(dest && src);
//    while (*dest++ = *src++)
//    {
//        ;
//    }
//}


//

//char* my_strcpy(char* dest, const char* src)
//{
//    assert(dest != NULL); // 断言:括号里面条件为假，就会断言
//    assert(src != NULL);
//    assert(dest && src);
//    while (*dest++ = *src++)
//    {
//        ;
//    }
//
//    return dest;
//}
//
//int main()
//{
//    char arr1[] = "hello bit";
//    char arr2[] = {0};
//    my_strcpy(arr2, arr1);
//
//    printf("%s\n", arr2);
//
//    return 0;
//}

int my_strlen(const char* p)
{
    assert(p != NULL);

    int ret = 0;

    while (*p != '\0')
    {
        p++;
        ret++;
    }

    return ret;
}

int main()
{
    int len = my_strlen("abcdef");

    printf("%d\n", len);

    return 0;
}
