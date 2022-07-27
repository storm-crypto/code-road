#include <accctrl.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>


// 练习：变种水仙花
//int main()
//{
//    int i = 0;
//    for (i = 10000; i <= 99999; i++)
//    {
//        int j = 0;
//        int sum = 0;
//        for (j = 0; j < 4; j++)
//        {
//            int m = i % (int)pow(10, j);
//            int n = i / (int)pow(10, j);
//            sum += m*n;
//        }
//        if (sum == i)
//        {
//            printf("%d ", i);
//        }
//    }
//}

// 练习：字符串左旋
//void left_move(char arr[], int k)
//{
//    int len = strlen(arr);
//    int j = 0;
//    for (j = 0; j < k % len; j++)
//    {
//        char tmp = arr[0];
//        int i = 0;
//        for (i = 0; i < len - 1; i++)
//        {
//            arr[i] = arr[i + 1]; // 后面所有的元素往前挪
//        }
//        arr[len - 1] = tmp;
//    }
//
//}

//void reverse(char* left, char* right)
//{
//    while (left < right)
//    {
//        char tmp = *left;
//        *left = *right;
//        *right = tmp;
//        left++;
//        right--;
//    }
//}
//
//// 三次逆序
//void left_move(char arr[], int k)
//{
//    int len = strlen(arr);
//
//    reverse(arr, arr + k - 1);
//    reverse(arr + k, arr + len - 1);
//    reverse(arr, arr + len - 1);
//
//}
//int main()
//{
//    // 左旋转字符的代码
//    char arr[20] = "abcdef";
//    int k = 0;
//    scanf("%d", &k);
//
//    left_move(arr, k);
//
//    printf("%s\n", arr);
//    return 0;
//}

// 在杨氏矩阵种找某个数字是否存在
// 方法：跟右上角的元素进行比较
// 如果比右上角的元素大，就去掉一行
// 如果比右上角的元素小，就去掉一列
//void find_k(int arr[3][3], int k, int r, int c)
//{
//    int x = 0;
//    int y = c - 1;
//    int flag = 0;
//    while (x < r && y >= 0)
//    {
//        if (arr[x][y] < k)
//        {
//            x++;
//        }
//        else if (arr[x][y] > k)
//        {
//            y--;
//        }
//        else
//        {
//            printf("找到了，下标是:%d %d\n", x, y);
//            flag = 1;
//            break;
//        }
//    }
//    if (flag == 0)
//        printf("找不到\n");
//
//}


//int main()
//{
//    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int k = 7;
//    find_k(arr, k, 3, 3);
//    return 0;
//}

//char* my_strcat(char* dest, const char* src)
//{
//    assert(dest && src);
//    char* ret = dest;
//    // 1. 找dest中的'\0'
//    while (*dest)
//    {
//        dest++;
//    }
//
//    // 2. 拷贝
//    while (*dest ++ = *src++)
//    {
//        ;
//    }
//
//    return ret;
//}
//
//int main()
//{
//    char arr1[20] = "hello";
//    char arr2[] = " bit";
//    my_strcat(arr1, arr2);
//
//    printf("%s\n", arr1);
//}

// 实现strcmp

//int my_strcmp(const char* s1, const char* s2)
//{
//    assert(s1 && s2);
//    while (*s1 == * s2)
//    {
//        if (*s1 == '\0')
//        {
//            return 0;
//        }
//        s1++;
//        s2++;
//    }
//    if (*s1 > *s2)
//        return 1;
//    else
//        return -1;
//}
//
//int main()
//{
//    char a1[] = "abc";
//    char a2[] = "abc";
//    int ret = my_strcmp(a1, a2);
//    printf("%d\n", ret);
//
//    return 0;
//}

// 实现strstr函数
//char* my_strstr(const char* str1, const char* str2)
//{
//    assert(str1 && str2);
//
//    const char* s1 = str1;
//    const char* s2 = str2;
//
//    char* cur = str1;
//    while (*cur)
//    {
//        s1 = cur;
//        s2 = str2;
//        while ((*s1 == *s2) && *s1 && *s2)
//        {
//            s1++;
//            s2++;
//        }
//        if (*s2 == '\0')
//        {
//            return (char*)cur;
//        }
//        cur++;
//    }
//    return NULL;
//}
//
//int main()
//{
//    char a1[] = "abcdeqabcdef";
//    char a2[] = "cdef";
//    char* ret = my_strstr(a1, a2);
//    if (NULL == ret)
//    {
//        printf("找不到字串\n");
//    }
//    else
//    {
//        printf("%s\n", ret);
//    }
//}

