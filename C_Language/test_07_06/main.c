#include <accctrl.h>
#include <stdio.h>

// �ַ����������⺯��strcpy
//int main() {
//    char arr1[] = "abcdef";
//    char arr2[20] = "xxxxxxxxxxx";
//    strcpy(arr2, arr1);
//    printf("%s\n", arr1);
//    return 0;
//}

// ��ǰ��ļ����ַ����ó�x����memset
//int main()
//{
//    char arr[] = "hello bit";
//    memset(arr, 'X', 5);
//
//    printf("%s\n", arr);
//
//    return 0;
//}

// дһ�����������ҳ��������������ֵ

//int get_max(int x, int y)
//{
//    return x > y ? x : y;
//}
//
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d%d", &a, &b);
//
//    int m = get_max(a, b);
//    printf("%d", m);
//    return 0;
//}

// дһ���������Խ����������ͱ���������

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 0;
    int b = 0;
    scanf("%d%d", &a, &b);

    printf("����ǰ��a = %d b = %d\n", a, b);
    swap(&a, &b);
    printf("������a = %d b = %d", a, b);
    return 0;
}