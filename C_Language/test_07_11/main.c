#include <stdio.h>
#include <string.h>

//int main()
//{
//    int a = 3;
//    int b = -5;
//    //int c = a & b; // 按位与
//    //int c = a | b;   // 按位或
//    int c = a ^ b;   // 按位异或
//    printf("%d\n", c);
//
//    return 0;
//}

// 练习：不能创建临时变量，实现两个数的交换
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

// 练习：求一个整数存储在内存中的二进制中1的个数
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
// 结构体 操作符：.
void print1(struct Stu ss)
{
    printf("%s %d %f\n", ss.name, ss.age, ss.score);
}

// 结构体指针 操作符：->
void print2(struct Stu* ps)
{
    printf("%s %d %f\n", ps->name, ps->age, ps->score);
}

int main()
{
    struct Stu s = {"张三", 20, 90.5f};
    // 修改结构体的第一个元素，也就是名字的方法
    strcpy(s.name, "张三丰");
    print1(s);
    print2(&s);
    return 0;
}