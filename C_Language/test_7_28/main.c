#include <assert.h>
#include <stdio.h>
#include <string.h>

// дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ���

// �ж�str1�ǲ�����str2��ת�õ���
int is_left_move(const char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    assert(str1 && str2);
    // 1. ��str2����׷��һ��str2
    strncat(str2, str2, strlen(str2));
    // 2. �ж�str1�ǲ���׷�Ӻ���ִ�
    char* ret = strstr(str2, str1);
    if (ret == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    char arr1[20] = "abcedf";
    char arr2[20] = "efabcd";
    // �ж�arr2�Ƿ���arr1��ת����
    int ret = is_left_move(arr2, arr1);
    if (ret == 1)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
