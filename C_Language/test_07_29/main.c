#include <stdio.h>


// �򿪺͹ر��ļ�
//int main()
//{
//    // ���ļ�
//    FILE* pf = fopen("test.txt", "w");
//    if (pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//    // д�ļ� - �������
//    char i = 'a';
//    for (i = 'a'; i <= 'z'; i++)
//    {
//        fputc(i, pf);
//    }
//
//    // �ر��ļ�
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

// ���ļ�
//int main()
//{
//    // ���ļ�
//    FILE* pf = fopen("test.txt", "r");
//    if (pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//    // ���ļ� - �������
//    int ch = 0;
//    while ((ch = getc(pf)) != EOF)
//    {
//        printf("%c ", ch);
//    }
//
//    // �ر��ļ�
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

//int main()
//{
//    // ���ļ�
//    FILE* pf = fopen("test.txt", "w");
//    if (pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//
//    // д�ļ�  дһ��
//    fputs("skajflsajdfl", pf);
//    fputs("xxxxxxxxxxxx", pf);
//
//    // �ر��ļ�
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

// fgets����
//int main()
//{
//    char arr[256] = {0};
//    // ���ļ�
//    FILE* pf = fopen("test.txt", "r");
//    if (pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//
//    // д�ļ�
//    while (fgets(arr, 256, pf) != NULL)
//    {
//        printf("%s", arr);
//    }
//    // �ر��ļ�
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

// fprintf����

// �ṹ�����͵�����

struct S
{
    char name[20];
    int age;
    double d;
};

int main()
{
    struct S s = {"����", 20, 95.5};
    // ���ļ�
    FILE* pf = fopen("test2.txt", "w");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }

    // д�ļ�
    fprintf(pf, "%s %d %lf", s.name, s.age, s.d);

    // �ر��ļ�
    fclose(pf);
    pf = NULL;

    return 0;
}