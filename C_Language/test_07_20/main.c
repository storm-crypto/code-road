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

//void swap_arr(int arr[], int sz)
//{
//    int left = 0;
//    int right = sz - 1;
//
//    while (left < right)
//    {
//        while ((left < right) && (arr[left] %2 == 1))
//        {
//            left++;
//        }
//
//        while ((left < right) && (arr[right] % 2 == 0))
//        {
//            right --;
//        }
//        if (left < right)
//        {
//            int tmp = arr[left];
//            arr[left] = arr[right];
//            arr[right] = tmp;
//        }
//    }
//}
//
//int main()
//{
//    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    swap_arr(arr, 10);
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//// 操作符的练习


// 练习：统计二进制中1的个数

// 方法1：右移+(&1) == 1
//int NumberOf1(int n)
//{
//    int i = 0;
//    int count = 0;
//    for (i = 0; i < 32; i++)
//    {
//        if (((n >> i) & 1) == 1)
//        {
//            count++;
//        }
//    }
//
//    return count;
//}

// 方法2：除2，mod2
// 为了防止-1之类的负数，所以就当作无符号数来处理就好
//int NumberOf1(int n)
//{
//    unsigned int m = n;
//    int count = 0;
//    while (m)
//    {
//        if (m % 2 == 1)
//            count ++;
//        m /= 2;
//    }
//
//    return count;
//}

// 方法3：n & (n - 1)
// 有多少个1就循环几次
// 用n作为循环的条件就行了
//int NumberOf1(int n)
//{
//    int count = 0;
//    while (n)
//    {
//        n = n & (n - 1);
//        count ++;
//    }
//
//    return count;
//}

// 练习：求两个数二进制中不同位的个数

// 方法1：
//int main()
//{
//    int m = 0;
//    int n = 0;
//    int diff = 0;
//    scanf("%d%d", &n, &m);
//    int i = 0;
//    for (i = 0; i < 32; i++)
//    {
//        if (((n >> i) & 1) != ((m >> i) & 1))
//            diff++;
//    }
//
//    printf("%d ", diff);
//    return 0;
//}

// 方法2：
//int main()
//{
//    int m = 0;
//    int n = 0;
//    int diff = 0;
//    scanf("%d%d", &n, &m);
//    int tmp = m ^ n;
//
//    while (tmp)
//    {
//        tmp = tmp & (tmp - 1);
//        diff++;
//    }
//
//    printf("%d ", diff);
//    return 0;
//}

// 练习：打印奇数位和偶数位
//int main()
//{
//    int m = 0;
//    scanf("%d", &m);
//    int i = 0;
//    // 奇数位
//    for(i = 30; i >= 0; i -= 2)
//    {
//        printf("%d ", (m >> i) & 1);
//    }
//    printf("\n");
//
//    // 偶数位
//    for (i = 31; i >= 1; i -= 2)
//    {
//        printf("%d ", (m >> i) & i);
//    }
//
//    return 0;
//}

// 上面几道题主要是用到了移位和按位与这些

//// 指针初阶练习



