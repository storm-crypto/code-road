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
int main()
{
    // ���ļ�
    FILE* pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    // ���ļ� - �������
    int ch = 0;
    while ((ch = getc(pf)) != EOF)
    {
        printf("%c ", ch);
    }

    // �ر��ļ�
    fclose(pf);
    pf = NULL;

    return 0;
}