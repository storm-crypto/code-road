#include <stdio.h>


// 打开和关闭文件
//int main()
//{
//    // 打开文件
//    FILE* pf = fopen("test.txt", "w");
//    if (pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//    // 写文件 - 输出操作
//    char i = 'a';
//    for (i = 'a'; i <= 'z'; i++)
//    {
//        fputc(i, pf);
//    }
//
//    // 关闭文件
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

// 读文件
//int main()
//{
//    // 打开文件
//    FILE* pf = fopen("test.txt", "r");
//    if (pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//    // 读文件 - 输入操作
//    int ch = 0;
//    while ((ch = getc(pf)) != EOF)
//    {
//        printf("%c ", ch);
//    }
//
//    // 关闭文件
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

//int main()
//{
//    // 打开文件
//    FILE* pf = fopen("test.txt", "w");
//    if (pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//
//    // 写文件  写一行
//    fputs("skajflsajdfl", pf);
//    fputs("xxxxxxxxxxxx", pf);
//
//    // 关闭文件
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

// fgets函数
//int main()
//{
//    char arr[256] = {0};
//    // 打开文件
//    FILE* pf = fopen("test.txt", "r");
//    if (pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//
//    // 写文件
//    while (fgets(arr, 256, pf) != NULL)
//    {
//        printf("%s", arr);
//    }
//    // 关闭文件
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

// fprintf函数

// 结构体类型的数据

struct S
{
    char name[20];
    int age;
    double d;
};

int main()
{
    struct S s = {"张三", 20, 95.5};
    // 打开文件
    FILE* pf = fopen("test2.txt", "w");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }

    // 写文件
    fprintf(pf, "%s %d %lf", s.name, s.age, s.d);

    // 关闭文件
    fclose(pf);
    pf = NULL;

    return 0;
}