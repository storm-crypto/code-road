#include <stdio.h>

//int* test()
//{
//    int a = 10;
//    return &a;
//}
//
//int main() {
//   int *p = test();
//   *p = 100;
//    return 0;
//}

// 用指针实现my_strlen
int my_strlen(char* str)
{
    char* start = str;
    while (*str)
    {
        str++;
    }
    return str - start;
}

int main()
{
    char arr[] = "abcdef";
    int len = my_strlen(arr);
    printf("%d\n", len);

    return 0;
}
