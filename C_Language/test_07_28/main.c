#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ���

// �ж�str1�ǲ�����str2��ת�õ���
//int is_left_move(const char* str1, char* str2)
//{
//    int len1 = strlen(str1);
//    int len2 = strlen(str2);
//
//    assert(str1 && str2);
//    // 1. ��str2����׷��һ��str2
//    strncat(str2, str2, strlen(str2));
//    // 2. �ж�str1�ǲ���׷�Ӻ���ִ�
//    char* ret = strstr(str2, str1);
//    if (ret == NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        return 1;
//    }
//}
//
//int main()
//{
//    char arr1[20] = "abcedf";
//    char arr2[20] = "efabcd";
//    // �ж�arr2�Ƿ���arr1��ת����
//    int ret = is_left_move(arr2, arr1);
//    if (ret == 1)
//        printf("yes\n");
//    else
//        printf("no\n");
//    return 0;
//}

//int main()
//{
//    int* p = (int*)malloc(1000);
//    int i = 0;
//
//    return 0;
//}

// ��ϰ���ҵ���
// һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
// ��дһ�������ҳ�������ֻ����һ�ε����֡�

void find_single_dog(int arr[], int sz)
{
    int single1 = 0;
    int single2 = 0;
    // 1. �����������
    int ret = 0;
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        ret ^= arr[i];
    }
    // 2.����ret�ж������еڼ�λ��1
    int pos = 0;
    for (i = 0; i < 32; i++)
    {
        if (((ret >> i) & 1) == 1)
        {
            pos = i;
            break;
        }
    }

    // ����
    // �ѵ�iλΪ0�ķ���һ������(�����һ��)
    for (i = 0; i < sz; i++)
    {
        if (((arr[i] >> i) & 1) == 0)
        {
            single1 ^= arr[i];
        }
    }

    single2 = ret ^ single1;
    printf("%d %d\n", single1, single2);
}

// ���
int main()
{
    int arr[] = {1, 2, 3, 4, 5, };
    int sz = sizeof (arr) / sizeof(arr[0]);

    find_single_dog(arr, sz);

}
