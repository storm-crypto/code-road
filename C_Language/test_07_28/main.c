#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串

// 判断str1是不是由str2旋转得到的
//int is_left_move(const char* str1, char* str2)
//{
//    int len1 = strlen(str1);
//    int len2 = strlen(str2);
//
//    assert(str1 && str2);
//    // 1. 在str2后面追加一个str2
//    strncat(str2, str2, strlen(str2));
//    // 2. 判断str1是不是追加后的字串
//    char* ret = strstr(str2, str1);
//    if (ret == NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        return 1;
//    }
//}
//
//int main()
//{
//    char arr1[20] = "abcedf";
//    char arr2[20] = "efabcd";
//    // 判断arr2是否由arr1旋转得来
//    int ret = is_left_move(arr2, arr1);
//    if (ret == 1)
//        printf("yes\n");
//    else
//        printf("no\n");
//    return 0;
//}

//int main()
//{
//    int* p = (int*)malloc(1000);
//    int i = 0;
//
//    return 0;
//}

// 练习：找单身狗
// 一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
// 编写一个函数找出这两个只出现一次的数字。

void find_single_dog(int arr[], int sz)
{
    int single1 = 0;
    int single2 = 0;
    // 1. 所有数字异或
    int ret = 0;
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        ret ^= arr[i];
    }
    // 2.计算ret中二进制中第几位是1
    int pos = 0;
    for (i = 0; i < 32; i++)
    {
        if (((ret >> i) & 1) == 1)
        {
            pos = i;
            break;
        }
    }

    // 分组
    // 把第i位为0的放在一个组中(异或在一起)
    for (i = 0; i < sz; i++)
    {
        if (((arr[i] >> i) & 1) == 0)
        {
            single1 ^= arr[i];
        }
    }

    single2 = ret ^ single1;
    printf("%d %d\n", single1, single2);
}

// 异或
int main()
{
    int arr[] = {1, 2, 3, 4, 5, };
    int sz = sizeof (arr) / sizeof(arr[0]);

    find_single_dog(arr, sz);

}
