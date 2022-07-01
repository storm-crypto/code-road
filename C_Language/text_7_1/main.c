#include <stdio.h>

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

int main()
{
    int n = 0;
    printf("请输入一个数字:");
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        printf("不是奇数");
    }
    else
    {
        printf("是奇数");
    }
    return 0;
}