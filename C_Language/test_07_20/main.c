#include <stdio.h>

// ���������ϰ

// ��ӡ�������

//void yangHuiTriangle(int n)
//{
//    int data[30][30] = {1};
//
//    int i = 0;
//    for (i = 1; i < n; i++)
//    {
//        data[i][0] = 1;
//        int j = 0;
//        for (j = 1; j <= i; j++)
//        {
//            data[i][j] = data[i - 1][j] + data[i - 1][j - 1];
//        }
//    }
//
//    // ��ӡ
//    for (i = 0; i < n; i++)
//    {
//        int j = 0;
//        for (j = 0; j <= i; j++)
//        {
//            printf("%d ", data[i][j]);
//        }
//        printf("\n");
//    }
//}
//int main()
//{
//    yangHuiTriangle(8);
//    return 0;
//}

// ������
int main()
{
    int killer = 0;

    for (killer = 'a'; killer <= 'd'; killer++)
    {
        if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
        {
            printf("������:%c", killer);
        }
    }
    return 0;
}
