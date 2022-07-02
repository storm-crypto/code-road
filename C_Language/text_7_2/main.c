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
int main()
{
    int i = 0;
    float score = 0.0;
    float sum = 0.0;
    for (i = 0; i < 3; i++)
    {
        scanf("%f", &score);
        sum += score;
    }
    printf("%.2f %.2f", sum, sum / 3);
}
