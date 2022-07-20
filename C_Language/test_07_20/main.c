#include <assert.h>
#include <stdio.h>

// 各种码的练习

// 打印杨辉三角

//void yangHuiTriangle(int n)
//{
//    int data[30][30] = {1};
//
//    int i = 0;
//    for (i = 1; i < n; i++)
//    {
//        data[i][0] = 1;
//        int j = 0;
//        for (j = 1; j <= i; j++)
//        {
//            data[i][j] = data[i - 1][j] + data[i - 1][j - 1];
//        }
//    }
//
//    // 打印
//    for (i = 0; i < n; i++)
//    {
//        int j = 0;
//        for (j = 0; j <= i; j++)
//        {
//            printf("%d ", data[i][j]);
//        }
//        printf("\n");
//    }
//}
//int main()
//{
//    yangHuiTriangle(8);
//    return 0;
//}

// 猜凶手
//int main()
//{
//    int killer = 0;
//
//    for (killer = 'a'; killer <= 'd'; killer++)
//    {
//        if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//        {
//            printf("凶手是:%c", killer);
//        }
//    }
//    return 0;
//}

// 猜名次




// 结构体的练习题

// 喝汽水问题

//int main()
//{
//    int total = 0;
//    int money = 0;
//    int empty = 0;
//    // 输入总金额
//    scanf("%d", &money);
//    total = money;
//    empty = money;
//    while (empty > 1)
//    {
//        total += empty / 2;
//        empty = empty / 2 + empty % 2;
//    }
//
//    printf("最终获得的汽水数：%d", total);
//
//    return 0;
//}

// strlen的实现
//int my_strlen(const char* p)
//{
//    assert(p);
//
//    int ret = 0;
//    while (*p != '\0')
//    {
//        ret++;
//        p++;
//    }
//
//    return ret;
//}
//
//int main()
//{
//    char arr[] = "hello world";
//    int ret = my_strlen(arr);
//    printf("%d ", ret);
//    return 0;
//}

// strcpy实现
//
//void my_strcpy(char* dest, const char* src)
//{
//    assert(dest && src);
//
//    while (*dest++ = *src++);
//}
//
//int main()
//{
//    char src[] = "hello hi";
//    char dest[] = {0};
//    my_strcpy(dest, src);
//    printf("%s", dest);
//
//    return 0;
//}

// 调整奇数偶数顺序

void swap_arr(int arr[], int sz)
{
    int left = 0;
    int right = sz - 1;

    while (left < right)
    {
        while ((left < right) && (arr[left] %2 == 1))
        {
            left++;
        }

        while ((left < right) && (arr[right] % 2 == 0))
        {
            right --;
        }
        if (left < right)
        {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    swap_arr(arr, 10);
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}