
#include <activdbg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//int main()
//{
////    int age = 0;
////    scanf("%d", &age);
//
//   /* if (age >= 18)
//        printf("成年\n");*/
//
//    /*if (age >= 18)
//        printf("成年\n");
//    else
//        printf("未成年\n");*/
//
////    if (age < 18)
////        printf("青少年\n");
////    else if (age >= 18 && age < 30)
////        printf("青年\n");
////    else if (age >= 30 && age < 50)
////        printf("中年\n");
////    else
////        printf("老寿星\n");
//
//    int a = 0;
//    int b = 2;
//    if (a == 1)
//        if (b == 2)
//            printf("hehe\n");
//    else
//        printf("haha\n");
//
//    return 0;
//}

//int test()
//{
//    int a = 0;
//
//    if (a)
//        return 1;
//
//    return 0;
//}
//
//int main()
//{
//    int ret = test();
//    printf("ret = %d\n", ret);
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    printf("请输入一个数字:");
//    scanf("%d", &n);
//    if (n % 2 == 0)
//    {
//        printf("不是奇数");
//    }
//    else
//    {
//        printf("是奇数");
//    }
//    return 0;
//}

//int main()
//{
//    for (int i = 1; i <= 100; i++)
//    {
//        if (i % 2 == 1)
//            printf("%d ", i);
//    }
//    return 0;
//}

//int main()
//{
//    int day = 0;
//    scanf("%d", &day);
//    switch (day)
//    {
//        case 1:
//            printf("Monday\n");
//            break;
//        case 2:
//            printf("Tuesday\n");
//            break;
//        case 3:
//            printf("Wednesday\n");
//            break;
//        case 4:
//            printf("Thursday\n");
//            break;
//        case 5:
//            printf("Friday\n");
//            break;
//        case 6:
//            printf("Saturday\n");
//            break;
//        case 7:
//            printf("Sunday\n");
//            break;
//        default:
//            printf("输入错误");
//            break;
//    }
//}

//int main()
//{
//    int i = 1;
//    while (i <= 10)
//    {
//        if (i == 5) continue;
//        printf("%d ", i);
//        i++;
//    }
//}

//int main(){
//    char password[20] = {0};
//    printf("请输入密码：");
//
//    scanf("%s", password);
//    int tmp = 0;
//    // 这一步筛掉那些输入密码后的回车字符(\n)和输入密码带的那些空格
//    while ((tmp = getchar()) != '\n');
//
//    printf("请确认密码（Y/N）");
//    int ch = getchar();
//    if ('Y' == ch)
//        printf("确认成功");
//    else
//        printf("确认失败");
//}

//int main(){
//    int i = 0;
//    for (i = 1; i <= 10; i++)
//    {
//        if (5 == i) continue;
//        printf("%d ", i);
//    }
//    return 0;
//}

//int main()
//{
//    int i = 0;
//    int j = 0;
//    for (; i < 10; i++)
//    {
//        for (; j < 10; j++)
//        {
//            printf("hehe\n");
//        }
//    }
//}

//int main()
//{
//    int i = 1;
//    do
//    {
//        if (i == 5) continue;
//        printf("%d ", i);
//        i++;
//    } while (i <= 10);
//    return 0;
//}

// 1. 计算n的阶乘
//int main(){
//    int n = 0;
//    printf("请输入一个数：");
//    scanf("%d", &n);
//    int i = 0;
//    int ret = 1;
//    for (i = 1; i <= n; i++)
//    {
//       ret = ret * i;
//    }
//    printf("%d", ret);
//    return 0;
//}

// 2. 计算1! + 2! + 3! + …… + 10！
//int main()
//{
//    int i = 0;
//    int res1 = 1; // 用来每个阶乘的答案
//    int res2 = 0; // 保存最终答案
//    for (i = 1; i <= 10; i++)
//    {
//        res1 = res1 * i;
//        res2 += res1;
//    }
//
//    printf("%d ", res2);
//    return 0;
//}

// 3.在一个有序数组中查找具体的数字n(二分查找)
//int main()
//{
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int k = 7;
//    int sz = sizeof(arr) / sizeof(arr[0]);  // 算出该数组右多少个元素
//    // 查找k
//    int l = 0; // 左下标
//    int r = sz - 1; // 右下标
//    while (l <= r)
//    {
//        int mid  = (l + r) / 2; // 中间值
//        if (arr[mid] < k)
//        {
//            l = mid + 1;
//        }
//        else if (arr[mid] > k)
//        {
//            r = mid - 1;
//        }
//        else
//        {
//            printf("找到了，下标是%d\n", mid);
//            break;
//        }
//    }
//    if (l > r)
//    {
//        printf("找不到了\n");
//    }
//
//    return 0;
//}
//#include <stdlib.h>
//#include <windows.h>
//#include <string.h>
//// 4. 编写代码，演示多个字符从两端移动，向中间汇聚
//int main()
//{
//    char arr1[] = "welcome to bit!!!!!";
//    char arr2[] = "###################";
//
//    int left = 0;
//    // int right = sizeof(arr1) / sizeof(arr1[0]) - 2; 因为字符串的结尾处是'\0'
//    int right = strlen(arr1) - 1;
//
//    while (left <= right)
//    {
//        arr2[left] = arr1[left];
//        arr2[right] = arr1[right];
//        printf("%s\n", arr2);
//        Sleep(1000); // 单位是毫秒
//        //system("cls");
//        left++;
//        right--;
//    }
//
//
//    return 0;
//
//}

// 5.编写代码实现，模拟用户登录情景，
// 并且只能登录3次（只允许输入三次密码，如果密码正确则提示登录成功，如果三次均输入错误，则退出程序）
//int main()
//{
//    int i = 0;
//    char password[20] = {0};
//    // 假设正确密码是123456
//    for (i = 0; i < 3; i++)
//    {
//        printf("请输入密码：");
//        scanf("%s", password);
//        if (strcmp(password, "123456") == 0)
//        {
//            printf("密码正确，登录成功\n");
//            break;
//        }
//        else
//        {
//            printf("密码错误，请重新输入\n");
//        }
//    }
//    if (3 == i)
//    {
//        printf("密码输入三次都错误\n");
//    }
//
//}

// 猜数字游戏

void menu()
{
    printf("-----------------\n");
    printf("----1. 开始游戏---\n");
    printf("----0. 退出游戏---\n");
    printf("-----------------\n");
}
// 猜数字游戏
void game()
{
    int guess = 0;
    // 1. 生成随机数
    int ret = rand() % 100 + 1;
    // 2. 猜数字

    while(1)
    {
        printf("请输入数字：");
        scanf("%d", &guess);
        if (guess < ret)
        {
            printf("猜小了\n");
        }
        else if (guess > ret)
        {
            printf("猜大了\n");
        }
        else
        {
            printf("恭喜你猜对了\n");
            break;
        }
    }
}

int main()
{
    int input = 0;
    srand((unsigned int) time(NULL));
    do
    {
        menu();
        printf("请选择：");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("输入有误，请重新输入\n");
                break;
        }
    }while(input);

    return 0;
}
