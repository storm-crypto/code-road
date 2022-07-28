#include <assert.h>
#include <stdio.h>
#include <string.h>

// 写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串

// 判断str1是不是由str2旋转得到的
int is_left_move(const char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    assert(str1 && str2);
    // 1. 在str2后面追加一个str2
    strncat(str2, str2, strlen(str2));
    // 2. 判断str1是不是追加后的字串
    char* ret = strstr(str2, str1);
    if (ret == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    char arr1[20] = "abcedf";
    char arr2[20] = "efabcd";
    // 判断arr2是否由arr1旋转得来
    int ret = is_left_move(arr2, arr1);
    if (ret == 1)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
