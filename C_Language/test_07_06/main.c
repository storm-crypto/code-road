#include <accctrl.h>
#include <stdio.h>

// 字符串拷贝，库函数strcpy
//int main() {
//    char arr1[] = "abcdef";
//    char arr2[20] = "xxxxxxxxxxx";
//    strcpy(arr2, arr1);
//    printf("%s\n", arr1);
//    return 0;
//}

// 将前面的几个字符设置成x，用memset
//int main()
//{
//    char arr[] = "hello bit";
//    memset(arr, 'X', 5);
//
//    printf("%s\n", arr);
//
//    return 0;
//}

// 写一个函数可以找出两个整数的最大值

int get_max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    int a = 0;
    int b = 0;
    scanf("%d%d", &a, &b);

    int m = get_max(a, b);
    printf("%d", m);
    return 0;
}