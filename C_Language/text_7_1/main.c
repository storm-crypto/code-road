#include <stdio.h>

//int main()
//{
////    int age = 0;
////    scanf("%d", &age);
//
//   /* if (age >= 18)
//        printf("����\n");*/
//
//    /*if (age >= 18)
//        printf("����\n");
//    else
//        printf("δ����\n");*/
//
////    if (age < 18)
////        printf("������\n");
////    else if (age >= 18 && age < 30)
////        printf("����\n");
////    else if (age >= 30 && age < 50)
////        printf("����\n");
////    else
////        printf("������\n");
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
//    printf("������һ������:");
//    scanf("%d", &n);
//    if (n % 2 == 0)
//    {
//        printf("��������");
//    }
//    else
//    {
//        printf("������");
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

int main()
{
    int day = 0;
    scanf("%d", &day);
    switch (day)
    {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("�������");
            break;
    }
}