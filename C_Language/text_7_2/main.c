#include <stdio.h>

// �������һ������
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

// ��ϰ���ܳɼ���ƽ���ּ���
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

// ����һ���༶5��ѧ����5�Ƴɼ�������5��ѧ���ĸ��Ƴɼ����ܷ�
//int main()
//{
//    float score[5] = {0.0};
//    int i = 0;
//    for (i = 0; i < 5; i++)
//    {
//        int j = 0;
//        float sum = 0.0;
//        for (j = 0; j < 5; j++) // ����ÿ���˵ĸ��Ƴɼ�
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

// ��ϰ������5���˵���ߣ����ƽ�����
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

// ��ϰ��������������ִ�ӡ�����ǵĸ���
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) == 1)
//    {
//        int i = 0;
//        for (i = 0; i < n; i++)
//        {
//            printf("*");
//        }
//        printf("\n");
//    }
//    return 0;
//}

// �����Լ��
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d%d", &a, &b);
//    int m = (a < b) ? a : b;
//    while (1)
//    {
//        if (a % m == 0 && b % m == 0)
//        {
//            break;
//        }
//        m--;
//    }
//    printf("%d", m);
//}

// ��ϰ������С������
// �������Լ����m��������������a��b�����Լ����a * b / m
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d%d", &a, &b);
    int a1 = a;
    int b1 = b;
    while (c = a % b)
    {
        a = b;
        b = c;
    }
    printf("��С��������%d", a1 * b1 / b);
    return 0;
}