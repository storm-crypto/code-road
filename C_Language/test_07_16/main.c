#include <stdio.h>

//int main()
//{
//    int n = 9;
//    float* pFloat = (float *)&n;
//    printf("n��ֵΪ��%d\n", n);
//    printf("*pFloat��ֵΪ:%f\n", *pFloat);
//
//    *pFloat = 9.0;
//    printf("n��ֵΪ��%d\n", n);
//    printf("*pFloat��ֵΪ��%f\n", *pFloat);
//
//    return 0;
//}

// �ַ�ָ��ĳ���ʹ�÷���
//int main()
//{
//    char a = 'w';
//    char* ch = &a;
//    *ch = 'a';
//
//    printf("%c\n", ch);
//}

int main()
{
    const char* p = "abcdef";
    *p = 'w';
    return 0;
}
