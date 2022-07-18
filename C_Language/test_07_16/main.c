#include <stdio.h>

//int main()
//{
//    int n = 9;
//    float* pFloat = (float *)&n;
//    printf("n的值为：%d\n", n);
//    printf("*pFloat的值为:%f\n", *pFloat);
//
//    *pFloat = 9.0;
//    printf("n的值为：%d\n", n);
//    printf("*pFloat的值为：%f\n", *pFloat);
//
//    return 0;
//}

// 字符指针的常见使用方法
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
