#include <stdio.h>
#include <string.h>

//int main()
//{
//    int a = 3;
//    int b = -5;
//    //int c = a & b; // ��λ��
//    //int c = a | b;   // ��λ��
//    int c = a ^ b;   // ��λ���
//    printf("%d\n", c);
//
//    return 0;
//}

// ��ϰ�����ܴ�����ʱ������ʵ���������Ľ���
//int main()
//{
//    int a = 3;
//    int b = 5;
//    printf("a = %d b = %d\n", a, b);
//
//    a = a ^ b;
//    b = a ^ b;
//    a = a ^ b;
//
//    printf("a = %d b = %d\n",a, b);
//
//    return 0;
//}

// ��ϰ����һ�������洢���ڴ��еĶ�������1�ĸ���
//int main()
//{
//    int num = 0;
//    scanf("%d", &num);
//    int i = 0;
//    int count = 0;
//    for (i = 0; i < 32; i++)
//    {
//        if ((num>>i) & 1)
//        {
//            count++;
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}

struct Stu
{
    char name[20];
    int age;
    float score;
};
// �ṹ�� ��������.
void print1(struct Stu ss)
{
    printf("%s %d %f\n", ss.name, ss.age, ss.score);
}

// �ṹ��ָ�� ��������->
void print2(struct Stu* ps)
{
    printf("%s %d %f\n", ps->name, ps->age, ps->score);
}

int main()
{
    struct Stu s = {"����", 20, 90.5f};
    // �޸Ľṹ��ĵ�һ��Ԫ�أ�Ҳ�������ֵķ���
    strcpy(s.name, "������");
    print1(s);
    print2(&s);
    return 0;
}