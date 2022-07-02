#include <stdio.h>

// 反向输出一个数字
//int main() {
//    int num = 0;
//    scanf("%d", &num);
//    while (num)
//    {
//        printf("%d", num % 10);
//        num /= 10;
//    }
//    return 0;
//}

// 练习：总成绩和平均分计算
//int main()
//{
//    int i = 0;
//    float score = 0.0;
//    float sum = 0.0;
//    for (i = 0; i < 3; i++)
//    {
//        scanf("%f", &score);
//        sum += score;
//    }
//    printf("%.2f %.2f", sum, sum / 3);
//}

// 输入一个班级5个学生的5科成绩，输入5个学生的各科成绩和总分
//int main()
//{
//    float score[5] = {0.0};
//    int i = 0;
//    for (i = 0; i < 5; i++)
//    {
//        int j = 0;
//        float sum = 0.0;
//        for (j = 0; j < 5; j++) // 输入每个人的各科成绩
//        {
//            scanf("%f", &score[j]);
//            sum += score[j];
//        }
//        for (j = 0; j < 5; j++)
//        {
//            printf("%.1f ", score[j]);
//        }
//        printf("%.1f\n", sum);
//    }
//}

// 练习：输入5个人的身高，输出平均身高
//int main()
//{
//    float high = 0.0;
//    int i = 0;
//    float sum = 0.0;
//    for (i = 0; i < 5; i++)
//    {
//        scanf("%f", &high);
//        sum += high;
//    }
//    printf("%.2f\n", sum / 5);
//
//    return 0;
//}

// 练习：根据输入的数字打印出星星的个数
int main()
{
    int n = 0;
    while (scanf("%d", &n) == 1)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}